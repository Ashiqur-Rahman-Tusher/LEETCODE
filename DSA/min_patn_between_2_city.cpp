#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int ans = INT_MAX;

void dfs(int node,vector<vector<pair<int,int>>>& adj,vector<int>& vis) {

    vis[node] =1;

    for (auto & it :adj[node]) {

        int nxt =it.first;
        int dist =it.second;

        ans =min(ans, dist);

        if (!vis[nxt]) {
            dfs(nxt, adj, vis);
        }
    }
}

int minScore(int n, vector<vector<int>>& roads) {

    vector<vector<pair<int,int>>> adj(n + 1);

    for (auto & r : roads) {

        int u = r[0];
        int v = r[1];
        int d = r[2];

        adj[u].push_back({v, d});
        adj[v].push_back({u, d});
    }

    vector<int> vis(n+1,0);

    dfs(1,adj,vis);

    return ans;
}

int main() {

    int n, m;
    cin >>n>>m;

    vector<vector<int>> roads(m, vector<int>(3));

    for (int i = 0; i < m; i++) {
        cin >> roads[i][0]>> roads[i][1]>> roads[i][2];
    }

    cout << minScore(n, roads)<<endl;

    return 0;
}