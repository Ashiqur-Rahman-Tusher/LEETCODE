#include<iostream>
#include<vector>
#include<utility>
#include<climits>
using namespace std;
int croossum(int arr[],int l,int mid,int h){
    int l_sum = INT_MIN;
    int r_sum = INT_MIN;

int sum = 0;
for(int i=mid;i>=l;i--){
    sum += arr[i];
    l_sum = max(l_sum,sum);
}
sum =0;
for(int i=mid+1;i<=h;i++){
    sum += arr[i];
    r_sum = max(r_sum,sum);
}
return l_sum+r_sum;
}

int subb(int arr[],int l,int h){
    if(l==h){
        return arr[l];
    }

    int mid = (l+h)/2;

    int l_sum = subb(arr,l,mid);
    int r_sum = subb(arr,mid+1,h);
    int cross = croossum(arr,l,mid,h);

    return max(max(l_sum,r_sum),cross);
}

int main(){

    int arr[] = {1,2,4,6,-8,3,-4,5,-6,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<subb(arr,0,n-1)<<endl;



    return 0;
}