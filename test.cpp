#include <string>
#include <iostream>
#include <map>

using namespace std;

class Stack
{
public:
    int top = -1;
    int size = 100;
    char *stack;

    Stack()
    {
        stack = new char[size];
    }

    ~Stack()
    {
        if (stack != nullptr)
        {
            delete stack;
        }
    }

    void printStack()
    {

        for (int i = this->top; i >= 0; i--)
        {
            cout << stack[i];
        }
        cout << endl;
    }

    char peek()
    {
        // cout << top << endl;
        // cout << (top < 0 ? '|' : stack[top]);

        return top < 0
                   ? '|'
                   : stack[top];
    }

    char pop()
    {
        // if (top >=0) {

        // }
        // char popped_element = stack[top--];

        return top < 0 ? '|' : stack[top--];
    }

    void push(char data)
    {
        stack[++top] = data;
    }
};

bool checkForHigherOrEqualPrecedenceFromPH(char moperator, Stack placeholder)
{
    /// @brief operators are placed in the string such that higher the index of the operator higher its priority

    // string bodmas = "-+"
    map<char, int> priority;
    priority['-'] = 1;
    priority['+'] = priority['-'];

    priority['/'] = 2;
    priority['*'] = priority['/'];

    priority['^'] = 3;

    char topElement = placeholder.peek();
    if (priority[moperator] >= priority[topElement])
    {
        return true;
    }

    return false;
}

int main(int argc, char const *argv[])
{
    string t = "A+B*C";
    // string t = "A+B";
    // Stack prefix = new Stack(); //why this wrong?
    Stack prefix = Stack();
    Stack placeholder = Stack();

    // // string prefix = "";
    // char prefix[100];
    // char n;
    // char mstack[100];
    // cha
    for (int i = t.length() - 1; i >= 0; i--)
    {

        // cout << (placeholder.peek() == '|') << endl;
        if (isalpha(t[i]))
        {
            prefix.push(t[i]);
        }
        else if (placeholder.peek() == '|')
        {
            placeholder.push(t[i]);
        }
        else if (t[i] == ')')
        {
            placeholder.push(t[i]);
        }
        else if (t[i] == '(')
        {
            while (placeholder.peek() != ')')
            {
                prefix.push(placeholder.pop());
            }
            placeholder.pop();
        }
        else if (isalpha(placeholder.peek()) || placeholder.peek() == ')' || placeholder.peek() == '(')
        {
            prefix.push(t[i]);
        }
        else if (checkForHigherOrEqualPrecedenceFromPH(t[i], placeholder))
        {
            placeholder.push(t[i]);
        }
        else
        {
            placeholder.push(t[i]); // maybe this
            // cout << placeholder.peek();
        }

        // else {
        //     // checkForHigherPrecedence(t[i]);

        //     if ((t[i] == '/' || t[i] == '*')&& (placeholder.peek() == '/' || placeholder.peek() == '*')) {
        //         placeholder.push(t[i]);
        //     }
        //     else if ((t[i] == '-' || t[i] == '+') && (placeholder.peek() == '-' || placeholder.peek() == '+'))
        //     {
        //         placeholder.push(t[i]);
        //     }
        // }

        // if (isalpha(t[i]))
        // {
        //     prefix[n++] = t[i];
        // }
        // else if (t[i] == '(')
        // {
        //     mstack
        // }

        // cout << "prefix stack" << endl;
        // prefix.printStack();

        // cout << "placeholder stack" << endl;
        // placeholder.printStack();

        cout << "prefix stack" << endl;
        prefix.printStack();

        cout << "placeholder stack" << endl;
        placeholder.printStack();
    }

    while (placeholder.peek() != '|')
    {

        // cout << "test" << placeholder.peek();
        prefix.push(placeholder.pop());
        // cout << "done" << endl;
        //     cout
        // << prefix.pop();
    }

    while (prefix.peek() != '|')
    {
        cout << prefix.pop();
    }

    return 0;
}

// rdm : infix to prefix conversion
