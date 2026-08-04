#include <iostream>
#include <vector>
using namespace std;

class MinHeap
{
    vector<int> heap;

public:
    void insert(int x)
    {
        heap.push_back(x);
        int i = heap.size() - 1;

        while (i > 0)
        {
            int parent = (i - 1) / 2;

            if (heap[parent] > heap[i])
            {
                swap(heap[parent], heap[i]);
                i = parent;
            }
            else
                break;
        }
    }

    void extractMin()
    {
        if (heap.empty())
        {
            cout << "Heap is empty." << endl;
            return;
        }

        cout << "Extracted Minimum Element: " << heap[0] << endl;

        heap[0] = heap.back();
        heap.pop_back();

        int i = 0;

        while (true)
        {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int smallest = i;

            if (left < heap.size() && heap[left] < heap[smallest])
                smallest = left;

            if (right < heap.size() && heap[right] < heap[smallest])
                smallest = right;

            if (smallest != i)
            {
                swap(heap[i], heap[smallest]);
                i = smallest;
            }
            else
                break;
        }
    }

    void peek()
    {
        if (heap.empty())
            cout << "Heap is empty." << endl;
        else
            cout << "Minimum Element: " << heap[0] << endl;
    }

    void display()
    {
        if (heap.empty())
        {
            cout << "Heap is empty." << endl;
            return;
        }

        cout << "Heap elements: ";
        for (int x : heap)
            cout << x << " ";
        cout << endl;
    }
};

int main()
{
    MinHeap h;
    int choice, value;

    do
    {
        cout << "1. Insert" << endl;
        cout << "2. Extract Minimum" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display Heap" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter element to insert: ";
            cin >> value;
            h.insert(value);
            break;

        case 2:
            h.extractMin();
            break;

        case 3:
            h.peek();
            break;

        case 4:
            h.display();
            break;

        case 5:
            cout << "Exiting program..." << endl;
            break;

        default:
            cout << "Invalid choice." << endl;
        }

    } while (choice != 5);

    return 0;
}