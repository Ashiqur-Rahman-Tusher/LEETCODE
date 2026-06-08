#include<iostream>
#include<vector>

using namespace std;


int bellmanford(int V,vector<vector<int>> & edgelist,int src){
    vector<int> dist(V,1e9);
    dist[src]= 0;

    for(int i=0;i<V-1;i++){
        for(vector<int> edge : edgelist){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            if(dist[u]!=99999 && dist[u]+w < dist[v]){
                if(i==v-1){
                    return -1;
                }
                dist[v] = dist[u]+w;
            }
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

for(int dist : ans)
cout<< dist << " ";

    return 0;
}