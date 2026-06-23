#include <iostream>
#include <algorithm>
using namespace std;

struct Job {
    char id;
    int deadline, profit;
};

// Sort jobs by descending profit
bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

int main() {
    int n;
    cout << "Enter number of jobs: ";
    cin >> n;

    Job jobs[n];
    int maxDeadline = 0;

    for (int i = 0; i < n; i++) {
        cout << "Enter job id, deadline, profit: ";
        cin >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;
        maxDeadline = max(maxDeadline, jobs[i].deadline);
    }

    // Sort jobs by profit
    sort(jobs, jobs + n, compare);

    // Slot array based on maximum deadline
    bool slot[maxDeadline] = {false};
    char result[maxDeadline];
    int totalProfit = 0;

    cout << "\nTrace:\n";

    // Schedule jobs
    for (int i = 0; i < n; i++) {
        for (int j = min(maxDeadline, jobs[i].deadline) - 1; j >= 0; j--) {
            if (!slot[j]) {
                slot[j] = true;
                result[j] = jobs[i].id;
                totalProfit += jobs[i].profit;

                cout << "Job " << jobs[i].id
                     << " scheduled at slot " << j + 1
                     << " (Profit " << jobs[i].profit << ")" << endl;
                break;
            }
        }
    }

    cout << "\nSelected Jobs: ";
    for (int i = 0; i < maxDeadline; i++)
        if (slot[i])
            cout << result[i] << " ";

    cout << "\nTotal Profit = " << totalProfit << endl;

    return 0;
}
