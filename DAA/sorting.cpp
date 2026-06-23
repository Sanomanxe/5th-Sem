#include <iostream>
using namespace std;

// Function to display array
void display(int arr[], int n)
{
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Bubble Sort with tracing
void bubbleSort(int arr[], int n)
{
    cout << "\n--- Bubble Sort Trace ---\n";

    for(int i = 0; i < n - 1; i++)
    {
        cout << "Pass " << i + 1 << ": ";

        for(int j = 0; j < n - i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }

        display(arr, n);
    }
}

// Selection Sort with tracing
void selectionSort(int arr[], int n)
{
    cout << "\n--- Selection Sort Trace ---\n";

    for(int i = 0; i < n - 1; i++)
    {
        int minIndex = i;

        for(int j = i + 1; j < n; j++)
        {
            if(arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        swap(arr[i], arr[minIndex]);

        cout << "Step " << i + 1 << ": ";
        display(arr, n);
    }
}

// Insertion Sort with tracing
void insertionSort(int arr[], int n)
{
    cout << "\n--- Insertion Sort Trace ---\n";

    for(int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;

        cout << "Step " << i << ": ";
        display(arr, n);
    }
}

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter elements:\n";

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int choice;

    do
    {
        int temp[n];

        // Copy original array
        for(int i = 0; i < n; i++)
        {
            temp[i] = arr[i];
        }

        cout << "\nChoose Sorting Method:\n";
        cout << "1. Bubble Sort\n";
        cout << "2. Selection Sort\n";
        cout << "3. Insertion Sort\n";
        cout << "4. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                bubbleSort(temp, n);
                cout << "\nFinal Sorted Array: ";
                display(temp, n);
                break;

            case 2:
                selectionSort(temp, n);
                cout << "\nFinal Sorted Array: ";
                display(temp, n);
                break;

            case 3:
                insertionSort(temp, n);
                cout << "\nFinal Sorted Array: ";
                display(temp, n);
                break;

            case 4:
                cout << "Program Exited.";
                break;

            default:
                cout << "Invalid Choice!\n";
        }

    } while(choice != 4);

    return 0;
}