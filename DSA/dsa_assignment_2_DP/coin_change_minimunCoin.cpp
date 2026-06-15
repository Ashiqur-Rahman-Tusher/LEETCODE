#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int coinchange(vector<int> &coins,int amount){
    vector<int>dp(amount+1,INT_MAX);

    dp[0]=0;

    for(int i = 1;i<=amount;i++){
        for(int coin : coins){

            if(i>=coin && dp[i-coin] != INT_MAX){
                dp[i]= min(dp[i],1+dp[i-coin]);
            }

        }
    }
    if(dp[amount]==INT_MAX){
        return -1;
    }
    else{
        return dp[amount];
    }
}

int main(){

int n;
    cin >> n;

    vector<int> coins(n);

    for (int i = 0; i < n; i++)
        cin >> coins[i];

    int amount;
    cin >> amount;

    cout << coinchange(coins, amount);


    return 0;
}