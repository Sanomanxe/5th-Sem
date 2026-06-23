#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int key, int &comparisons)
{
    comparisons = 0;

    for(int i = 0; i < n; i++)
    {
        comparisons++;

        cout << "Comparison " << comparisons
             << ": checking arr[" << i << "] = "
             << arr[i] << endl;

        if(arr[i] == key)
            return i;
    }

    return -1;
}

int main()
{
    int n, key;

    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];

    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter element to search: ";
    cin >> key;

    int comparisons;
    int result = linearSearch(arr, n, key, comparisons);

    if(result != -1)
        cout << "\nElement found at index "
             << result << endl;
    else
        cout << "\nElement not found" << endl;

    cout << "Total comparisons = "
         << comparisons << endl;

    return 0;
}
