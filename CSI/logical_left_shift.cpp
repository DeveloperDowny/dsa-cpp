// Code for Logical Left Shift Question
//
// Authored by Vedant Panchal

#include <iostream>
#include <cmath>

using namespace std;

class BinUtil
{
public:
    static int F, AS, AE, R, n;
    static int *qArr, *mArr;

    static void leftShift()
    {
        updateIndices(F - 1, n);
        qArr[AS] = 0;
    }

    static void operateA(int n1S, int n1E, int n2S, int n2E)
    {
        int carry = 0;
        int *theArr = mArr;
        // cout << endl;
        // for (int i = 0; i <= n; i++)
        // {
        //     cout << theArr[i];
        // }
        // cout << endl;
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
    }

    static void updateIndices(int startIndex, int n)
    {
        F = startIndex;
        AS = F;
        AE = AS + n - 1;
        R = AE;
    }

    BinUtil(/* args */)
    {
    }

    ~BinUtil()
    {
    }

    static void printQArr(int result[][100], int index)
    {

        for (int i = F; i <= R; i++)
        {

            // result
            cout << qArr[i] << " ";
        }
        cout << endl;

        // cout << endl;
        // for (int i = 0; i < 8; i++)
        // {
        //     cout << qArr[i];
        // }
        // cout << endl;
    }

    static void mInit(int *A, int *M, int K, int newN)
    {
        n = newN;

        updateIndices(K, n);

        int sizeOfPaddedArray = K + n;
        qArr = new int[sizeOfPaddedArray];
        for (int i = 0; i < K; i++)
        {
            qArr[i] = 0;
        }

        for (int i = K; i < sizeOfPaddedArray; i++)
        {
            qArr[i] = A[i - K];
        }

        // cout << endl;
        // for (int i = 0; i < sizeOfPaddedArray; i++)
        // {
        //     cout << qArr[i];
        // }
        // cout << endl;
        mArr = M;
    }

    static void solve(int *A, int *M, int K, int n)
    {
        mInit(A, M, K, n);
        int temp = K;
        while (temp--)
        {
            /// Condition for Odd
            if (qArr[AE] == 1)
            {
                operateA(AS, AE, 0, n - 1);
                leftShift();
            }
            else
            {
                leftShift();
            }
        }
    }
};

int BinUtil::F, BinUtil::AS, BinUtil::AE, BinUtil::R, BinUtil::n;
int *BinUtil::qArr, *BinUtil::mArr;

int main(int argc, char const *argv[])
{
    int arrOfA[][100] = {
        {1},
        {1, 0},
        {1, 0, 1},
        {1, 1, 1, 0},
        {1, 0, 1, 0, 1},
        {1, 0, 1, 0, 1, 1},
        {1, 0, 1, 0, 1, 0, 1},
        {1, 0, 1, 1, 0, 1, 1, 1}};

    // int A[] = {1};
    // int A[] = {1, 0};
    // int A[] = {1, 0, 1};
    // int A[] = {1, 1, 1, 0};
    // int A[] = {1, 0, 1, 0, 1};
    // int A[] = {1, 0, 1, 0, 1, 1};
    // int A[] = {1, 0, 1, 0, 1, 0, 1};
    // int A[] = {1, 0, 1, 1, 0, 1, 1, 1};

    int arrOfM[][100] = {

        {1},
        {1, 1},
        {1, 1, 1},
        {1, 0, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 0, 1, 0, 1, 1},
        {1, 1, 1, 0, 0, 1, 1},
        {1, 1, 1, 0, 0, 1, 1, 1}

    };
    // int M[] = {1};
    // int M[] = {1, 1};
    // int M[] = {1, 1, 1};
    // int M[] = {1, 0, 1, 1};
    // int M[] = {1, 1, 1, 1, 1};
    // int M[] = {1, 0, 1, 0, 1, 1};
    // int M[] = {1, 1, 1, 0, 0, 1, 1};
    // int M[] = {1, 1, 1, 0, 0, 1, 1, 1};

    int arrOfK[] = {
        1,
        1,
        2,
        4,
        2,
        4,
        2,
        5};

    int ansArrr[100][100];
    int count = 0;

    cout << "8" << endl;
    for (int i = 0; i < sizeof(arrOfK) / sizeof(int); i++)
    {
        count++;

        const int n = count;
        // const int n = sizeof(arrOfM[i]) / sizeof(int);
        int K = arrOfK[i];
        int ans[n];

        cout << endl
             << "Input " << count << endl
             << endl
             << "1"; //<< endl;
        cout << endl;
        for (int j = 0; j < n; j++)
        {
            cout << arrOfA[i][j] << " ";
        }
        cout << endl;

        for (int j = 0; j < n; j++)
        {
            cout << arrOfM[i][j] << " ";
        }
        cout << endl;
        cout << n;
        cout << endl;
        cout << K;
        cout << endl;
        cout << endl;

        cout << "Output " << count;
        cout << endl;
        BinUtil::solve(arrOfA[i], arrOfM[i], K, n);
        BinUtil::printQArr(ansArrr, count);

        // BinUtil::solve(arrOfA[i], arrOfM[i], K, n);
        // BinUtil::printQArr(ansArrr, count);
    }

    cout << endl;
    count = 0;
    for (int i = 0; i < sizeof(arrOfK) / sizeof(int); i++)
    {
        count++;

        int n = count;
        // const int n = sizeof(arrOfM[i]) / sizeof(int);
        int K = arrOfK[i];
        int ans[n];

        // cout << endl;
        // for (int j = 0; j < n; j++)
        // {
        //     cout << arrOfA[i][j] << " ";
        // }
        // cout << endl;

        // for (int j = 0; j < n; j++)
        // {
        //     cout << arrOfM[i][j] << " ";
        // }
        // cout << endl;

        BinUtil::solve(arrOfA[i], arrOfM[i], K, n);
        BinUtil::printQArr(ansArrr, count);
    }

    return 0;
}

