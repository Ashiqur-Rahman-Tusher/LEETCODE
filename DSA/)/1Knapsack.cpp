#include<iostream>
#include<vector>

using namespace std;

int knapsack(int w,vector<int> & val ,vector<int> & wt){
 int n= wt.size();
 vector<vector<int>> dp(n+1,vector<int>(w + 1));
for(int i=0;i<=n;i++){
    for(int j=0;j<=w;j++){

        if(i==0 || j==0){
            dp[i][j]=0;
        }
        else{
            int pick = 0;

            if(wt[i-1]<=j){
                pick = val[i-1]+dp[i-1][j-wt[i-1]];
            }
            
            int notpick = dp[i-1][j];
            dp[i][j] = max(pick,notpick);

        }

    }
}

return dp[n][w];

}

int main(){

vector<int> val = {1,2,3};
vector<int> wt = {4,5,1};

int w=4;

cout<<knapsack(w,val,wt)<<endl;
    return 0;
}