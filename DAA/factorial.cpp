#include <iostream>

#include<Windows.h>
#include<conio.h>
using namespace std;

int main() {
    int n;
    long long fact = 1;

    cout << "Enter a number: ";
    cin >> n;

    cout << "\nTracing:\n";
    for (int i = 1; i <= n; i++) {
        fact = fact * i;

        cout << "Pass " << i << ": fact = " << fact << endl;
    }

    cout << "\nFactorial of " << n << " is " << fact;
    return 0;
    getch();
}

