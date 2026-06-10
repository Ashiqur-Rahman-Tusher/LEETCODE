#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int cut(int n, int x,int y ,int z){

    vector <int> dp(n+1,-1);

    dp[0] =0;

    for(int i=0;i<n;i++){
         if (i >= x && dp[i -x]!=-1)
            dp[i] = max(dp[i], dp[i - x] + 1);

        if (i >= y && dp[i- y]!=-1)
            dp[i] = max(dp[i], dp[i - y] + 1);

        if (i >= z && dp[i -z]!=-1)
            dp[i] = max(dp[i], dp[i - z] + 1);
    }

    return max(0,dp[n]);
}


int main(){

int n,x,y,z;
cin>>n>>x>>y>>z;


cout<< cut(n,x,y,z)<<endl;

    return 0;
}