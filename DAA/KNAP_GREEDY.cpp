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
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;

    Item items[n];

    for(int i = 0; i < n; i++)
    {
        cin >> items[i].weight >> items[i].profit;
        items[i].ratio =
            (float)items[i].profit / items[i].weight;
    }

    cout << "Enter capacity: ";
    cin >> W;

    sort(items, items + n, compare);

    int profit = 0;

    for(int i = 0; i < n; i++)
    {
        if(W >= items[i].weight)
        {
            W -= items[i].weight;
            profit += items[i].profit;

            cout << "Selected item "
                 << i + 1 << endl;
        }
    }

    cout << "Profit = " << profit;

    return 0;
}
