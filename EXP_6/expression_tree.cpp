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

    // char makeExpTree(string mStr, int index)
    // {
    //     return 't';
    // }
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
            // char temp = (char)node->data;
        }

        // Vlr
    }

    Node *f1(string mString, int index_of_next, char mChar)
    {

        if (mString[index_of_next] == 0)
        {
            return nullptr;
        }

        if (!(mString[index_of_next] >= 48 && mString[index_of_next] <= 57))
        {

            Node *leftChild = new Node(mChar, mChar);
            leftChild->left = nullptr;
            leftChild->right = nullptr;

            return f2(leftChild, mString, index_of_next);
            // return f2(f1(mString, index_of_next + 1, mString[index_of_next]), mString, index_of_next)
            // Node *temp = new Node(mChar, mChar);
            // Node *leftChild = new Node(mString[index_of_next], mString[index_of_next]);
            // leftChild->left = nullptr;
            // leftChild->right = nullptr;

            // Node *rightChild = new Node(mChar, mChar);
            // rightChild->left = nullptr;
            // rightChild->right = nullptr;

            // Node *temp2 = new Node()
        }

        else
        {
            return f1(mString, index_of_next + 1, mString[index_of_next]);
            // return ()
        }

        return nullptr;
    }

    Node *f2(Node *myNode, string mString, int i)
    {
        Node *leftChild = myNode;
        Node *rightChild = f1(mString, i + 2, mString[i + 1]);
        // return new Node(leftChild, rightChild);
        Node *temp = new Node(mString[i], mString[i]);
        temp->left = leftChild;
        temp->right = rightChild;

        return temp;
    }

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
            // i -= 3;
            // i -= 3;
            // i -= 1;
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
        // string s = "29/435-*+";
        // Node *myTree = f1(s, 1, s[0]);
        Node *myTree = makeTree(s, s.length());
        // cout << myTree->data << endl;

        cout << "Prefix Expression: " << s << endl;
        cout << "Preorder traversal of the expression tree: " << endl;
        preorderTraversal(myTree);

        // for (int i = s.length(); i != -1; i--)
        // {
        //     // cout << s[i] << ' ';
        //     // makeExpTree(s, i);
        // }

        // for (int i = 0; i < prefixStr.length(); i++)
        // {
        //     cout << prefixStr[i];
        //     char mChar = prefixStr[i];

        //     if (mChar >= 48 && mChar <= 57)
        //     {
        //     }
        // }

        // for (auto it = s.cend(); it != s.cbegin(); it--)
        // // for (auto it = s.cbegin(); it != s.cend(); ++it)
        // {
        //     cout << *it << ' ';
        // }
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
    auto mExpTree = ExpTree(true);
    return 0;
}

// class BST
// {
// public:
//     Node *head;
//     BST()
//     {
//         head = new Node(-999, -999);
//         head->left = nullptr;
//     }
//     ~BST() {}
//     // delete 18 value
//     void deleteWhere(Node *&head, Node *&prevHead, int condValue)
//     {
//         if (head == nullptr)
//         {
//             return;
//         }
//         else if (condValue == head->data)
//         {
//             Node *toRearrange = head->left;
//             Node *toDelete = head;
//             if (prevHead->left->data == condValue)
//             {
//                 prevHead->left = toDelete->right;
//             }
//             else
//             {
//                 prevHead->right = toDelete->right;
//             }
//             addElement(toRearrange, toDelete->right);
//         }
//         else
//         {
//             if (prevHead == head)
//             {
//                 deleteWhere(head->left, head, condValue);
//                 deleteWhere(head->right, head, condValue);
//             }
//         }
//     }

//     void addElement(Node *newNode, Node *&head)
//     {
//         if (head == nullptr || head->data == -999)
//         {
//             head = newNode;
//             head->left = nullptr;
//             head->right = nullptr;
//             // cout << "get_this" << endl;
//             // preorderTraversal(this->head);
//         }
//         else if (newNode->data >= head->data)
//         {
//             addElement(newNode, head->right);
//             // printLL();
//         }
//         else
//         {
//             addElement(newNode, head->left);
//             // printLL();
//         }
//     }

