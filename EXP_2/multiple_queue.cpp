#include <iostream>

using namespace std;

class Queue
{
private:
public:
    int front;
    int rear;
    static int size;
    static int arr[20];
    static int newKaFront;
    Queue();
    ~Queue();
    bool isQueueEmpty();
    bool isQueueFull();
    int enqueue(int);
    int dequeue();
    static void printAllQueue()
    {
        cout << endl
             << "Printing the Array storing all Queues: " << endl;
        for (int i = 0; i < 20; i++)
        {

            cout << Queue::arr[i] << " ";
            if ((i + 1) % 5 == 0)
            {
                cout << endl;
            }
        }
        cout << endl;
    }
};

int Queue::size = 5;
int Queue::newKaFront = 0;
int Queue::arr[] = {};

int main(int argc, char const *argv[])
{
    Queue q1 = Queue();
    Queue q2 = Queue();
    Queue q3 = Queue();
    Queue q4 = Queue();

    q1.enqueue(1);
    q1.enqueue(1);
    q1.enqueue(1);
    q1.enqueue(1);
    q1.enqueue(1);
    cout << "Trying to Overflow Queue Number 1: Error " << q1.enqueue(1) << endl;

    q2.enqueue(1);
    q3.enqueue(1);
    q4.enqueue(1);
    q4.dequeue();
    cout << endl;
    cout << "Trying to Underflow Queue Number 4: Error " << q4.dequeue() << endl;

    Queue::printAllQueue();

    return 0;
}

Queue::Queue()
{
    this->front = newKaFront;
    this->rear = front - 1;
    newKaFront += size;
}

Queue::~Queue()
{
}

bool Queue::isQueueEmpty()
{
    return (front > rear);
}

bool Queue::isQueueFull()
{
    return (rear == (front + size - 1));
}

int Queue::enqueue(int data)
{

    if (!isQueueFull())
    {
        arr[++rear] = data;
        cout << "Enqueuing in Queue Number " << ((front + rear) / 2) / size + 1;
        printAllQueue();
        return 200;
    }

    return -999;
}

int Queue::dequeue()
{
    if (!isQueueEmpty())
    {
        int toReturn = arr[front];
        arr[front++] = 0;
        cout << "Dequeuing Queue Number " << ((front + rear) / 2) / size + 1;
        printAllQueue();
        return toReturn;
    }

    return -999;
}