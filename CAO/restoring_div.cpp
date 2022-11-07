#include <iostream>
#include <cmath>

using namespace std;

class BinUtil
{
public:
    static int F, AS, AE, QS, QE, Qminu1, R, n;
    static int *qArr, *mArr, *minusMArr;

    static int convertToDecimal(int nS, int nE, int *&arr)
    {
        int negMultiplier = 1;

        // printQArr();
        if (arr[nS] == 1)
        {
            negMultiplier = -1;
            convertToNegative(nS, nE, 10, arr);
        }

        // printQArr();
        int multiplier = 1;
        int decimal = 0;
        for (int i = nE; i >= nS; multiplier *= 2, i--)
        {
            if (arr[i] == 0)
                continue;
            decimal += arr[i] * multiplier;
        }

        return decimal * negMultiplier;
    }

    static void arithmeticRightShift()
    {
        qArr[F - 1] = qArr[F];

        calcAll(F - 1, n);

        cout << endl;
        cout << "Doing Right Shift" << endl
             << "Printing A, Q and Q minus 1" << endl;
        printQArr();
    }

    static void leftShift()
    {
        updateIndices(F + 1, n);
        qArr[QE] = 9;

        cout << endl;
        cout << "Doing Left Shift" << endl;
        //      << "Printing A, Q and Q minus 1" << endl;
        // printQArr();
    }

    static void operateA(int n1S, int n1E, int n2S, int n2E, int addOrSubtract)
    {
        int carry = 0;
        int *theArr = addOrSubtract < 0 ? minusMArr : mArr;
        cout << endl;
        for (int i = 0; i <= n; i++)
        {
            cout << theArr[i];
        }
        cout << endl;
        for (int i = n1E, j = n - 1; i >= n1S; i--, j--)
        {
            switch (qArr[i] + theArr[j] + carry)
            {
            case 0:
                continue;
                break;
            case 1:
                qArr[i] = 1;
                carry = 0;
                break;

            case 2:
                qArr[i] = 0;
                carry = 1;
                break;
            case 3:
                qArr[i] = 1;
                carry = 1;
                break;

            default:
                break;
            }
        }

        cout << endl
             << "Doing " << (addOrSubtract == -1 ? "A = A - M" : "A = A + M") << endl
             << "Printing A, Q and Q minus 1" << endl;
        printQArr();
    }

    static int switchBit(int n)
    {
        return (n == 0) ? 1 : 0;
    }

    static void convertToNegative(int nS, int nE, int num, int *&arr)
    {
        int carry = 0;
        if (switchBit(arr[nE]) == 0)
        {
            arr[nE] = 1;
        }
        else
        {
            arr[nE] = 0;
            carry = 1;
        }

        nE--;
        while (nE >= nS)
        {
            switch (carry + switchBit(arr[nE]))
            {
            case 0:
                arr[nE] = 0;
                break;
            case 1:
                arr[nE] = 1;
                carry = 0;
                break;

            case 2:
                arr[nE] = 0;
                carry = 1;
                break;
            case 3:
                arr[nE] = 1;
                carry = 1;
                break;

            default:
                break;
            }
            nE--;
        }
    }

    static void convertToBin(int nS, int nE, int num, int *&arr)
    {
        int i = nE;
        int temp = abs(num);
        while (temp > 0)
        {
            arr[i] = temp % 2;
            temp /= 2;
            i--;
        }

        if (num < 0)
        {
            convertToNegative(nS, nE, num, arr);

            while (i >= nS)
            {
                arr[i] = 1;
                i--;
            }
        }
        else
        {
            while (i >= nS)
            {
                arr[i] = 0;
                i--;
            }
        }

        for (int i = nS; i <= nE; i++)
        {
        }
    }

    static void calcAll(int startIndex, int n)
    {
        F = startIndex;
        AS = F;
        AE = F + n - 1;
        QS = AE + 1;
        QE = AE + n;
        Qminu1 = QE + 1;
        R = Qminu1;
    }

    /// @brief for left shift
    /// @param startIndex
    /// @param n
    static void updateIndices(int startIndex, int n)
    {
        F = startIndex;
        AS = F;
        AE = AS + n;
        QS = AE + 1;
        QE = QS + n - 1;
        R = QE;
    }

    BinUtil(/* args */)
    {
    }

