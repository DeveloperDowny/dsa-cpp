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
    cout << "trying to overflow q1  " << q1.enqueue(1) << endl;
    cout << "dequeuing q1  " << q1.dequeue() << endl;

    q2.enqueue(1);
    q3.enqueue(1);
    q4.enqueue(1);
    cout << q4.dequeue();
    cout << endl;
    cout << q4.dequeue() << endl;

    for (int i = 0; i < 20; i++)
    {
        cout << Queue::arr[i] << " " << i << endl;
    }

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
        return toReturn;
    }
    return -999;
}
// menu driven
// when asked to insert, which queue to insert into
// user input dikhao