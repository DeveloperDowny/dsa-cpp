#include <iostream>
#include <cmath>

using namespace std;

class BinUtil
{
private:
    /* data */
public:
    static int F, AS, AE, QS, QE, Qminu1, R, n;
    static int *qArr, *mArr, *minusMArr;
    // BinUtil(/* args */);
    // ~BinUtil();
    // static int multiply(int n1, int n2);
    // static void mInit(int n1, int n2);
    // static void calcAll(int startIndex, int n);
    // static void convertToBin(int nS, int nE, int num, int *mArr);
    // static void convertToNegative(int nS, int nE, int num, int *arr);
    // static int switchBit(int n);
    // static void operateA(int n1S, int n1E, int n2S, int n2E, int addOrSubtract);
    // static void arithmeticRightShift();
    // static int convertToDecimal(int nS, int nE, int *arr);

    // };

    static int convertToDecimal(int nS, int nE, int *&arr)
    {
        cout << "before making negative";
        printQArr();
        if (arr[nS] == 1)
        {
            convertToNegative(nS, nE, 10, arr);
        }
        cout << "after making negative";
        printQArr();
        int multiplier = 1;
        int decimal = 0;
        for (int i = nE; i >= nS; multiplier *= 2, i--)
        {
            if (arr[i] == 0)
                continue;
            decimal += arr[i] * multiplier;
        }

        return decimal;
    }

    static void arithmeticRightShift()
    {
        qArr[F - 1] = qArr[F];
        // int temp = F;
        calcAll(F - 1, n);
        // qArr[temp] =
        cout << "a right shift ";
        printQArr();
    }

    static void operateA(int n1S, int n1E, int n2S, int n2E, int addOrSubtract) /// operate a issues
    {
        int carry = 0;
        int *theArr = addOrSubtract < 0 ? minusMArr : mArr;
        for (int i = n1E, j = n - 1; i >= n1S; i--, j--)
        {
            int t1 = qArr[i] + theArr[j] + carry;
            int t2 = qArr[i];
            int t3 = theArr[j];

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

        cout << "after " << addOrSubtract << endl;
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
            // carry = 1;
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

        cout << " in binary " << num << endl;
        for (int i = nS; i <= nE; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
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

        cout << endl
             << "calcall" << endl;
        cout << F << AS << AE << QS << QE << Qminu1 << R << endl;
    }

    // static void mInit(int n1, int n2)
    // {
    //     n = max(
    //             (int)log(n1, 2) + 1,
    //             (int)log(n2, 2) + 1) +
    //         1;
    //     qArr = new int[3 * n + 1];
    //     mArr = new int[n];
    //     minusMArr = new int[n];
    //     convertToBin(0, n - 1, n1, mArr);

    //     calcAll(n, n);
    // }

    // static int multiply(int n1, int n2)
    // {
    //     mInit(n1, n2);
    //     while (n--)
    //     {
    //         if (qArr[QE] == 1 &&
    //             qArr[Qminu1] == 0)
    //         {
    //             operateA(AS, AE, 0, n, -1);
    //         }
    //         else if (qArr[QE] == 0 &&
    //                  qArr[Qminu1] == 1)
    //         {
    //             operateA(AS, AE, 0, n, 1);
    //         }
    //         arithmeticRightShift();
    //     }
    //     return convertToDecimal(F, QE, qArr);
    // }

    BinUtil(/* args */)
    {
    }

    ~BinUtil()
    {
    }

    static void printQArr()
    {
        for (int i = F; i < R; i++)
        {
            cout << qArr[i] << " ";
            // << i << " ";
        }

        cout << endl;
    }

    static void mInit(int n1, int n2)
    {
        // log2()
        // n = max(
        //         (int)log(n1, 2) + 1,
        //         (int)log(n2, 2) + 1) +
        //     1;
        // double test = log10(abs(n1));
        // n = max(log10(n1) / log10(2) + 1, log2(n2) / log10(2) + 1) + 1;
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

        cout << "11"
             << " ";
        printQArr();
        convertToBin(0, n, 0, qArr);

        // cout << "22"
        //      << " ";
        // printQArr();
        // convertToBin(AS, AE, 0, qArr);

        cout << "33"
             << " ";
        printQArr();
        convertToBin(QS, QE, n2, qArr); // overflow occuring

        cout << "check this only"
             << " ";
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
};
int BinUtil::F, BinUtil::AS, BinUtil::AE, BinUtil::QS, BinUtil::QE, BinUtil::Qminu1, BinUtil::R, BinUtil::n;
int *BinUtil::qArr, *BinUtil::mArr, *BinUtil::minusMArr;

int main(int argc, char const *argv[])
{
    int num1 = -2, num2 = 3;
    // BinUtil test = BinUtil();
    int ans = BinUtil::multiply(num1, num2); // this is the way to call static functios
    cout << ans << endl;
    BinUtil::printQArr();
    return 0;
}
