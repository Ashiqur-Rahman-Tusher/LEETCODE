#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int minCostClimb(vector<int>& cost) {
    int n = cost.size();


    int prev2 = cost[0];

    int prev1 = cost[1];

    for (int i=2;i<n;i++){
        int curr =cost[i] + min(prev1,prev2);
        prev2= prev1;
        prev1 =curr;
    }

    return min(prev1,prev2);
}


int main(){

int n;
cin>>n;

vector<int> cost(n);

for(int i=0;i<n;i++){

    cin >> cost[i] ;
}

cout<< minCostClimb(cost)<<endl;

    return 0 ;

}