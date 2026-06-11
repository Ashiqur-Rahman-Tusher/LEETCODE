#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

int rob(vector<int> &num){

    int n =num.size();

    if(n==1){
        return num[0];
    }

    vector<int> dp(n);

    dp[0] =num[0];
    dp[1]  = max(num[0],num[1]);

    for (int i = 2; i < n; i++) {
        dp[i] = max(num[i] + dp[i - 2],
     dp[i - 1]);
    }

    return dp[n - 1];

}

int main(){
int n;
cin>>n;

vector<int> num(n);

for(int i=0;i<n;i++){
    cin>> num[i];
}

cout<<rob(num)<<endl;


    return 0;
}