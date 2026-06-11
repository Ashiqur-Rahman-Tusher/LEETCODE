#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int maxprofit(vector<int> &price){
    int mini = INT_MAX;
    int profit = 0;

    for(int i=0;i<price.size(); i++) {

        mini = min(mini,price[i]);

        profit =max(profit, price[i] -mini);
    }

    return profit;
}

int main(){
int n;
cin>> n;

vector<int> price(n);

for(int i=0;i<n;i++){
    cin>>price[i];

}

cout<< maxprofit(price)<<endl;


    return 0;
}