

// ai code ta holo greedy algorithm ar 2 pointer ar algo...
//like .... লিটকোডের (LeetCode) বিখ্যাত "Assign Cookies" সমস্যার মতো। সেখানে কুকিজ দিয়ে বাচ্চাদের খুশি করতে হয়, আর এখানে স্কলারশিপ দিয়ে ছাত্রদের।


#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int maxximumnum(vector<int> &r,vector<int> &v){
    
    sort(r.begin(),r.end());
    sort(v.begin(),v.end());

    int i = 0;
    int j = 0;
    int count = 0;

    while(i < r.size() && j< v.size()){
        if(v[j]>=r[i]){
            count++;
            i++;
        }
        j++;

    }
    return count;


}

int main(){

vector<int> r = {3000,3200,4300,5000,6000,7000,9000,10000,12000,16000};
vector<int> v = {4000,5000,6000,8000,13000,16500,17000};

cout<<"final count : "<<maxximumnum(r,v)<<endl;

    return 0;
}