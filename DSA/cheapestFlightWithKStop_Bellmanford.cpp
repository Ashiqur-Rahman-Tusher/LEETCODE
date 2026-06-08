#include<iostream>
#include<vector>
#include<climits>

using namespace  std;

int cheepflight(int n,vector<vector<int>> &flight,int src,int dst,int k){
    vector<int> dist(n,INT_MAX);
    dist[src] = 0;
    for(int i=0;i<=k;i++){
        vector<int> temp = dist;
        for(auto & edge : flight){
            int u= edge[0];
            int v= edge[1];
            int w= edge[2];
            if(dist[u] != INT_MAX && dist[u]+w < temp[v]){
                temp[v] = dist[u]+w;
            }
        }
        dist = temp;
    }
    if(dist[dst]==INT_MAX){
        return{};
    }
    return dist[dst];
}


int main (){
int n,src,dst,k;
cout<<"enter N :"<<endl;
cin>>n;
vector<vector<int>> flight = {
    {0,1,100},
    {1,2,100},
    {2,0,100},
    {1,3,600},
    {2,3,200}
};

cout<<" enter src : "<<endl;
cin>>src;

cout<< " enter dst  ; "<< endl;
cin>>dst;

cout<< "enter k ; "<<endl;
cin>>k;



int ans = cheepflight(n,flight,src,dst,k);

cout<<"The cheepest cost is : "<<ans<<endl;


    return 0;
}