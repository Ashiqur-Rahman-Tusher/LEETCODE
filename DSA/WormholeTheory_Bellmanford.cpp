#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int main(){
    int src = 0;
int tc;
cin>>tc;
while (tc--)
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> edges;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back({u,v,w});
    }

    vector<int> dist(n,INT_MAX);
    dist[src] = 0;

    for(int i=0;i<n-1;i++){
        for(auto & edge : edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            if(dist[u] != INT_MAX && dist[u]+w<dist[v]){
                dist[v] = dist[u]+w;
            }
        }
    }
    bool negativecycle = false;


    for(auto & edge : edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            if(dist[u] != INT_MAX && dist[u]+w<dist[v]){
                negativecycle =  true;
                break;
            }
        }

        if(negativecycle){
            cout<<"possiible"<<endl;
        }
        else{
            cout<<"NOT possible"<<endl;
        }



}



    return 0;
}