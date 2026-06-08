#include<iostream>
#include<vector>
#include<climits>

using namespace std;


vector<int> bellmanford(int V,vector<vector<int>> & edgelist,int src){
    vector<int> dist(V,INT_MAX);
    dist[src]= 0;

    for(int i=0;i<V;i++){
        for(auto & edge : edgelist){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            if(dist[u]!=INT_MAX && dist[u]+w < dist[v]){
                dist[v] = dist[u]+w;
            }
        }

    }
    for(auto & edge : edgelist){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            if(dist[u]!=INT_MAX && dist[u]+w < dist[v]){
                cout<< "negative weight cycle ditected "<<endl;
                return {};

            }
        }
    return dist;
}

int main(){
int V,E;
cout<<"Enter the vertecs count :"<<endl;
cin>>V;
cout<<"Enter the edge count :"<<endl;
cin>>E;
vector<vector<int>> edgelist;
cout<<"Enter the edges : "<<endl;
for(int i=0 ;i<E;i++){
int u,v,w;
cin>>u>>v>>w;
edgelist.push_back({u,v,w});
}
int src = 0;

vector<int> ans = bellmanford(V,edgelist,src);

for(int i=0 ;i<V;i++){
cout<< src<<"to"<<i<<"->"<<ans[i]<<endl;
}


    return 0;
}