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
    Node *prev;

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

        head = new Node(1, 1);
        head->left = new Node(2, 2);
        head->left->left = new Node(3, 3);
        head->left->left->left = nullptr;
    }
    Node *head2 = head;

    ~DoublyLinkedList();
    void addNodeAtEnd(Node *newNode);
    void printList();
    void mchangeValue();
};

void printLists(Node *head2)
{
    while (head2 != NULL)
    {
        cout << head2->data << " ";
    }
}

void DoublyLinkedList::mchangeValue()
{

    head = new Node(2, 2);
}

void DoublyLinkedList::printList()
{

    // Node *temp = head;

    // while (temp != nullptr)
    // {
    //     cout << temp->coeff << endl;
    //     temp = temp->next;
    // }

    Node *temp = head;
    // printing in reverse
    while (temp->left != nullptr)
    {
        temp = temp->left;
    }

    while (temp != nullptr)
    {
        cout << temp->data << endl; // why not prev exist?
        temp = temp->prev;
    }
}

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

        if (choice == 1)
        {
            if (temp == nullptr)
            {
                this->head = new Node(count, count);
                head->prev = nullptr;
                temp = head;
                continue;
            }

            Node *inter = new Node(count, count);
            // inter->next = nullptr;

            // inter->prev = temp;

            temp->left = (inter);
            // Node *prev = temp; not working
            // inter->prev = prev; //[]

            inter->prev = temp; // not working
            inter->left = nullptr;
            temp = temp->left;
            // printLists(head);
        }
        else
        {
            cout << "in else" << endl;
            break;
        }
    }
    temp = nullptr;
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
        newNode->prev = temp;
    }
}

int main(int argc, char const *argv[])
{

    DoublyLinkedList test = new DoublyLinkedList();

    test.printList();

    return 0;
}

// head me somehow prev not existing
// why not previous, just like next null ptr not working?