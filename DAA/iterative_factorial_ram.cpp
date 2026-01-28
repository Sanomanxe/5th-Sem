#include <iostream>
using namespace std;

long long factorialRAMTrace(int n, long long &timeOps, int &spaceUsed) {
    timeOps = 0;

    // Space used by variables: n, i, fact
    spaceUsed = sizeof(int) * 2 + sizeof(long long); // i, n, fact

    timeOps++;                   // fact = 1
    long long fact = 1;

    cout << "Iteration Trace:\n";
    cout << "i\tfact(before)\tOperation\tfact(after)\tCumulative RAM Ops\n";

    timeOps++;                   // i = 1 (loop init)
    for (int i = 1; i <= n; i++) {
        timeOps++;               // loop comparison i <= n

        long long factBefore = fact;

        timeOps++;               // multiplication fact * i
        long long temp = fact * i;

        timeOps++;               // assignment fact = temp
        fact = temp;

        timeOps++;               // increment i (for RAM count)
        
        cout << i << "\t" << factBefore 
             << "\t\t* " << i 
             << "\t\t" << fact 
             << "\t\t" << timeOps << "\n";
    }
    timeOps++;                   // final loop comparison
    timeOps++;                   // return operation

    return fact;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    long long timeOps;
    int spaceUsed;
    long long result = factorialRAMTrace(n, timeOps, spaceUsed);

    cout << "\nFactorial of " << n << " = " << result << endl;
    cout << "Estimated Time Complexity (RAM operations) = " << timeOps << endl;
    cout << "Estimated Space Complexity (bytes) = " << spaceUsed << endl;

    // Big-O Notation
    cout << "Time Complexity (Big-O) = O(n)" << endl;
    cout << "Space Complexity (Big-O) = O(1)" << endl;

    return 0;
}
