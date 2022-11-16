#include <iostream>
#include <string>

using namespace std;

class Node
{
public:
    /// @brief the data it holds
    int data;

    /// @brief next is the link to the next node in the array of connectedTo
    Node *next = nullptr;

    /// @brief connectedTo
    Node *cT = nullptr;

    string color = "white";
    Node(int data)
    {
        this->data = data;
    }
    Node()
    {
    }
};

class DFS
{
private:
    /* data */
public:
    DFS(/* args */)
    {
    }

    static int dfs(int clock, Node *node, int *result, int *index)
    {
        cout << endl
             << "Next in DFS Traversal Output: " << node->data;
        result[*index] = node->data;
        *index += 1;

        int startTime = clock;
        int endTime = startTime;

        while (node->cT != nullptr)
        {

            if (node->color.compare("white") != 0)
            {
                node->cT = node->cT->next;
                continue;
            }

            node->color = "gray";
            endTime = dfs(++clock, node->cT, result, index);
            node->cT = node->cT->next;
        }

        if (endTime == startTime)
            endTime++;

        cout << endl
             << "Of Node:" << node->data << endl
             << "Start Time: " << startTime << endl
             << "End Time: " << endTime << endl;

        return endTime + 1;
    }
};

int main(int argc, char const *argv[])
{

    int choice;
    int totalNumberOfNodes;
    Node *startNode = nullptr;

    cout << "Enter Total Number of Nodes: ";
    cin >> totalNumberOfNodes;
    Node *wholeArrayOfNode[totalNumberOfNodes];
    int data;

    for (int i = 0; i < totalNumberOfNodes; i++)
    {

        cout << "Enter data of Node " << i + 1 << ": ";
        cin >> data;
        wholeArrayOfNode[i] = new Node(data);
    }

    for (int i = 0; i < totalNumberOfNodes; i++)
    {
        while (true)
        {
            cout << "Enter the data of the node connected to Node with data " << wholeArrayOfNode[i]->data << " (in ascending order)\n-999 if nothing more is connected:";
            Node *temp = wholeArrayOfNode[i]->cT;

            cin >>
                choice;

            if (choice != -999)
            {
                Node *nodeFromData = nullptr;
                for (int j = 0; j < totalNumberOfNodes; j++)
                {
                    if (wholeArrayOfNode[j]->data == choice)
                    {
                        nodeFromData = wholeArrayOfNode[j];
                    }
                }

                if (temp == nullptr)
                {

                    // temp = nodeFromData;
                    wholeArrayOfNode[i]->cT = nodeFromData;
                    temp = wholeArrayOfNode[i]->cT;

                    // temp = getNodeFromData(choice);
                }
                else
                {
                    temp->next = nodeFromData;
                    temp = temp->next;
                }
            }
            else
            {
                break;
            }
        }
    }
    for (int j = 0; j < totalNumberOfNodes; j++)
    {
        cout << wholeArrayOfNode[j]->data << " is connected to: "; // << endl;
        Node *temp = wholeArrayOfNode[j]->cT;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    int res[100];
    int index = 0;
    DFS::dfs(1, wholeArrayOfNode[0], res, &index);

    // while (true)
    // {
    //     cout << "Do you want to add a node?" << endl
    //          << "1. Yes" << endl
    //          << "2. No" << endl
    //          << "Enter choice: ";
    //     cin >> choice;

    //     if (choice == 1)
    //     {
    //         cout << "Enter Node Data: ";
    //         cin >> choice;
    //     }
    // }

    return 0;
}
