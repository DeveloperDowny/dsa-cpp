#include <iostream>

using namespace std;

class Node
{
public:
    char data;
    char expo;
    Node *left;
    Node *right;

    Node(char coeff, char expo)
    {
        this->data = coeff;
        this->expo = expo;
        this->left = nullptr;
        this->right = nullptr;
    }
    Node()
    {
    }
};

class ExpTree
{
public:
    Node *head;

    void preorderTraversal(Node *node)
    {

        if (node == nullptr)
        {
            return;
        }
        else
        {

            cout << (char)node->data << " ";
            preorderTraversal(node->left);
            preorderTraversal(node->right);
        }
    }
    // string s = "+*-534/92";
    Node *makeTree(string s, int sLength)
    {
        static int i = 0;

        if (i >= sLength)
        {
            return nullptr;
        }

        if (!(s[i] >= 48 && s[i] <= 57))
        {
            Node *N = new Node();
            N->data = s[i];
            i++;
            N->left = makeTree(s, sLength);
            N->right = makeTree(s, sLength);

            return N;
        }
        else
        {
            Node *N = new Node(s[i], s[i]);
            N->left = nullptr;
            N->right = nullptr;
            N->data = s[i];
            i += 1;
            return N;
        }

        return nullptr;
    }

    void dummyRun()
    {
        string s = "+*-534/92";

        Node *myTree = makeTree(s, s.length());

        cout
            << "Prefix Expression: " << endl;
        for (auto i = s.cbegin(); i != s.cend(); i++)
        {
            cout << *i << " ";
        }

        cout << endl
             << "Preorder traversal of the expression tree: " << endl;
        preorderTraversal(myTree);
        cout << endl
             << endl;
    }

    ExpTree()
    {
        head = nullptr;
    }

    ExpTree(bool isDummyRun)
    {
        head = nullptr;
        dummyRun();
    }

    ~ExpTree() {}
};

int main()
{
    // for dummy run
    auto mExpTree = ExpTree(true);
    return 0;
}
