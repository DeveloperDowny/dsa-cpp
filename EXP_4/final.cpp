#include <iostream>

using namespace std;

class Node
{
private:
    /* data */
public:
    int data;
    Node *prev;
    Node *left;
    Node(int data)
    {
        this->data = data;
    }
    // ~Node();
};

void testFunc(Node *&head)
{
    Node *temp = head;
    for (int i = 2; i < 4; i++)
    {
        head->left = new Node(i);
        head->left->prev = head;
        head = head->left;
    }
    head->left = nullptr;
    head = temp;
}

int main(int argc, char const *argv[])
{
    Node *head = new Node(1);
    head->prev = nullptr;
    testFunc(head);
    cout << head->data;
    return 0;
}

// class DoublyLinkedLi
// {
// private:
//     /* data */
// public:
//     DoublyLinkedLi(/* args */);
//     ~DoublyLinkedLi();
// };

// DoublyLinkedLi::DoublyLinkedLi(/* args */)
// {
// }

// DoublyLinkedLi::~DoublyLinkedLi()
// {
// }