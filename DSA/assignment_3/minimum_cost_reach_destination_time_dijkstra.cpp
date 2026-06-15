#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int minCost(int maxTime,vector<vector<int>> &edges,vector<int> &passingFees){

    int n =passingFees.size();

    vector<vector<pair<int, int>>> adj(n);

    for (auto &e :edges)
    {

        int u =e[0];
        int v =e[1];
        int t =e[2];

        adj[u].push_back({v, t});
        adj[v].push_back({u, t});
    }

    vector<int> bestTime(n, INT_MAX);

    priority_queue<
    vector<int>,
    vector<vector<int>>,
    greater<vector<int>>>
    pq;

    pq.push({passingFees[0],0,0});

    bestTime[0] =0;

    while(!pq.empty())
    {

        auto cur = pq.top();
        pq.pop();

        int cost = cur[0];
        int time = cur[1];
        int node = cur[2];

        if (node == n - 1)
            return cost;

        for (auto &it : adj[node]){

            int nxt = it.first;
            int travel = it.second;

            int newTime = time + travel;
            int newCost = cost + passingFees[nxt];

            if (newTime > maxTime){
                continue;
            }

            if (newTime < bestTime[nxt]){

                bestTime[nxt] = newTime;

                pq.push({newCost,
                         newTime,
                         nxt});
            }
        }
    }

    return -1;
}

int main()
{

    int maxTime, m, n;

    cin >> maxTime;
    cin >> m;

    vector<vector<int>> edges(m, vector<int>(3));

    for (int i = 0; i < m; i++)
    {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    cin >> n;

    vector<int> fees(n);

    for (int i = 0; i < n; i++)
    {
        cin >> fees[i];
    }

    cout << minCost(maxTime, edges, fees) << endl;

    return 0;
}