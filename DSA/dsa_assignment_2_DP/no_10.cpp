#include <iostream>
#include <vector>
using namespace std;

int main() {

    int m, n;
    cin >> m >> n;

    vector<int> coins(n);

    for (int i = 0; i < n; i++)
     cin >> coins[i];

    int D;
    cin >> D;

    vector<vector<bool>> dp(m + 1, vector<bool>(D + 1, false));

    dp[0][0] = true;

    for (int coin : coins) {

    for (int sum=m;sum>=coin;sum--) {

      for (int cnt= D;cnt >= 1; cnt--) {

         if (dp[sum-coin][cnt - 1])
         dp[sum][cnt] = true;
      }
    }
    }

    bool possible = false;

    for (int cnt=0;cnt<=D;cnt++) {

        if (dp[m][cnt]) {
            possible = true;
            break;
        }
    }

    cout << (possible ? "YES" : "NO")<< endl;

    return 0;
}