#include <iostream>
#include <algorithm>
using namespace std;

struct Item
{
    int weight, profit;
    float ratio;
};

bool compare(Item a, Item b)
{
    return a.ratio > b.ratio;
}

int main()
{
    int n, capacity;

    cout << "Enter number of items: ";
    cin >> n;

    Item items[n];

    for(int i = 0; i < n; i++)
    {
        cout << "Enter weight and profit of item " << i + 1 << ": ";
        cin >> items[i].weight >> items[i].profit;

        items[i].ratio =
            (float)items[i].profit / items[i].weight;
    }

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    sort(items, items + n, compare);

    float totalProfit = 0;

    cout << "\nTrace:\n";

    for(int i = 0; i < n; i++)
    {
        if(capacity >= items[i].weight)
        {
            capacity -= items[i].weight;
            totalProfit += items[i].profit;

            cout << "Taking full item "
                 << i + 1 << endl;
        }
        else
        {
            totalProfit +=
                items[i].ratio * capacity;

            cout << "Taking fraction of item "
                 << i + 1 << endl;
            break;
        }
    }

    cout << "Maximum Profit = "
         << totalProfit << endl;

    return 0;
}
