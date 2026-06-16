#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int prims(int V, vector<vector<pair<int,int>>>& adj)
{
    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    vector<int> vis(V, 0);

    pq.push({0, 0});

    int sum = 0;

    while(!pq.empty())
    {
        pair<int,int> it = pq.top();
        pq.pop();

        int wt = it.first;
        int node = it.second;

        if(vis[node] == 1)
            continue;

        vis[node] = 1;

        sum += wt;

        for(auto &nbr : adj[node])
        {
            int adjNode = nbr.first;
            int edgeWt = nbr.second;

            if(!vis[adjNode])
            {
                pq.push({edgeWt, adjNode});
            }
        }
    }

    return sum;
}

int main()
{
    int V, E;
    cin >> V >> E;

    vector<vector<pair<int,int>>> adj(V);

    for(int i=0;i<E;i++)
    {
        int u,v,w;
        cin >> u >> v >> w;

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    cout << prims(V, adj);

    return 0;
}