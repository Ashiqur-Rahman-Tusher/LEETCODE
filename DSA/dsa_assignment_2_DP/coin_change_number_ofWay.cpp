#include<iostream>
#include<vector>

using namespace std;

int countway(vector<int>&  coins, int amount){
    vector<int> dp (amount +1,0);
dp[0] = 1;

for(int coin: coins){
    for(int i =1;i<=amount;i++){
        dp[i]+=dp[i-coin];
    }
}
return dp[amount];
}


int main(){
int n;
    cin >> n;

    vector<int> coins(n);

    for (int i = 0; i < n; i++)
        cin >> coins[i];

    int amount;
    cin >> amount;

    cout << countway(coins, amount);


    return 0;
}