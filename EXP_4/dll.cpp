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
};

class DLL
{
private:
    /* data */
public:
    Node *head;
    DLL()
    {
        head = new Node(1);
        head->prev = nullptr;
        head->left = nullptr;
    }
    ~DLL() {}

    void printDLL()
    {
        Node *temp = head;
        cout << "Printing DLL" << endl;
        while (temp != nullptr)
        {
            cout << temp->data << endl;
            temp = temp->left;
        }
        cout << endl
             << endl;
    }

    void testFunc()
    {
        Node *temp = head;
        for (int i = 2; i < 4; i++)
        {
            temp->left = new Node(i);
            temp->left->prev = temp;
            temp = temp->left;
        }
        temp->left = nullptr;
    }

    void addNodeAt(Node *newNode, int pos)
    {
        if (head == nullptr)
        {
            head = newNode;
            head->prev = nullptr;
            head->left = nullptr;
            return;
        }

        if (pos == 1)
        {
            newNode->prev = nullptr;
            newNode->left = head;
            head = newNode;
            return;
        }

        // Add at end if pos is -1
        if (pos == -1)
        {
            Node *temp = head;
            while (temp->left != nullptr)
            {
                temp = temp->left; // why does doing this doesn't change loc of head. It doesn't because you aren't using a double pointer. If temp was a double pointer, *temp would be accesing the address of the head pointer (which itself is storing an address)
                // *temp =
                // temp = (*temp).next;
                // *temp =
            }
            temp->left = newNode;
            newNode->left = nullptr;
            newNode->prev = temp;
            return;
        }

        Node *temp = head;
        while (pos-- > 1)
        {
            if (temp->left == nullptr)
            {
                temp->left = newNode;
                newNode->prev = temp;
                newNode->left = nullptr;
                break;
            }
            else
            {
                temp = temp->left;
            }
            // while (temp->next != null)
            // {
            //     /* code */
            // }
        }

        // newNode->next = temp->next->next; use this for deletion
        if (newNode->prev == temp)
        {
            return;
        }
        newNode->left = temp->left;
        if (newNode->left != nullptr)
        {
            newNode->left->prev = newNode;
        }

        temp->left = newNode;
        newNode->prev = temp;

        cout << head->data << endl;
    }

    void deleteNodeAt(int pos)
    {
        if (head == nullptr)
            return;
        if (head->left == nullptr)
        {
            Node *temp = head;
            head = nullptr;
            delete temp;
            return;
        }

        if (pos == 1)
        {
            Node *toDelete = head;
            head->left->prev = nullptr;
            head = toDelete->left;
            delete toDelete;
            return;
        }

        // Add at end if pos is -1
        if (pos == -1)
        {
            Node *temp = head;
            while (temp->left != nullptr)
            {
                temp = temp->left; // why does doing this doesn't change loc of head. It doesn't because you aren't using a double pointer. If temp was a double pointer, *temp would be accesing the address of the head pointer (which itself is storing an address)
                // *temp =
                // temp = (*temp).next;
                // *temp =
            }
            temp->prev = nullptr;
            delete temp;
            // temp->next = newNode;
            // newNode->next = nullptr;
            // newNode->prev = temp;
            return;
        }

        Node *temp = head;
        while (pos-- > 1)
        {
            if (temp->left == nullptr)
            {
                temp->prev->left = nullptr;
                // delete temp;
                temp = nullptr;

                // temp->next = newNode;
                // newNode->prev = temp;
                // newNode->next = nullptr;
                break;
            }
            else
            {
                temp = temp->left;
            }
            // while (temp->next != null)
            // {
            //     /* code */
            // }
        }

        // newNode->next = temp->next->next; use this for deletion
        if (temp == nullptr)
        {
            delete temp;
            return;
        }

        Node *toDelete = temp->left;
        temp->left = temp->left->left;
        temp->left->prev = temp;

        delete toDelete;

        cout << head->data << endl;
    }
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

    DLL mDLL = DLL();

    // To Populate the Double Linked List 'mDLL'
    mDLL.testFunc();
    cout << "Initial DLL" << endl;
    mDLL.printDLL();

    // Adding node at first position
    mDLL.addNodeAt(new Node(0), 1);
    cout << "After adding at 1st position" << endl;
    mDLL.printDLL();

    // Deleting node at first position
    mDLL.deleteNodeAt(1);
    cout << "After deleting at 1st position" << endl;
    mDLL.printDLL();

    return 0;
}