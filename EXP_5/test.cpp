#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    int expo;
    Node *left;
    Node *right;

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
        head = new Node(-999, -999);
        head->left = nullptr;
    }
    ~BST() {}
    // delete 18 value
    void deleteWhere(Node *&head, Node *&prevHead, int condValue)
    {
        if (head == nullptr)
        {
            return;
        }
        else if (condValue == head->data)
        {
            Node *toRearrange = head->left;
            Node *toDelete = head;
            if (prevHead->left->data == condValue)
            {
                prevHead->left = toDelete->right;
            }
            else
            {
                prevHead->right = toDelete->right;
            }
            addElement(toRearrange, toDelete->right);
        }
        else
        {
            if (prevHead == head)
            {
                deleteWhere(head->left, head, condValue);
                deleteWhere(head->right, head, condValue);
            }
        }
    }

    void addElement(Node *newNode, Node *&head)
    {
        if (head == nullptr || head->data == -999)
        {
            head = newNode;
            head->left = nullptr;
            head->right = nullptr;
            // cout << "get_this" << endl;
            // preorderTraversal(this->head);
        }
        else if (newNode->data >= head->data)
        {
            addElement(newNode, head->right);
            // printLL();
        }
        else
        {
            addElement(newNode, head->left);
            // printLL();
        }
    }

    Node *findMinimum(Node *node, Node *parent)
    {
        if (node->left == nullptr)
        {
            parent->left = nullptr;
            return node;
        }
        else
        {
            return findMinimum(node->left, node);
        }

        return node;
    }

    void deleteElementWhenFound(Node *&toDeleteNode, Node *&parent, bool isNodeLeftChild)
    {
        // if node is leaf delete
        // if node has one child delete and adjust pointer
        // if node has two child, min element of right subtree
        if (toDeleteNode->left == nullptr && toDeleteNode->right == nullptr)
        {
        }
        else if (toDeleteNode->left == nullptr)
        {
            if (isNodeLeftChild)
            {
                parent->left = toDeleteNode->right;
            }
            else
            {
                parent->right = toDeleteNode->right;
            }
        }
        else if (toDeleteNode->right == nullptr)
        {
            if (isNodeLeftChild)
            {
                parent->left = toDeleteNode->left;
            }
            else
            {
                parent->right = toDeleteNode->left;
            }
        }
        else
        {
            Node *min = findMinimum(toDeleteNode->right, parent);
            min->right = toDeleteNode->right;
            min->left = toDeleteNode->left;
            if (isNodeLeftChild)
            {
                parent->left = min;
            }
            else
            {
                parent->right = min;
            }
        }

        delete toDeleteNode;
    }

    void
    preorderTraversalAndDelete(Node *node, int condValue, Node *parent, bool isNodeLeftChild)
    {

        static bool shouldStop = false;

        if (node == nullptr || shouldStop)
        {
            return;
        }
        else
        {

            if (node->data == condValue)
            {
                if (parent == nullptr)
                {

                    this->head = nullptr;
                    shouldStop = true;
                    return;
                }
                deleteElementWhenFound(node, parent, isNodeLeftChild);
                shouldStop = true;
                return;
            }
            cout << node->data << endl;
            preorderTraversalAndDelete(node->left, condValue, node, true);
            preorderTraversalAndDelete(node->right, condValue, node, false);
        }

        // Vlr
    }

    void preorderTraversal(Node *node)
    {

        if (node == nullptr)
        {
            return;
        }
        else
        {
            cout << node->data << endl;
            preorderTraversal(node->left);
            preorderTraversal(node->right);
        }

        // Vlr
    }

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

void menu(BST *mBST)
{
    int choice;
    int data;
    while (true)
    {
        cin >> choice;
        if (choice == 1)
        {
            cin >> data;
            mBST->addElement(new Node(data, data), mBST->head);
            cout << "Current shee" << endl;
            mBST->preorderTraversal(mBST->head);
        }
        else if (choice == 2)
        {
            cin >> data;
        }
        else
        {
            break;
        }
    }
}

int main(int argc, char const *argv[])
{

    BST mBST = BST();
    menu(&mBST);
    mBST.preorderTraversal(mBST.head);
    return 0;

    // To Populate the Double Linked List 'mLL'
    // mBST.testFunc();
    // cout << "Initial LL" << endl;
    // mBST.//printLL();

    int arr[60];
    arr[0] = 53;
    arr[1] = 42;
    arr[2] = 18;
    arr[3] = 11;
    arr[4] = 36;
    arr[5] = 24;
    arr[6] = 10;
    arr[7] = 62;
    arr[8] = 85;
    arr[9] = 9;
    arr[10] = 90;
    arr[11] = 52;

    for (int i = 0; i < 12; i++)
    {
        mBST.addElement(new Node(arr[i], arr[i]), mBST.head);
    }

    // mBST.deleteWhere(mBST.head, mBST.head, 18);
    cout << "Before Deleting 18: " << endl;
    mBST.preorderTraversal(mBST.head);
    mBST.preorderTraversalAndDelete(mBST.head, 18, nullptr, true);
    cout << "After Deleting 18: " << endl;
    mBST.preorderTraversal(mBST.head);

    // inst
    // deletion
    // exit

    // // Adding node at first position
    // mLL.addNodeAt(new Node(0, 0), 1);
    // cout << "After adding at 1st position" << endl;
    // mLL.//printLL();

    // // Deleting node at first position
    // mLL.deleteNodeAt(1);
    // cout << "After deleting at 1st position" << endl;
    // mLL.//printLL();

    return 0;
}