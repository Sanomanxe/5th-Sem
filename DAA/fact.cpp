#include <iostream>
using namespace std;

// Recursive function
long long recursiveFactorial(int n)
{
    cout << "recursiveFactorial(" << n << ") called" << endl;

    if(n == 0 || n == 1)
        return 1;

    return n * recursiveFactorial(n - 1);
}

int main()
{
    int n;

    cout << "Enter a number: ";
    cin >> n;

    // Iterative method
    long long iterativeFact = 1;

    cout << "\nIterative Trace:\n";
    for(int i = 1; i <= n; i++)
    {
        iterativeFact *= i;

        cout << "After multiplying by "
             << i << " = "
             << iterativeFact << endl;
    }

    cout << "\nIterative Factorial = "
         << iterativeFact << endl;

    // Recursive method
    cout << "\nRecursive Trace:\n";
    long long recursiveFact =
        recursiveFactorial(n);

    cout << "\nRecursive Factorial = "
         << recursiveFact << endl;

    return 0;
}
