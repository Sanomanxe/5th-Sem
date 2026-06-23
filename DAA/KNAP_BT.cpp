#include <iostream>
using namespace std;

int knapsack(int wt[], int val[], int n, int W)
{
    if(n == 0 || W == 0)
        return 0;

    if(wt[n - 1] > W)
        return knapsack(wt, val, n - 1, W);

    return max(
        val[n - 1] +
        knapsack(wt, val, n - 1, W - wt[n - 1]),
        knapsack(wt, val, n - 1, W)
    );
}

int main()
{
    int n, W;

    cout << "Enter items and capacity: ";
    cin >> n >> W;

    int wt[n], val[n];

    for(int i = 0; i < n; i++)
        cin >> wt[i] >> val[i];

    cout << "Maximum Profit = "
         << knapsack(wt, val, n, W);

    return 0;
}
