#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    int expo;
    Node *left;

    Node(int coeff, int expo)
    {
        this->data = coeff;
        this->expo = expo;
    }
    Node()
    {
    }
};

class BST
{
public:
    Node *head;
    BST()
    {
        head = new Node(1, 1);

        head->left = nullptr;
    }
    ~BST() {}

    void printLL()
    {
        Node *temp = head;
        cout << "Printing LL" << endl;
        while (temp != nullptr)
        {
            cout << temp->data << " " << temp->expo << endl;
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
            temp->left = new Node(i, i);

            temp = temp->left;
        }
        temp->left = nullptr;
    }

    void addNodeAt(Node *newNode, int pos)
    {
        if (head == nullptr)
        {
            head = newNode;

            head->left = nullptr;
            return;
        }

        if (pos == 1)
        {

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

            return;
        }

        Node *temp = head;
        while (pos-- > 1)
        {
            if (temp->left == nullptr)
            {
                temp->left = newNode;

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

        {
            return;
        }
        newNode->left = temp->left;
        if (newNode->left != nullptr)
        {
        }
        temp->left = newNode;
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
                temp = temp->left;
            }

            delete temp;
            return;
        }

        Node *temp = head;
        while (pos-- > 1)
        {
            if (temp->left == nullptr)
            {
                temp = nullptr;
                break;
            }
            else
            {
                temp = temp->left;
            }
        }

        if (temp == nullptr)
        {
            delete temp;
            return;
        }

        Node *toDelete = temp->left;
        temp->left = temp->left->left;

        delete toDelete;
    }
};

void testFunc(Node *&head)
{
    Node *temp = head;
    for (int i = 2; i < 4; i++)
    {
        head->left = new Node(i, i);

        head = head->left;
    }
    head->left = nullptr;
    head = temp;
}

int main(int argc, char const *argv[])
{

    BST mLL = BST();

    // To Populate the Double Linked List 'mLL'
    mLL.testFunc();
    cout << "Initial LL" << endl;
    mLL.printLL();

    // Adding node at first position
    mLL.addNodeAt(new Node(0, 0), 1);
    cout << "After adding at 1st position" << endl;
    mLL.printLL();

    // Deleting node at first position
    mLL.deleteNodeAt(1);
    cout << "After deleting at 1st position" << endl;
    mLL.printLL();

    return 0;
}