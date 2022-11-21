#include <stack>
#include <string>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    string test = "test";
    stack<char> mstack;
    for (auto i = 0; i < test.length(); i++)
    {
        mstack.push(test[i]);
        // cout << mstack.top();
        // mstack.pop();
    }

    cout << "top-> ";
    while (!mstack.empty())
    {
        cout << (mstack.top()) << endl;
        mstack.pop();
    }

    return 0;
}
