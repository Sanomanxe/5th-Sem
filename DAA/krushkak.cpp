#include <iostream>
#include <algorithm>
using namespace std;

struct Edge
{
    int u, v, weight;
};

bool compare(Edge a, Edge b)
{
    return a.weight < b.weight;
}

int parent[100];

int find(int i)
{
    while(parent[i] != i)
        i = parent[i];
    return i;
}

void unionSet(int a, int b)
{
    parent[a] = b;
}

int main()
{
    int V, E;

    cout << "Enter vertices and edges: ";
    cin >> V >> E;

    Edge edges[E];

    for(int i = 0; i < E; i++)
    {
        cout << "Enter u v weight: ";
        cin >> edges[i].u
            >> edges[i].v
            >> edges[i].weight;
    }

    for(int i = 0; i < V; i++)
        parent[i] = i;

    sort(edges, edges + E, compare);

    cout << "\nEdges in MST:\n";

    int totalCost = 0;

    for(int i = 0; i < E; i++)
    {
        int a = find(edges[i].u);
        int b = find(edges[i].v);

        if(a != b)
        {
            cout << edges[i].u << " - "
                 << edges[i].v
                 << " = "
                 << edges[i].weight
                 << endl;

            totalCost += edges[i].weight;
            unionSet(a, b);
        }
    }

    cout << "Total Cost = "
         << totalCost << endl;

    return 0;
}