//     Node *findMinimum(Node *node, Node *parent)
//     {
//         if (node->left == nullptr)
//         {
//             parent->left = nullptr;
//             return node;
//         }
//         else
//         {
//             return findMinimum(node->left, node);
//         }

//         return node;
//     }

//     void deleteElementWhenFound(Node *&toDeleteNode, Node *&parent, bool isNodeLeftChild)
//     {
//         // if node is leaf delete
//         // if node has one child delete and adjust pointer
//         // if node has two child, min element of right subtree
//         if (toDeleteNode->left == nullptr && toDeleteNode->right == nullptr)
//         {
//         }
//         else if (toDeleteNode->left == nullptr)
//         {
//             if (isNodeLeftChild)
//             {
//                 parent->left = toDeleteNode->right;
//             }
//             else
//             {
//                 parent->right = toDeleteNode->right;
//             }
//         }
//         else if (toDeleteNode->right == nullptr)
//         {
//             if (isNodeLeftChild)
//             {
//                 parent->left = toDeleteNode->left;
//             }
//             else
//             {
//                 parent->right = toDeleteNode->left;
//             }
//         }
//         else
//         {
//             Node *min = findMinimum(toDeleteNode->right, parent);
//             min->right = toDeleteNode->right;
//             min->left = toDeleteNode->left;
//             if (isNodeLeftChild)
//             {
//                 parent->left = min;
//             }
//             else
//             {
//                 parent->right = min;
//             }
//         }

//         delete toDeleteNode;
//     }

//     void
//     preorderTraversalAndDelete(Node *&node, int condValue, Node *&parent, bool isNodeLeftChild)
//     {

//         static bool shouldStop = false;

//         if (node == nullptr || shouldStop)
//         {
//             return;
//         }
//         else
//         {

//             if (node->data == condValue)
//             {
//                 if (parent == nullptr)
//                 {

//                     this->head = nullptr;
//                     shouldStop = true;
//                     return;
//                 }
//                 deleteElementWhenFound(node, parent, isNodeLeftChild);
//                 shouldStop = true;
//                 return;
//             }
//             if (condValue > node->data)
//             {
//                 preorderTraversalAndDelete(node->right, condValue, node, false);
//             }
//             else
//             {
//                 preorderTraversalAndDelete(node->left, condValue, node, true);
//             }
//             cout << node->data << endl;
//         }

//         // Vlr
//     }

//     void preorderTraversal(Node *node)
//     {

//         if (node == nullptr)
//         {
//             return;
//         }
//         else
//         {
//             cout << node->data << endl;
//             preorderTraversal(node->left);
//             preorderTraversal(node->right);
//         }

//         // Vlr
//     }

//     void printLL()
//     {
//         Node *temp = head;
//         cout << "Printing LL" << endl;
//         while (temp != nullptr)
//         {
//             cout << temp->data << " " << temp->expo << endl;
//             temp = temp->left;
//         }
//         cout << endl
//              << endl;
//     }

//     void testFunc()
//     {
//         Node *temp = head;
//         for (int i = 2; i < 4; i++)
//         {
//             temp->left = new Node(i, i);

//             temp = temp->left;
//         }
//         temp->left = nullptr;
//     }

//     void addNodeAt(Node *newNode, int pos)
//     {
//         if (head == nullptr)
//         {
//             head = newNode;

//             head->left = nullptr;
//             return;
//         }

//         if (pos == 1)
//         {

//             newNode->left = head;
//             head = newNode;
//             return;
//         }

//         // Add at end if pos is -1
//         if (pos == -1)
//         {
//             Node *temp = head;
//             while (temp->left != nullptr)
//             {
//                 temp = temp->left; // why does doing this doesn't change loc of head. It doesn't because you aren't using a double pointer. If temp was a double pointer, *temp would be accesing the address of the head pointer (which itself is storing an address)
//                 // *temp =
//                 // temp = (*temp).next;
//                 // *temp =
//             }
//             temp->left = newNode;
//             newNode->left = nullptr;

//             return;
//         }

//         Node *temp = head;
//         while (pos-- > 1)
//         {
//             if (temp->left == nullptr)
//             {
//                 temp->left = newNode;

