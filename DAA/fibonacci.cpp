#include <iostream>
#include<Windows.h>
using namespace std;

int main() {
    int n;
    int a = 0, b = 1, c;

    cout << "Enter number of terms: ";
    cin >> n;

    cout << "\nTracing:\n";
    for (int i = 1; i <= n; i++) {
        cout << "Term " << i << ": " << a << endl;
        c = a + b;
        a = b;
        b = c;
    }
	Sleep(300000);
    return 0;
}

