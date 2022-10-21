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

        printQArr();
        if (arr[nS] == 1)
        {
            negMultiplier = -1;
            convertToNegative(nS, nE, 10, arr);
        }

        printQArr();
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

        printQArr();
    }

    static void operateA(int n1S, int n1E, int n2S, int n2E, int addOrSubtract)
    {
        int carry = 0;
        int *theArr = addOrSubtract < 0 ? minusMArr : mArr;
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
        }
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

    int ans = BinUtil::multiply(num1, num2);
    cout << num1 << " x " << num2 << " = " << ans;
    BinUtil::printQArr();
    return 0;
}
