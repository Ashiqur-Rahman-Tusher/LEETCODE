/*Consider the problem of making change for N cents using the fewest number of coins. Assume that each
coin’s value is an integer. Write a greedy algorithm to make change consisting of quarters (25 cents),
dimes (10 cents), nickels (5 cents), and pennies (1 cent).
Sample input
N
Sample output
173 25 cents --- 6
10 cents --- 2
1 cents --- 3
Total 11 coins
Consider the problem of making change for N cents using the fewest number of coins. Assume that each
coin’s value is an integer and there are an in
finite number of coins for each coin type. Write a greedy
algorithm to make change consisting of coins .*/




#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
 void findmincoin(vector<int> &coin , int n){
    sort(coin.rbegin(),coin.rend());// desendding a sort korsi

    int totalcoin = 0;

    for(int i=0;i<coin.size();i++){
        if(n>=coin[i]){
            int count = n/coin[i];
            n=n%coin[i];
            totalcoin += count;
             cout<<coin[i]<<"cent : " << count <<"no."<<endl;
        }
       

    }
    cout << totalcoin << endl;
 }

int main(){
    int n = 173;

    vector<int> coin = {25,10,5,1};

    findmincoin(coin,n);





    return 0;
}