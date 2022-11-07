/// Todo LL and LR rotations and print balance factor of every nodes on insertion.
// /Then print the tree in post order/preorder

#include <iostream>

using namespace std;

class Node
{
public:
    int data;

    Node *left = nullptr;
    Node *right = nullptr;

    Node(int data)
    {
        this->data = data;
    }
    Node()
    {
    }
};

class AVLTree
{
public:
    Node *head = nullptr;
    int bf = 0;
    AVLTree() {}
    void preorderTraversal(Node *node)
    {

        if (node == nullptr)
        {
            return;
        }
        else
        {
            cout << node->data << " ";
            preorderTraversal(node->left);
            preorderTraversal(node->right);
        }

        // Vlr
    }
    AVLTree(bool test)
    {

        AVLTree mAVLTree = AVLTree();
        int arr[60];
        arr[0] = 53;
        arr[1] = 42;
        arr[2] = 18;
        arr[3] = 9;
        // arr[3] = 11;
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
            // LL Rotation Done
            mAVLTree.addNode(new Node(arr[i]), mAVLTree.head);
            bf = 0;
            Node *newHead = mAVLTree.rebalanceTree(mAVLTree.head);
            mAVLTree.head = newHead;
            mAVLTree.preorderTraversal(mAVLTree.head);
            cout << endl;
            cout << endl;
        }

        mAVLTree.preorderTraversal(mAVLTree.head);
        cout << endl;
    }

    // addNode possibly changes the head, hence it should return Node*
    // 1st simply add, then rebalance the tree right

    // void addNode(Node *newNode, Node *&head)
    void addNode(Node *newNode, Node *head)
    {
        if (this->head == nullptr)
        {
            this->head = newNode;
            return;
        }

        if (head == nullptr)
        {
            head = newNode;
            head->left = nullptr;
            head->right = nullptr;
            // cout << "get_this" << endl;
            // preorderTraversal(this->head);
        }
        else if (newNode->data >= head->data)
        {
            addNode(newNode, head->right);
            // printLL();
        }
        else
        {
            addNode(newNode, head->left);
            // printLL();
        }
    }

    Node *rebalanceTree(Node *node)
    {
        // static int bf = 0;
        if (node == nullptr)
        {
            bf = 0;
            return head;
        }
        if (node->left == nullptr && node->right == nullptr)
        {
            bf = 1;
            return node;
        }

        Node *nodeL = rebalanceTree(node->left);
        int bfL = bf;
        Node *nodeR = rebalanceTree(node->right);
        int bfR = bf;

        if ((bfL - bfR) > 1)
        {
            if (nodeL->right != nullptr)
            {
                Node *temp = nodeL->right;
                temp->left = nodeL;
                temp->right = node;
                bf = bfL - bfR - 1;
                return temp;
            }

            nodeL->right = node;

            // upar ke left ko null kar
            node->left = nullptr;
            return nodeL;
        }

        else if ((bfR - bfL) > 1)
        {
            // /todo
            if (nodeL->left != nullptr)
            {
                Node *temp = nodeL->right;
                temp->left = nodeL;
                temp->right = node;
                bf = bfL - bfR - 1;
                return temp;
            }

            nodeL->right = node;
        }

        if ((bfL - bfR) == 1 || (bfR - bfL) == 1)
        {
            bf = (bfL - bfR) == 1 ? bfL - bfR + 1 : bfL - bfR - 1;
            return node;
        }

        return node;
    }
};

int main(int argc, char const *argv[])
{
    AVLTree test = AVLTree(true);
    // test.preorderTraversal(test.head);
    return 0;
}
