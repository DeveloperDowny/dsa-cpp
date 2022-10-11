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

        // head = new Node(1, 1);
        // head->prev = nullptr;

        // head->next = new Node(2, 2);
        // head->next->prev = head;

        // head->next->next = new Node(3, 3);
        // head->next->next->prev = head->next;

        // head->next->next->next = nullptr;
        // head->next->next->next->prev = head->next->next->next;

        // hardcoded printing works.
        // why is it getting gayab, because temp is temporary?//if yes then why did it show previously.
        // should I use double pointer there?
    }

    ~DoublyLinkedList();
    void addNodeAtEnd(Node *newNode);
    void printList();
    void mchangeValue();
};

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
    head = nullptr;
    Node *temp = new Node(1, 1);
    int t = 5;
    while (t--)
    {
        if (head == nullptr)
        {
            head = new Node(5 - t, 5 - t);
            *temp = *head;
            temp->left = nullptr;
            temp->prev = nullptr;
        }

        temp->left = new Node(5 - t, 5 - t);
        temp->prev = temp;
        // temp = *(temp->next);
        temp = (temp->left);
    }
}

// DoublyLinkedList::DoublyLinkedList() // maybe you need to use malloc calloc etc
// {
//     Node *mheadtest = (Node *)malloc(sizeof(Node));
//     this->head = nullptr;
//     int choice;
//     // Node **temp = &(this->head);
//     Node **temp = nullptr;
//     int count = 0;
//     while (true)
//     {
//         count++;
//         cout << "Do you want to add a node?" << endl
//              << "1. Yes" << endl
//              << "2. No" << endl
//              << "Enter choice: ";
//         cin >> choice;

//         if (choice == 1)
//         {
//             if (temp == nullptr)
//             {
//                 this->head = new Node(count, count);
//                 head->prev = nullptr;
//                 temp = &head;
//                 mheadtest = head; // this is changing repeatedly

//                 continue;
//             }

//             Node *inter = new Node(count, count);
//             // inter->next = nullptr;

//             // inter->prev = temp;

//             (*temp)->next = (inter);
//             // Node *prev = temp; not working
//             // inter->prev = prev; //[]

//             // Node *test = (Node *)malloc(sizeof(Node)); // hell yes boy
//             // // Node *test = new Node();
//             // test = temp;
//             // inter->prev = test; // not working

//             inter->prev = *temp; // not working

//             inter->next = nullptr;
//             *temp = (*temp)->next;
//         }
//         else
//         {
//             cout << "in else" << endl;
//             break;
//         }
//     }
//     // temp = nullptr; []

//     // cout << head->coeff << endl;
//     head = mheadtest;
// }

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
    // DoublyLinkedList test = new DoublyLinkedList(true);

    test.printList();

    return 0;
}

// head me somehow prev not existing
// why not previous, just like next null ptr not working?