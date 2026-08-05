#include <iostream>
#include <vector>
using namespace std;

class HeapSort
{
    vector<int> arr;

    void heapify(int n, int i)
    {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[left] > arr[largest])
            largest = left;

        if (right < n && arr[right] > arr[largest])
            largest = right;

        if (largest != i)
        {
            swap(arr[i], arr[largest]);
            heapify(n, largest);
        }
    }

public:
    void inputArray()
    {
        int n, x;
        cout << "Enter number of elements: ";
        cin >> n;

        arr.clear();

        cout << "Enter elements: ";
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            arr.push_back(x);
        }
    }

    void buildMaxHeap()
    {
        int n = arr.size();

        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(n, i);

        cout << "Max Heap Built Successfully." << endl;
    }

    void heapSort()
    {
        int n = arr.size();

        buildMaxHeap();

        for (int i = n - 1; i > 0; i--)
        {
            swap(arr[0], arr[i]);
            heapify(i, 0);
        }

        cout << "Array Sorted Successfully." << endl;
    }

    void display()
    {
        if (arr.empty())
        {
            cout << "Array is empty." << endl;
            return;
        }

        cout << "Elements: ";
        for (int x : arr)
            cout << x << " ";
        cout << endl;
    }
};

int main()
{
    HeapSort h;
    int choice;

    do
    {
        cout << "\n1. Input Array" << endl;
        cout << "2. Build Max Heap" << endl;
        cout << "3. Heap Sort (Ascending)" << endl;
        cout << "4. Display Array" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            h.inputArray();
            break;

        case 2:
            h.buildMaxHeap();
            break;

        case 3:
            h.heapSort();
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