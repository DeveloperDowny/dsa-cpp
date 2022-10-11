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

        for (int i = 0; i <= this->top; i++)
        {
            cout << stack[i];
        }
    }

    char peek()
    {
        //
        //

        return top < 0
                   ? '|'
                   : stack[top];
    }

    char pop()
    {

        if (top < 0)
        {
            return '|';
        }
        else
        {
            char toReturn = stack[top];
            top--;
            return toReturn;
        }
    }

    void push(char data)
    {
        stack[++top] = data;
    }
};

bool checkForHigherOrEqualPrecedenceFromPH(char moperator, Stack placeholder)
{

    map<char, int> priority;
    priority['-'] = 1;
    priority['+'] = priority['-'];

    priority['/'] = 2;
    priority['*'] = priority['/'];

    priority['^'] = 3;

    char topElement = placeholder.peek();
    if (topElement == '|')
    {
        return false;
    }
    if (priority[moperator] >= priority[topElement])
    {
        return true;
    }

    return false;
}

bool checkForHigherFromPH(char moperator, Stack placeholder)
{

    map<char, int> priority;
    priority['-'] = 1;
    priority['+'] = priority['-'];

    priority['/'] = 2;
    priority['*'] = priority['/'];

    priority['^'] = 3;

    char topElement = placeholder.peek();
    if (topElement == '|')
    {
        return false;
    }
    if (priority[moperator] > priority[topElement])
    {
        return true;
    }

    return false;
}

int main(int argc, char const *argv[])
{

    string t = "A+B*C-D";

    cout << endl;
    cout
        << "Infix Expression: " << t << endl;
    cout << endl;

    Stack prefix = Stack();
    Stack placeholder = Stack();

    for (int i = t.length() - 1; i >= 0; i--)
    {

        //
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
            if (placeholder.peek() != '|')
            {
                prefix.push(placeholder.pop());
            }

            while (!checkForHigherFromPH(t[i], placeholder))
            {
                if (placeholder.peek() != '|')
                {
                    prefix.push(placeholder.pop());
                }
                else
                {
                    break;
                }
            }

            placeholder.push(t[i]);
            //
        }

        //

        //

        cout << "Expresion: \t";
        prefix.printStack();
        cout << " (right to left)" << endl;

        cout << "Stack: \t\t";
        placeholder.printStack();
        cout << " (top)" << endl;

        cout << endl;
    }

    while (placeholder.peek() != '|')
    {

        //
        prefix.push(placeholder.pop());
        //
    }

    cout << "Prefix Expresion of '" << t << "':\t";
    while (prefix.peek() != '|')
    {
        cout << prefix.pop();
    }

    return 0;
}
