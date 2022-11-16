// Code shared by Vedant Panchal
// Reach me incase of doubts on vedantpanchal12345@gmail.com

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    string row;

    // (Reason 1)
    // I have used an approach where no intermediate 2D matrix is needed to hold the result
    // to print the result to stdout at the end to
    // reduce space and time complexity

    // Because of the above reason, I have not used the following result[n][n]
    // char result[n][n];

    cin >> n;

    // The following getline is just to remove \n from buffer
    getline(cin, row);
    for (int j = 0; j < n; j++)
    {
        // To get the string of 0 and 1 (one row of image matrix)
        getline(cin, row);

        // I have not used the commented code because of reason mentioned in (Reason 1)
        // for (int i = 0; i < 2*n; i += 2)
        for (int i = 2 * n - 2; i >= 2; i -= 2)
        {
            cout << (row[i] == '0' ? "1 " : "0 "); // (Line A)
            // result[j][n - i / 2 - 1] = row[i] == '0' ? '1' : '0';
        }

        // This one is out of the for loop because I have to print the last character without space (want to print "0" not "0 " unlike (Line A))
        cout << (row[0] == '0' ? '1' : '0') << endl;
    }

    return 0;
}