//                 newNode->left = nullptr;
//                 break;
//             }
//             else
//             {
//                 temp = temp->left;
//             }
//             // while (temp->next != null)
//             // {
//             //     /* code */
//             // }
//         }

//         // newNode->next = temp->next->next; use this for deletion

//         {
//             return;
//         }
//         newNode->left = temp->left;
//         if (newNode->left != nullptr)
//         {
//         }
//         temp->left = newNode;
//     }

//     void deleteNodeAt(int pos)
//     {
//         if (head == nullptr)
//             return;
//         if (head->left == nullptr)
//         {
//             Node *temp = head;
//             head = nullptr;
//             delete temp;
//             return;
//         }

//         if (pos == 1)
//         {
//             Node *toDelete = head;

//             head = toDelete->left;
//             delete toDelete;
//             return;
//         }

//         // Add at end if pos is -1
//         if (pos == -1)
//         {
//             Node *temp = head;
//             while (temp->left != nullptr)
//             {
//                 temp = temp->left;
//             }

//             delete temp;
//             return;
//         }

//         Node *temp = head;
//         while (pos-- > 1)
//         {
//             if (temp->left == nullptr)
//             {
//                 temp = nullptr;
//                 break;
//             }
//             else
//             {
//                 temp = temp->left;
//             }
//         }

//         if (temp == nullptr)
//         {
//             delete temp;
//             return;
//         }

//         Node *toDelete = temp->left;
//         temp->left = temp->left->left;

//         delete toDelete;
//     }
// };

// void testFunc(Node *&head)
// {
//     Node *temp = head;
//     for (int i = 2; i < 4; i++)
//     {
//         head->left = new Node(i, i);

//         head = head->left;
//     }
//     head->left = nullptr;
//     head = temp;
// }

// void menu(BST *mBST)
// {
//     int choice;
//     int data;
//     while (true)
//     {
//         cout
//             << "1. Insert" << endl
//             << "2. Delete" << endl
//             << "0. Exit"
//             << "Enter choice: " << endl;

//         cin >>
//             choice;

//         if (choice == 0)
//         {
//             cout << "";
//         }
//         else
//         {
//             cout << "Enter data";
//         };

//         if (choice == 1)
//         {
//             cin >> data;
//             mBST->addElement(new Node(data, data), mBST->head);
//             cout << "Current shee" << endl;
//             mBST->preorderTraversal(mBST->head);
//         }
//         else if (choice == 2)
//         {
//             cin >> data;
//             mBST->preorderTraversalAndDelete(mBST->head, data, mBST->head, true);
//         }
//         else
//         {
//             break;
//         }
//     }
// }

// int main(int argc, char const *argv[])
// {

//     BST mBST = BST();
//     menu(&mBST);
//     mBST.preorderTraversal(mBST.head);
//     return 0;

//     // To Populate the Double Linked List 'mLL'
//     // mBST.testFunc();
//     // cout << "Initial LL" << endl;
//     // mBST.//printLL();

//     int arr[60];
//     arr[0] = 53;
//     arr[1] = 42;
//     arr[2] = 18;
//     arr[3] = 11;
//     arr[4] = 36;
//     arr[5] = 24;
//     arr[6] = 10;
//     arr[7] = 62;
//     arr[8] = 85;
//     arr[9] = 9;
//     arr[10] = 90;
//     arr[11] = 52;

//     for (int i = 0; i < 12; i++)
//     {
//         mBST.addElement(new Node(arr[i], arr[i]), mBST.head);
//     }

//     // mBST.deleteWhere(mBST.head, mBST.head, 18);
//     cout << "Before Deleting 18: " << endl;
//     mBST.preorderTraversal(mBST.head);
//     mBST.preorderTraversalAndDelete(mBST.head, 18, mBST.head, true);
//     cout << "After Deleting 18: " << endl;
//     mBST.preorderTraversal(mBST.head);

//     // inst
//     // deletion
//     // exit

//     // // Adding node at first position
//     // mLL.addNodeAt(new Node(0, 0), 1);
//     // cout << "After adding at 1st position" << endl;
//     // mLL.//printLL();

//     // // Deleting node at first position
//     // mLL.deleteNodeAt(1);
//     // cout << "After deleting at 1st position" << endl;
//     // mLL.//printLL();

//     return 0;
// }