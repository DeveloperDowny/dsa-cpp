#include <vector>
#include <iostream>

using namespace std;

class Heap
{
private:
    /* data */
public:
    vector<int> heapTree;
    Heap(/* args */) {}

    int getParentIndex(int i)
    {
        return (i - 1) / 2;
    }

    int getLeftChildIndex(int i)
    {
        return 2 * i;
    }

    int getRightChildIndex(int i)
    {
        return 2 * i + 1;
    }
    void heapify(int i)
    {
        if (i == 0)
            return;

        if (heapTree[i] < heapTree[getParentIndex(i)])
        {
            int temp = heapTree[i];
            heapTree[i] = heapTree[getParentIndex(i)];
            heapTree[getParentIndex(i)] = temp;

            heapify(getParentIndex(i));
        }
    }

    void printHeap()
    {
        cout << endl;

        for (int i = 0; i < heapTree.size(); i++)
        {
            cout << heapTree[i] << endl;
        }
        cout << endl;
    }
    void addToHeap(int data)
    {
        heapTree.push_back(data);
        heapify(heapTree.size() - 1);
    }
    void swap(int i, int j)
    {
        int temp = heapTree[i];
        heapTree[i] = heapTree[j];
        heapTree[j] = i;
    }

    void sortHeap(int currI, int lastI)
    {
        if (currI == lastI)
        {
            swap(lastI, 0);
            sortHeap(0, lastI - 1);
        }
        else if (currI > lastI)
        {
            return;
        }
        else if (heapTree[getLeftChildIndex(currI)] < heapTree[currI])
        {
            swap(getLeftChildIndex(currI), currI);
            sortHeap(getLeftChildIndex(currI), lastI);
        }
        else if (heapTree[getRightChildIndex(currI)] < heapTree[currI])
        {
            swap(getRightChildIndex(currI), currI);
            sortHeap(getRightChildIndex(currI), lastI);
        }

        // if (currI <= lastI)
        //     return;
        // if (heapTree[getLeftChildIndex(currI)] <= lastI)

        // int temp = heapTree[currI];
        // heapTree[currI] = heapTree[0];
        // heapTree[0] = temp;
        // heapify() // reverse heapify
    }
};

int main(int argc, char const *argv[])
{
    vector<int> dummyData;
    dummyData.push_back(20);
    dummyData.push_back(35);
    dummyData.push_back(9);
    dummyData.push_back(26);
    dummyData.push_back(49);
    dummyData.push_back(78);
    dummyData.push_back(2);
    dummyData.push_back(46);
    Heap mHeap = Heap();

    for (int i = 0; i < dummyData.size(); i++)
    {
        mHeap.addToHeap(dummyData[i]);
        mHeap.printHeap();
    }

    mHeap.printHeap();

    // real code
    //  int choice;
    //  while (true)
    //  {
    //      cout << endl
    //           << "Enter the next data of the heap (enter -999 to stop): ";
    //      cin >> choice;
    //      if (choice == -999)
    //      {
    //          break;
    //      }
    //      mHeap.addToHeap(choice);
    //      mHeap.printHeap();
    //  }
    // real code ends

    cout << endl
         << "The final heap: " << endl;
    mHeap.printHeap();

    mHeap.sortHeap(mHeap.heapTree.size() - 1, mHeap.heapTree.size() - 1);

    cout
        << endl
        << "Sorted heap: " << endl;
    mHeap.printHeap();

    return 0;
}

// heap sort. use array
// take input from user and make tree in heap form. top to bottom use karna hai
// add one by one. shift up process (swapping)
// min heap property
// parent should be less

// then while sorting, print phases wise

// max heap se ascending

// min heap se descending