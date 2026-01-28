#include <iostream>
using namespace std;

// Global counters for analysis
int timeCount = 0;     // counts basic operations (RAM model)
int maxDepth = 0;     // maximum recursion depth

int gcd(int a, int b, int depth) {
    timeCount++;                 // comparison b == 0
    if (depth > maxDepth)
        maxDepth = depth;        // track max recursion depth (space)

    cout << "Call " << depth << ": gcd(" << a << ", " << b << ")\n";

    if (b == 0) {
        timeCount++;             // return operation
        return a;
    }

    timeCount++;                 // modulo operation
    return gcd(b, a % b, depth + 1);
}

int main() {
    int a, b;

    cout << "Enter two numbers: ";
    cin >> a >> b;

    cout << "\n--- Tracing Euclid's Algorithm ---\n";
    int result = gcd(a, b, 1);

    cout << "\nGCD = " << result << endl;

    cout << "\n--- Complexity Calculations ---\n";
    cout << "Total basic operations (Time count) = " << timeCount << endl;
    cout << "Maximum recursion depth (Space used) = " << maxDepth << endl;

    cout << "\n--- Final Complexity (RAM Model) ---\n";
    cout << "Time Complexity  = O(log(min(a, b)))" << endl;
    cout << "Space Complexity = O(log(min(a, b)))" << endl;

    return 0;
}
