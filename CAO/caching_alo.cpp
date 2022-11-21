#include <iostream>

using namespace std;

class Node
{
public:
    int data;

    Node *next = nullptr;
    Node *prev = nullptr;

    Node(int data)
    {
        this->data = data;
    }
    Node()
    {
    }
};

class CircularLinkedList
{
public:
    static int maxSize;
    int currentSize = 0;
    /// @brief tail will be second last node
    Node *tail = nullptr;
    Node *head = nullptr;

    bool isFull = false;
    CircularLinkedList()
    {
    }

    int replaceTo(int data)
    {
        Node *newNode = new Node(data);
        addToFront(newNode);

        Node *toDelete = tail->next;
        // newNode->next = toDelete->next;
        int dataReplaced = toDelete->data;
        free(toDelete);
        // tail->next = newNode;

        return dataReplaced;
    }

    void checkFull()
    {
        currentSize++;
        isFull = currentSize >= maxSize;
    }

    void addToEnd(int data)
    {
        Node *newNode = new Node(data);
        tail = tail->next;
        Node *firstNode = tail->next;
        tail->next = newNode;
        newNode->next = firstNode;
        // currentSize++;
        checkFull();
    }

    void addToFront(Node *newNode)
    {

        // Node *newNode = new Node(data);
        newNode->next = tail->next->next;
        tail->next->next = newNode;

        // checkFull();
    }

    void
    checkIfInCache(int data)
    {
        if (tail == nullptr)
        {
            currentSize++;
            tail = new Node(data);
            tail->next = tail;
            cout << "Added to Cache Memory" << endl;
            return;
        }

        // pointer to the previous node
        Node *temp = tail->next;

        // Node *temp = tail->next->next;
        // while (temp != tail)
        for (int i = 0; i < currentSize; i++)
        {
            // if (temp->data == data)
            // pointer to previous node
            if (temp->next->data == data)
            {
                cout << "Cache Hit" << endl;
                Node *toAddToFront = temp->next;
                temp->next = temp->next->next;
                addToFront(toAddToFront);
                // just disconnect from linked list and add to front.
                // you need to be one place behind
                // bring to front
                return;
            }
        }
        // if (temp == tail)
        // {
        if (isFull)
        {
            cout << data << " replaced by: " << replaceTo(data) << endl;
        }
        else
        {
            cout << "Cache Miss\nAdding to Cache Memory" << endl;
            addToFront(new Node(data));
            checkFull();
        }
        // }
    }
};

int CircularLinkedList::maxSize = 3;

int main(int argc, char const *argv[])
{
    CircularLinkedList mLRU = CircularLinkedList();
    mLRU.checkIfInCache(1);
    mLRU.checkIfInCache(2);
    mLRU.checkIfInCache(3);
    mLRU.checkIfInCache(1);
    mLRU.checkIfInCache(4);
    return 0;
}