// List of Input and Outputs:

// 1)

// 1
// 1
// 1
// 1

// 0
// —--
// 2)
//     int A[] = {1, 0};
// int M[] = {1, 1};
// const int n = sizeof(M) / sizeof(int);
// int K = 1;

// 0 1
// —--
// 3)

//     int A[] = {1, 0, 1};
// int M[] = {1, 1, 1};
// const int n = sizeof(M) / sizeof(int);
// int K = 2;

// 0 0 1
// —--
// 4)
//     int A[] = {1, 1, 1, 0};
// // int A[] = {1, 0, 1, 0, 1};
// // int A[] = {1, 0, 1, 0, 1, 1};
// // int A[] = {1, 0, 1, 0, 1, 0, 1};
// // int A[] = {1, 0, 1, 1, 0, 1, 1, 1};
// this is the test case for the m array

// // int M[] = {1};
// // int M[] = {1, 1};
// // int M[] = {1, 1, 1};
// int M[] = {1, 0, 1, 1};
// // int M[] = {1, 1, 1, 1, 1};
// // int M[] = {1, 0, 1, 0, 1, 1};
// // int M[] = {1, 1, 1, 0, 0, 1, 1};
// // int M[] = {1, 1, 1, 0, 0, 1, 1, 1};

// const int n = sizeof(M) / sizeof(int);
// int K = 4;

// 0 0 1 1
// —--
// 5)
//     int A[] = {1, 0, 1, 0, 1};
// // int A[] = {1, 0, 1, 0, 1, 1};
// // int A[] = {1, 0, 1, 0, 1, 0, 1};
// // int A[] = {1, 0, 1, 1, 0, 1, 1, 1};

// // int M[] = {1};
// // int M[] = {1, 1};
// // int M[] = {1, 1, 1};
// // int M[] = {1, 0, 1, 1};
// int M[] = {1, 1, 1, 1, 1};
// // int M[] = {1, 0, 1, 0, 1, 1};
// // int M[] = {1, 1, 1, 0, 0, 1, 1};
// // int M[] = {1, 1, 1, 0, 0, 1, 1, 1};

// const int n = sizeof(M) / sizeof(int);
// int K = 2;

// 0 0 1 0 1
// 6)
//     int A[] = {1, 0, 1, 0, 1, 1};
// // int A[] = {1, 0, 1, 0, 1, 0, 1};
// // int A[] = {1, 0, 1, 1, 0, 1, 1, 1};

// // int M[] = {1};
// // int M[] = {1, 1};
// // int M[] = {1, 1, 1};
// // int M[] = {1, 0, 1, 1};
// // int M[] = {1, 1, 1, 1, 1};
// int M[] = {1, 0, 1, 0, 1, 1};
// // int M[] = {1, 1, 1, 0, 0, 1, 1};
// // int M[] = {1, 1, 1, 0, 0, 1, 1, 1};

// const int n = sizeof(M) / sizeof(int);
// int K = 4;

// 0 1 0 1 1 1
// —--
// 7)
//     int A[] = {1, 0, 1, 0, 1, 0, 1};
// // int A[] = {1, 0, 1, 1, 0, 1, 1, 1};

// // int M[] = {1};
// // int M[] = {1, 1};
// // int M[] = {1, 1, 1};
// // int M[] = {1, 0, 1, 1};
// // int M[] = {1, 1, 1, 1, 1};
// // int M[] = {1, 0, 1, 0, 1, 1};
// int M[] = {1, 1, 1, 0, 0, 1, 1};
// // int M[] = {1, 1, 1, 0, 0, 1, 1, 1};

// const int n = sizeof(M) / sizeof(int);
// int K = 2;

// 0 0 1 0 0 1 0
// —--
// 8)
//     int A[] = {1, 0, 1, 1, 0, 1, 1, 1};

// // int M[] = {1};
// // int M[] = {1, 1};
// // int M[] = {1, 1, 1};
// // int M[] = {1, 0, 1, 1};
// // int M[] = {1, 1, 1, 1, 1};
// // int M[] = {1, 0, 1, 0, 1, 1};
// // int M[] = {1, 1, 1, 0, 0, 1, 1};
// int M[] = {1, 1, 1, 0, 0, 1, 1, 1};

// const int n = sizeof(M) / sizeof(int);
// int K = 5;

// 0 0 1 1 1 0 1 0
