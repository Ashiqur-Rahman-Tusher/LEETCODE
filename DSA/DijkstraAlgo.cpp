#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

vector<int> dijkstra(int v, vector<vector<pair<int,int>>> &graph,int src){
vector<int> dist(v,INT_MAX);
priority_queue<
pair<int,int>,
vector<pair<int,int>>,
greater<pair<int,int>>> pq;
dist[src] = 0;

pq.push({0,src});

while (!pq.empty())
{
    int d = pq.top().first;
    int u = pq.top().second;
    pq.pop();

    if(d>dist[u]){
        continue;
    }

    for(auto & edge : graph[u]){
        int v = edge.first;
        int w = edge.second;

        if(dist[u]+w <dist[v]){
            dist[v] = dist[u]+w;
            pq.push({dist[v],v});
        }
    }
}
return dist;

}


int main(){
    int v,e;
    cout<<"enter vertics :"<<endl;
    cin>>v;
    cout<<"enter edges :"<<endl;
    cin>>e;

    vector<vector<pair<int,int>>> graph(v);

    cout<<" enter edges :"<<endl;

    for(int i=0;i<e;i++){
        int u,v,w;
        cin>> u>>v>>w;

        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }
    int src;

    cout<<"Enter the srcnode : "<<endl;
    cin>>src;

    vector<int> dist = dijkstra(v,graph,src);

    for(int i=0;i<v;i++){
        cout<<src<<"->"<<i<<" : "<<dist[i]<<endl;
    }






return 0 ;
}