

// ai code ta gready ar sliding window ar kaj kore ,,,mane slide kore arr ar samne r dike jai 
// like....
// [3,6,5,4,8,2,1],9,10,5,13,42
// 3,[6,5,4,8,2,1,9],10,5,13,42


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int mindiff(vector<int> &a,int n,int m){
    if(n==0 || m==0) return 0;
    if(n<m) return -1;

    sort (a.begin(),a.end());

    int mindif = 9999999;

    for(int i = 0;i+m-1<n;i++){
        int cdiff = a[i+m-1]-a[i];
        if(cdiff<mindif){
            mindif = cdiff;
        }
    }
    return mindif;

}


int main(){

int n = 7;
int m = 3;

vector <int> a = {7, 3, 2, 4, 9, 12, 56};

cout<<"min diff : "<< mindiff( a , n,m)<<endl;

    return 0;
}