    ~BinUtil()
    {
    }

    static void printQArr()
    {

        for (int i = F; i <= R; i++)
        {
            cout << qArr[i] << " ";
        }
        cout << endl;
    }

    static void mInit(int n1, int n2)
    {

        n = max(log2(abs(n1)) + 1, log2(abs(n2)) + 1) + 1;
        calcAll(n, n);
        qArr = new int[3 * n + 1];
        for (int i = 0; i < 3 * n + 1; i++)
        {
            qArr[i] = 0;
        }
        mArr = new int[n];
        minusMArr = new int[n];

        convertToBin(0, n - 1, n1, mArr);
        convertToBin(0, n - 1, n1 * -1, minusMArr);
        convertToBin(0, n, 0, qArr);
        convertToBin(QS, QE, n2, qArr);

        cout << endl
             << "Operation: " << n1 << " x " << n2 << endl;
        cout << endl
             << "Initialization" << endl
             << "Printing A, Q and Q minus 1" << endl;
        printQArr();
    }

    /// @brief initialization step of restoring divison
    /// @param dividend is dividend
    /// @param divisor is dividor
    static void mInit(int dividend, int divisor)
    {

        // n = max(log2(abs(n1)) + 1, log2(abs(n2)) + 1);
        n = log2(abs(dividend)) + 1;
        updateIndices(0, n);

        qArr = new int[n + 1 + n + n];
        for (int i = 0; i < 3 * n + 1; i++)
        {
            qArr[i] = 0;
        }

        mArr = new int[n + 1];
        minusMArr = new int[n + 1];

        convertToBin(0, n, divisor, mArr);
        convertToBin(0, n, divisor * -1, minusMArr);
        // convertToBin(0, n, 0, qArr);
        // convertToBin(AS, AE, 0, qArr);
        printQArr();
        convertToBin(QS, QE, dividend, qArr);
        printQArr();

        cout << endl
             << "Operation: " << dividend << " / " << divisor << endl;
        cout << endl
             << "Initialization" << endl
             << "Printing A, Q and Q minus 1" << endl
             << AS << QS << R;
        printQArr();
    }

    static int multiply(int n1, int n2)
    {
        mInit(n1, n2);
        int temp = n;
        while (temp--)
        {
            if (qArr[QE] == 1 &&
                qArr[Qminu1] == 0)
            {
                operateA(AS, AE, 0, n, -1);
            }
            else if (qArr[QE] == 0 &&
                     qArr[Qminu1] == 1)
            {
                operateA(AS, AE, 0, n, 1);
            }
            arithmeticRightShift();
        }
        return convertToDecimal(F, QE, qArr);
    }

    /// @brief code for restoring div
    /// @return arr of ints. index 0 will have quotient, index 1 will have remainder
    static void solve(int dividend, int divisor, int *ansList)
    {
        mInit(dividend, divisor);
        int temp = n;
        while (temp--)
        {
            leftShift();
            operateA(AS, AE, 0, n, -1);
            printQArr();
            if (qArr[AS] == 1)
            {
                qArr[QE] = 0;
                printQArr();
                operateA(AS, AE, 0, n, 1);
                printQArr();
            }
            else
            {
                qArr[QE] = 1;
                printQArr();
            }
        }
        ansList[0] = convertToDecimal(QS, QE, qArr);
        ansList[1] = convertToDecimal(AS, AE, qArr);
        //     convertToDecimal(AS, AE, qArr)};
        // ansList = {1, 2};
        // int ansList[] = {
        //     convertToDecimal(QS, QE, qArr),
        //     convertToDecimal(AS, AE, qArr)};
        // return ansList;
    }
};

int BinUtil::F, BinUtil::AS, BinUtil::AE, BinUtil::QS, BinUtil::QE, BinUtil::Qminu1, BinUtil::R, BinUtil::n;
int *BinUtil::qArr, *BinUtil::mArr, *BinUtil::minusMArr;

int main(int argc, char const *argv[])
{
    int num1 = 11, num2 = 3;

    int ansList[2];
    BinUtil::solve(num1, num2, ansList);
    int quotient = ansList[0];
    int remainder = ansList[1];
    // BinUtil::printQArr();
    cout << endl
         << "Result: " << num1 << " / " << num2 << " = " << quotient << " (with " << remainder << " as remainder)";

    return 0;
}
