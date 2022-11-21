// Code shared by Vedant Panchal, CSI-SPIT, Tech Team
// Incase of any doubts, reach me on vedantpanchal12345@gmail.com
// GitHub Profile: https://github.com/DeveloperDowny

#include <bits/stdc++.h>
#include <stack>
// #include <string>
#include <iostream>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'isBalanced' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

void printStack(stack<char> mstack)
{
    cout << "top-> ";
    while (!mstack.empty())
    {
        cout << (mstack.top()) << endl;
        mstack.pop();
    }
    cout << endl;
}

char getCorrespondingRightBracket(char theBracket)
{
    if (theBracket == '(')
        return ')';
    if (theBracket == '[')
        return ']';
    if (theBracket == '{')
        return '}';

    return '|';
}

bool isRightBracket(char theBracket)
{
    if (theBracket == ')' || theBracket == ']' || theBracket == '}')
        return true;
    return false;
}
string isBalanced(string s)
{
    stack<char> mstack;

    // A string starting with a right bracket can never be balanced (e.g. )]} )
    if (isRightBracket(s[0]))
        return "NO";
    else
        mstack.push(s[0]);

    for (int i = 1; i < s.length(); i++)
    {
        printStack(mstack);
        if (isRightBracket(s[i]))
        {
            // If the top is a right bracket and is not the left counterpart bracket of the current bracket,
            // it can never be a balanced bracket and hence return NO
            if (getCorrespondingRightBracket(mstack.top()) != s[i])
                return "NO";
            // When the top is the left counterpart bracket of the current bracket, remove the top from the stack
            else
                mstack.pop();
        }
        // If it is a left bracket, push into stack to check
        // whether the future most recent right bracket is the corresponding right bracket of the top of stack or not
        else
        {
            mstack.push(s[i]);
        }
    }

    // When the stack is not empty, it means no corresponding right brackets of the brackets left in the stack were found.
    // Hence, return NO as the brackets are not balanced (e.g. in the case of "{[(")
    printStack(mstack);
    if (!mstack.empty())
        return "NO";
    return "YES";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++)
    {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}
