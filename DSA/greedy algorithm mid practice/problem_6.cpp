#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
bool compare(vector<int> &a , vector<int> &b){
    return a[1]<b[1];
}

int activityselection(vector<int> &start , vector<int> &finish){
    vector<vector<int>> arr;
    for(int i =0;i< start.size();i++){
        arr.push_back({start[i], finish[i]});
    }

    sort(arr.begin(),arr.end(),compare);

    int ans =1;
    int j = 0;

    for(int i=1;i<arr.size();i++){
        if(arr[i][0]>=arr[j][1]+1){
            ans++;
            j=i;
        }
    }
    return ans;
}

int main(){
    vector<int> start = {8,6,11,2,1,12,7,13};
    vector<int> finish = {12,9,14,7,7,20,12,19};
     cout<<activityselection(start,finish)<<endl;
    return 0;
}