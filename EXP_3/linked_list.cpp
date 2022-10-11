#include <iostream>

using namespace std;

class Node
{
private:
    /* data */
public:
    int data;
    int expo;
    Node *left;

    Node(int coeff, int expo);
    Node(){};
    ~Node();
};

Node::Node(int coeff, int expo)
{
    this->data = coeff;
    this->expo = expo;
}

Node::~Node()
{
}

class DoublyLinkedList
{
private:
    /* data */
public:
    Node *head;
    DoublyLinkedList();
    DoublyLinkedList(bool dummy)
    {
        this->head = nullptr;
    }
    ~DoublyLinkedList();
    void addNodeAtEnd(Node *newNode);
};

DoublyLinkedList::DoublyLinkedList()
{
    this->head = nullptr;
    int choice;
    Node *temp = this->head;
    int count = 0;
    while (true)
    {
        count++;
        cout << "Do you want to add a node?" << endl
             << "1. Yes" << endl
             << "2. No" << endl
             << "Enter choice: ";
        cin >> choice;
        cout << choice;
        if (choice == 1)
        {
            if (temp == nullptr)
            {
                this->head = new Node(count, count);
                temp = head;
                continue;
            }
            Node *inter = new Node(count, count);
            inter->left = nullptr;
            temp->left = (inter); // segmentation fault is occuring . here is the issue
            temp = temp->left;
        }
        else
        {
            cout << "in else";
            break;
        }

        cout << head->data << endl;
        cout << head->expo << endl;
    }

    temp = head;

    while (temp != nullptr) // error here
    {
        cout << temp->data << endl;
        temp = temp->left;
    }

    cout << head->data;
}

DoublyLinkedList::~DoublyLinkedList()
{
}

void DoublyLinkedList::addNodeAtEnd(Node *newNode)
{
    if (this->head == nullptr)
    {
        head = newNode;
    }
    else
    {
        Node *temp = head;
        while (temp->left != nullptr)
        {
            temp = temp->left;
        }
        temp->left = newNode;
    }
}

// front end ke liye marks hai (but not required)
// mini project. Choose Data Structure and show it's application to solve a real world problem.
// graph travelling salesman problem
// concept, etc. // new data structure // red black treess zig zag trees

int main(int argc, char const *argv[])
{
    DoublyLinkedList equation1 = new DoublyLinkedList();
    return 0;
}

// *& pass by reference

// why head ko append nai ho raha?