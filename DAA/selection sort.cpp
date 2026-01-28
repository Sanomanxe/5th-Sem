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

    cout << "\nTracing of Selection Sort:\n";

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[minIndex]) {
                minIndex = j;
            }
        }

        // Swap
        int temp = a[i];
        a[i] = a[minIndex];
        a[minIndex] = temp;

        // Tracing
        cout << "Pass " << i + 1 << ": ";
        for (int k = 0; k < n; k++) {
            cout << a[k] << " ";
        }
        cout << endl;
    }

    return 0;
}

