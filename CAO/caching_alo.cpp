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

class LRU
{
public:
    static int maxSize;
    int currentSize = 0;
    /// @brief tail will be second last node
    Node *tail = nullptr;
    Node *head = nullptr;

    bool isFull = false;
    LRU()
    {
    }

    void addToLeft(Node *newNode)
    {
        newNode->next = head;
        head->prev = newNode;
        head = head->prev;
    }

    int removeFromRight()
    {
        Node *toDelete = tail;
        tail = tail->prev;
        int toReturn = toDelete->data;
        free(toDelete);
        return toReturn;
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

    void checkIfInCacheElseAdd(int data)
    {
        if (head == nullptr)
        {
            head = new Node(data);
            tail = head;
        }
        else if (head == tail)
        {

            head = new Node(data);
            head->next = tail;
            tail->prev = head;
        }

        if (head->data == data) // don't do this
            return;

        Node *temp = head;
        int i;
        for (i = 0; i < maxSize; i++, temp = temp->next)
        {

            if (temp->data == data)
            {
                Node *toAddToFront = temp;
                toAddToFront->prev->next = temp->next;
                if (toAddToFront->next != nullptr)
                {
                    toAddToFront->next->prev = temp->prev;
                }
                addToLeft(toAddToFront);
                return;
            }

            if (temp->next == nullptr)
                break;
        }
        if (i >= maxSize)
        {
            addToLeft(new Node(data));
            cout << removeFromRight() << endl;
        }
        else if (i < maxSize)
        {
            addToLeft(new Node(data));
        }
    }

    void
    // checkIfInCacheElseAdd(int data)
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

int LRU::maxSize = 3;

int main(int argc, char const *argv[])
{
    LRU mLRU = LRU();
    mLRU.checkIfInCacheElseAdd(1);
    mLRU.checkIfInCacheElseAdd(2);
    mLRU.checkIfInCacheElseAdd(3);
    mLRU.checkIfInCacheElseAdd(1);
    mLRU.checkIfInCacheElseAdd(4);
    return 0;
}
