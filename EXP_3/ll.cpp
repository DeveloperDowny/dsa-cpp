#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    int expo;
    Node *next;

    Node(int coeff, int expo)
    {
        this->data = coeff;
        this->expo = expo;
    }
    Node()
    {
    }
};

class LL
{
public:
    Node *head;
    LL()
    {
        // head = new Node(1, 1);

        // head->next = nullptr;
        head = nullptr;
    }
    ~LL() {}

    void printLL()
    {
        Node *temp = head;
        cout << "Printing LL" << endl;
        while (temp != nullptr)
        {
            cout << temp->data << "x^" << temp->expo << " + ";
            temp = temp->next;
        }
        cout << "0" << endl
             << endl;
    }

    void testFunc()
    {
        Node *temp = head;
        for (int i = 2; i < 4; i++)
        {
            temp->next = new Node(i * 10, i);

            temp = temp->next;
        }
        temp->next = nullptr;
    }

    void multiply(LL eq2)
    {
        Node *temp = head;

        while (temp != nullptr)
        {
            Node *temp2 = eq2.head;
            while (temp2 != nullptr)
            {
                int res = temp->data * temp2->data;
                int expo = temp->expo + temp2->expo;
                Node *toMakeChangesTo = temp;
                while (toMakeChangesTo != nullptr)
                {
                    if (toMakeChangesTo->expo == expo)
                    {
                        if (toMakeChangesTo == temp)
                        {
                            break;
                        }
                        toMakeChangesTo->data += res;
                        break;
                    }
                    else
                    {
                        toMakeChangesTo = toMakeChangesTo->next;
                    }
                }

                // temp->data *= temp2->data;
                // temp->expo += temp->expo;
                temp2 = temp2->next;
            }

            temp = temp->next;
        }
    }

    void multiply(LL eq1, LL eq2)
    {

        Node *temp = eq1.head;
        // head = temp;
        // Node *temp3 = head;

        while (temp != nullptr)
        {
            Node *temp2 = eq2.head;
            Node *temp3 = head;

            while (temp2 != nullptr)
            {
                int prodCoef = temp->data * temp2->data;
                int resExpo = temp->expo + temp2->expo;

                if (temp3 == nullptr)
                {
                    head = new Node(prodCoef, resExpo);
                    head->next = nullptr;
                    temp3 = head;
                }
                else if (temp3->expo == resExpo)
                {
                    temp3->data += prodCoef;
                }
                else
                {

                    while (temp3->next != nullptr && temp3->next->expo != resExpo)
                    {
                        temp3 = temp3->next;
                    }

                    // if (temp3->next == nullptr){
                    //     temp3->next = new Node
                    // }

                    // if (temp3->next->expo == resExpo)
                    if (temp3->next == nullptr)
                    {
                        temp3->next = new Node(prodCoef, resExpo);
                        temp3->next->next = nullptr;
                    }
                    else // (temp3->next->expo == resExpo)
                    {
                        temp3->next->data += prodCoef;
                    }
                    // else
                    // {
                    //     temp3->next = new Node(prodCoef, resExpo);
                    // }
                }

                // if (temp3 == nullptr)
                // {
                //     head = new Node(prodCoef, resExpo);
                //     head->next = nullptr;
                //     temp3 = head;
                // }
                // else if (temp3->expo == resExpo)
                // {
                //     temp3->data += prodCoef;
                // }
                // else if (temp3->next != nullptr)
                // {
                //     temp3 = temp3->next;
                //     temp3->data += prodCoef;
                // }
                // else
                // {
                //     temp3->next = new Node(prodCoef, resExpo);
                // }

                temp2 = temp2->next;
            }

            temp = temp->next;
        }
    }

    void
    addNodeAt(Node *newNode, int pos)
    {
        if (head == nullptr)
        {
            head = newNode;

            head->next = nullptr;
            return;
        }

        if (pos == 1)
        {

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

            return;
        }

        Node *temp = head;
        while (pos-- > 1)
        {
            if (temp->next == nullptr)
            {
                temp->next = newNode;

                newNode->next = nullptr;
                break;
            }
            else
            {
                temp = temp->next;
            }
        }

        {
            return;
        }
        newNode->next = temp->next;
        if (newNode->next != nullptr)
        {
        }
        temp->next = newNode;
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

            delete temp;
            return;
        }

        Node *temp = head;
        while (pos-- > 1)
        {
            if (temp->next == nullptr)
            {
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

        delete toDelete;
    }
};

void testFunc(Node *&head)
{
    Node *temp = head;
    for (int i = 2; i < 4; i++)
    {
        head->next = new Node(i, i);

        head = head->next;
    }
    head->next = nullptr;
    head = temp;
}

int main(int argc, char const *argv[])
{

    LL eq1 = LL();
    LL eq2 = LL();
    LL result = LL();

    eq1.addNodeAt(new Node(5, 0), -1);
    eq1.addNodeAt(new Node(0, 1), -1);
    eq1.addNodeAt(new Node(10, 2), -1);
    eq1.addNodeAt(new Node(6, 3), -1);

    eq2.addNodeAt(new Node(1, 0), -1);
    eq2.addNodeAt(new Node(2, 1), -1);
    eq2.addNodeAt(new Node(4, 2), -1);

    eq1.printLL();
    eq2.printLL();

    // eq1.multiply(eq2);
    // eq1.printLL();

    result.multiply(eq1, eq2);
    result.printLL();
    // eq2.printLL();

    // LL mLL = LL();

    // mLL.testFunc();
    // cout << "Initial LL" << endl;
    // mLL.printLL();

    // mLL.addNodeAt(new Node(0, 0), 1);
    // cout << "After adding at 1st position" << endl;
    // mLL.printLL();

    // mLL.deleteNodeAt(1);
    // cout << "After deleting at 1st position" << endl;
    // mLL.printLL();

    return 0;
}