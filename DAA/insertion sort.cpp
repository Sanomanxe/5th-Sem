#include <iostream>
using namespace std;

int main() {
    int a[50], n;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << "\nTracing of Insertion Sort:\n";

    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;

        // Move elements greater than key one position ahead
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;

        // Tracing
        cout << "Pass " << i << ": ";
        for (int k = 0; k < n; k++) {
            cout << a[k] << " ";
        }
        cout << endl;
    }

    return 0;
}

