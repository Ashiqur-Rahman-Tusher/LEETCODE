#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int adjacentSum(vector<int> &arr) {

    int n = arr.size();

    if (n == 1){
   return arr[0];
    }

    vector<int> dp(n);

    dp[0] = arr[0];
    dp[1] = max(arr[0], arr[1]);

    for (int i =2;i<n;i++) {

     int pick = arr[i] + dp[i - 2];
    int  notPick = dp[i - 1];

        dp[i] = max(pick, notPick);
    }

    return dp[n-1];
}

int main (){
int T;
    cin >> T;

    while (T--) {

    int n;
    cin >> n;

     vector<int> arr(n);

     for (int i = 0; i < n; i++){
    cin >> arr[i];
     }
        cout << adjacentSum(arr) << endl;
    }




}