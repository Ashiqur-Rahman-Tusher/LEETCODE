#include<iostream>
#include<utility>
#include<vector>

using namespace std;

pair<int,int> max_min(vector<int> v,int index){
if(index==0){
    return{v[index],v[index]};
}

pair<int,int> rec = max_min(v,index-1);

return {max(v[index],rec.first) , min(v[index],rec.second)};

}

pair<int,int> max_min_div(int arr[],int l, int h){

//base case : we've one element
if(l==h){
return {arr[l],arr[h]};

}

//divide the array

int mid = (l+h)/2;

pair<int,int> left_res = max_min_div(arr,l,mid);
pair<int,int> right_res = max_min_div(arr,mid+1,h);

//conquer
 pair<int,int> res;
 //max element
 res.first = max(left_res.first,right_res.first);
  //min element
res.second= min(left_res.second,right_res.second);

return res;

}

int main(){

vector<int> v = {1,4,8,-5,12,14,-16,20};
pair<int,int> rec = max_min(v,v.size()-1);
cout<<"max : "<<rec.first<<"  "<<"min : "<<rec.second<<endl;

int arr[] = {1,4,8,-5,12,14,-16,21};
int n = sizeof(arr)/sizeof(arr[0]);

pair<int,int> rec_div = max_min_div(arr,0,n-1);
cout<< "max: "<<rec_div.first<<" "<<"min: "<<rec_div.second<<endl;


return 0;
}
