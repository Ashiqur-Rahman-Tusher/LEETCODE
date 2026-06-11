#include<iostream>
#include<vector>

using namespace std;

int stair(int n){
    if(n<=2){
        return n;
    }

    int p1 = 1;
    int p2 = 2;

    for(int i= 0;i<=n;i++){
        int cur = p1+p2;
        p2=p1;
        p1=cur;
    }
    return p1;
}

int main(){

int n;
cin>> n;

cout<< stair(n)<<endl;

    return 0;
}
