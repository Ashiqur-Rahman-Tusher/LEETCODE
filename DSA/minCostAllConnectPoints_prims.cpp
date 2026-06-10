#include<iostream>
#include<vector>
#include<climits>
#include<cmath>

using namespace std;

int minKey(vector<int>& key, vector<bool>& mstSet)
{
    int mini = INT_MAX;
    int index = -1;

    for(int i=0; i<key.size(); i++)
    {
        if(!mstSet[i] && key[i] < mini)
        {
            mini = key[i];
            index = i;
        }
    }

    return index;
}

int minCostConnectPoints(vector<vector<int>>& points)
{
    int V = points.size();

    // Adjacency Matrix
    vector<vector<int>> graph(V, vector<int>(V, 0));

    // Manhattan Distance Calculation
    for(int i=0; i<V; i++)
    {
        for(int j=0; j<V; j++)
        {
            graph[i][j] =
                abs(points[i][0] - points[j][0]) +
                abs(points[i][1] - points[j][1]);
        }
    }

    vector<int> parent(V, -1);
    vector<int> key(V, INT_MAX);
    vector<bool> mstSet(V, false);

    key[0] = 0;

    for(int count=0; count<V-1; count++)
    {
        int u = minKey(key, mstSet);

        mstSet[u] = true;

        for(int v=0; v<V; v++)
        {
            if(!mstSet[v] &&
               graph[u][v] < key[v])
            {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    int totalCost = 0;

    cout << "\nMST Edges:\n";

    for(int i=1; i<V; i++)
    {
        cout << parent[i]
             << " -> "
             << i
             << " = "
             << graph[parent[i]][i]
             << endl;

        totalCost += graph[parent[i]][i];
    }

    return totalCost;
}

int main()
{
    int n;

    cout << "Enter number of points: ";
    cin >> n;

    vector<vector<int>> points(n, vector<int>(2));

    cout << "Enter points (x y):\n";

    for(int i=0; i<n; i++)
    {
        cin >> points[i][0] >> points[i][1];
    }

    int ans = minCostConnectPoints(points);

    cout << "\nMinimum Cost = "
         << ans
         << endl;

    return 0;
}