#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int solve(int i, vector<int> &days, vector<int> &costs, vector<int> &dp){


if (i >= days.size())
    
return 0;

    if (dp[i] != -1)
        return dp[i];

int op1 = costs[0] + solve(i + 1, days, costs, dp);

    int j = i;
while (j < days.size() && days[j] < days[i] + 7)
        j++;

int op2 = costs[1] + solve(j, days, costs, dp);

    j = i;
while (j < days.size() && days[j] < days[i] + 30)
        j++;

int op3 = costs[2] + solve(j, days, costs, dp);

return dp[i] = min({op1, op2, op3});
}

int mincostTickets(vector<int> &days, vector<int> &costs){
vector<int> dp(days.size(), -1);

return solve(0, days, costs, dp);
}

int main()
{

    int n;
    cin >> n;

    vector<int> days(n);

    for (int i = 0; i < n; i++){
        cin >> days[i];
    }
    vector<int> costs(3);

    for (int i = 0; i < 3; i++){
        cin >> costs[i];
    }
    cout << mincostTickets(days, costs)<<endl;

    return 0;
}