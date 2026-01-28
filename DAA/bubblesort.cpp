#include <iostream>
using namespace std;

int main() {
    int n, i, j, temp;
    int arr[50];

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter array elements:\n";
    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Bubble Sort with tracing
    for (i = 0; i < n - 1; i++) {
        cout << "\nPass " << i + 1 << ": ";

        for (j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }

        // Print array after each pass
        for (int k = 0; k < n; k++) {
            cout << arr[k] << " ";
        }
    }

    cout << "\n\nFinal Sorted Array:\n";
    for (i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

