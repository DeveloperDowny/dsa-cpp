

#include <bits/stdc++.h>
using namespace std;

void printArray(int arr[], int n)
{

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << endl;
}

void hashing(int table[], int tsize, int arr[], int N, int i)
{

    int hv = arr[i] % tsize;
    cout << hv;

    if (table[hv] == -1)
        table[hv] = arr[i];
    else
    {
        cout << "Collision occurred at position " << hv << " for " << arr[i] << endl
             << endl;

        for (int j = 0; j < tsize; j++)
        {

            int t = (hv + j * j) % tsize;
            cout << t;
            if (table[t] == -1)
            {

                table[t] = arr[i];
                break;
            }
        }
    }

    cout << "Contents of Hash Table after Hashing " << arr[i] << " :" << endl
         << endl;
    printArray(table, N);
}

int main()
{

    int arr[100];

    int choice;

    cout << endl
         << "Enter size of hash table: ";
    cin >> choice;
    int N = choice;

    int L = choice;
    int hash_table[choice];

    for (int i = 0; i < L; i++)
    {
        hash_table[i] = -1;
    }

    int i = 0;
    while (true)
    {
        cout << endl
             << "Enter the next data of the heap (enter -999 to stop): ";
        cin >> choice;
        if (choice == -999)
        {
            break;
        }
        arr[i] = choice;
        hashing(hash_table, L, arr, N, i);
        i++;
    }

    return 0;
}
