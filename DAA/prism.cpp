#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter number of vertices: ";
    cin >> n;

    int cost[10][10];

    cout << "Enter adjacency matrix:\n";
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> cost[i][j];

    bool visited[10] = {false};

    visited[0] = true;

    int edges = 0, totalCost = 0;

    cout << "\nEdges in MST:\n";

    while(edges < n - 1)
    {
        int min = 999, a = -1, b = -1;

        for(int i = 0; i < n; i++)
        {
            if(visited[i])
            {
                for(int j = 0; j < n; j++)
                {
                    if(!visited[j] &&
                       cost[i][j] < min &&
                       cost[i][j] != 0)
                    {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }

        cout << a << " - "
             << b
             << " = "
             << min << endl;

        visited[b] = true;
        totalCost += min;
        edges++;
    }

    cout << "Total Cost = "
         << totalCost << endl;

    return 0;
}
