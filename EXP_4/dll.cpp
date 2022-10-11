#include <iostream>

using namespace std;

class Node
{
private:
    /* data */
public:
    int data;
    Node *prev;
    Node *next;
    Node(int data)
    {
        this->data = data;
    }
};

class DLL
{
private:
    /* data */
public:
    Node *head;
    DLL()
    {
        head = nullptr;
    }
    ~DLL() {}

    void printDLL()
    {
        Node *temp = head;
        cout << "Printing DLL" << endl;
        while (temp != nullptr)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
        cout << endl
             << endl;
    }

    void testFunc()
    {
        head = new Node(10);
        Node *temp = head;
        for (int i = 2; i < 4; i++)
        {
            temp->next = new Node(i * 10);
            temp->next->prev = temp;
            temp = temp->next;
        }
        temp->next = nullptr;
    }

    void addNodeAt(Node *newNode, int pos)
    {
        if (head == nullptr)
        {
            head = newNode;
            head->prev = nullptr;
            head->next = nullptr;
            return;
        }

        if (pos == 1)
        {
            newNode->prev = nullptr;
            newNode->next = head;
            head = newNode;
            return;
        }

        if (pos == -1)
        {
            Node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = nullptr;
            newNode->prev = temp;
            return;
        }

        pos--;

        Node *temp = head;
        while (pos-- > 1)
        {
            if (temp->next == nullptr)
            {
                temp->next = newNode;
                newNode->prev = temp;
                newNode->next = nullptr;
                break;
            }
            else
            {
                temp = temp->next;
            }
        }

        if (newNode->prev == temp)
        {
            return;
        }
        newNode->next = temp->next;
        if (newNode->next != nullptr)
        {
            newNode->next->prev = newNode;
        }

        temp->next = newNode;
        newNode->prev = temp;

        // cout << head->data << endl;
    }

    void deleteNodeAt(int pos)
    {
        if (head == nullptr)
            return;
        if (head->next == nullptr)
        {
            Node *temp = head;
            head = nullptr;
            delete temp;
            return;
        }

        if (pos == 1)
        {
            Node *toDelete = head;
            head->next->prev = nullptr;
            head = toDelete->next;
            delete toDelete;
            return;
        }

        if (pos == -1)
        {
            Node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->prev->next = nullptr;
            delete temp;

            return;
        }

        Node *temp = head;
        while (pos-- > 1)
        {
            if (temp->next == nullptr)
            {
                temp->prev->next = nullptr;

                temp = nullptr;

                break;
            }
            else
            {
                temp = temp->next;
            }
        }

        if (temp == nullptr)
        {
            delete temp;
            return;
        }

        Node *toDelete = temp->next;
        temp->next = temp->next->next;
        temp->next->prev = temp;

        delete toDelete;
    }
};

void testFunc(Node *&head)
{
    Node *temp = head;
    for (int i = 2; i < 4; i++)
    {
        head->next = new Node(i * 10);
        head->next->prev = head;
        head = head->next;
    }
    head->next = nullptr;
    head = temp;
}

int main(int argc, char const *argv[])
{

    DLL mDLL = DLL();

    mDLL.testFunc();
    cout << "Initial DLL" << endl;
    mDLL.printDLL();

    mDLL.addNodeAt(new Node(0), 1);
    cout << "After adding at 1st position" << endl;
    mDLL.printDLL();

    mDLL.deleteNodeAt(1);
    cout << "After deleting at 1st position" << endl;
    mDLL.printDLL();

    mDLL.addNodeAt(new Node(434), 2);
    cout << "After adding at 2 position" << endl;
    mDLL.printDLL();

    mDLL.addNodeAt(new Node(23), -1);
    cout << "After adding at last position" << endl;
    mDLL.printDLL();

    mDLL.deleteNodeAt(-1);
    cout << "After deleting at last position" << endl;
    mDLL.printDLL();

    return 0;
}