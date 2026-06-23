#include <iostream>
using namespace std;

// Iterative Binary Search
int iterativeBinarySearch(int arr[], int n, int key)
{
    int low = 0, high = n - 1;

    while(low <= high)
    {
        int mid = (low + high) / 2;

        cout << "Checking index " << mid
             << " value = " << arr[mid] << endl;

        if(arr[mid] == key)
            return mid;

        else if(arr[mid] < key)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return -1;
}

// Recursive Binary Search
int recursiveBinarySearch(int arr[], int low, int high, int key)
{
    if(low > high)
        return -1;

    int mid = (low + high) / 2;

    cout << "Checking index " << mid
         << " value = " << arr[mid] << endl;

    if(arr[mid] == key)
        return mid;

    else if(arr[mid] < key)
        return recursiveBinarySearch(arr, mid + 1, high, key);

    else
        return recursiveBinarySearch(arr, low, mid - 1, key);
}

int main()
{
    int n, key;

    cout << "Enter size of sorted array: ";
    cin >> n;

    int arr[n];

    cout << "Enter sorted elements:\n";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter element to search: ";
    cin >> key;

    cout << "\nIterative Binary Search Trace:\n";
    int result1 = iterativeBinarySearch(arr, n, key);

    if(result1 != -1)
        cout << "Element found at index " << result1 << endl;
    else
        cout << "Element not found\n";

    cout << "\nRecursive Binary Search Trace:\n";
    int result2 = recursiveBinarySearch(arr, 0, n - 1, key);

    if(result2 != -1)
        cout << "Element found at index " << result2 << endl;
    else
        cout << "Element not found\n";

    return 0;
}
