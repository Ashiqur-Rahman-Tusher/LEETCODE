#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

pair<int ,int> max_min_div(int arr[],int l,int h){
    if(l==h){
        return{arr[l],INT_MAX};
    }

    int mid = (l+h)/2;

    pair<int,int> left_res = max_min_div(arr,l,mid);
    pair<int,int> right_res = max_min_div(arr,mid+1,h);

    pair<int,int> res;
    res.first = min(left_res.first,right_res.first);

    if(left_res.first==right_res.first){
        res.second = min(left_res.second,right_res.second);

    }
    else if(res.first==left_res.first){
        res.second = min(left_res.second,right_res.first);
    }
    else{
        res.second = min(right_res.second,left_res.first);
    }

    return res;

}

int main(){

    int arr[] = {1,19,-3,7,9,12,-46,54,36};

    int n = sizeof(arr)/sizeof(arr[0]);

    pair<int,int> res_div = max_min_div(arr,0,n-1);

    cout<<"min : "<<res_div.first<<endl;
    cout<<"min 2 : "<< res_div.second<<endl;


    return 0;
}