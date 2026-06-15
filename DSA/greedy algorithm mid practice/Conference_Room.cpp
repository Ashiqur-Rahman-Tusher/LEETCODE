// activity selection in greedy

/*Ekti Coworking Space-e ekti matro Conference Room ache. Onekgulo Startup company sei room-ti bebohar korar jonno request pathiyeche.Constraints (Shorto-boli):Time Format: Protiti request-er format: [Start Time, End Time].Cleaning Break: Ekta company room chere jawar thik porer muhurtei arekta company dhukte parbe na. Protiti meeting-er por room-ti porishkar korar jonno ontoto 2 unit time gap thakte hobe.Sutorang, jodi ekti meeting $T$ somoy-e shesh hoy, porer meeting-ti $T + 2$ somoy ba tar pore shuru hote hobe.Special Condition (Priority): Jodi duiti request-er End Time eki hoy, tobe jey meeting-ti beshi deri te shuru hoyeche setake priority dite hobe (karon setar duration kom, fole room-ti baki somoy khali thakar sujog thake).Problem Data:Niche 7-ti meeting request-er list dewa holo:{ [1, 5], [4, 8], [7, 10], [12, 15], [9, 15], [17, 22], [15, 20] }Tomake ja korte hobe:Earliest Departure Time (Greedy) logic bebohar kore koto beshi meeting kora somvob setar count ber koro.Kont kono meeting gulo select korle (Meeting intervals) setar ekta list dekhao.Ai pura logic-ti diye ekti C++ code likho.Hint for solving:Prothome End Time onujayi sort koro.Jodi End Time mile jay, tobe Start Time onujayi sort koro (descending order-e).Selection condition-e +2 gap-er kotha mathay rakho.*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool compare1(vector<int> &a , vector<int> &b){
    if(a[1] != b[1]){
        return a[1]< b[1]; 
    }
    else{
        return a[0]>b[0];
    }
}


int activity(vector<int> &start,vector<int> &finish){
    vector<vector<int>> arr ;
for(int i=0;i< start.size();i++){
    arr.push_back({start[i],finish[i]});
}
sort(arr.begin(),arr.end(),compare1);

int ans = 1;
int j=0;
cout<< "select intarval : "<< arr[0][0]<<","<<arr[0][1]<<endl;


for(int i=1;i<arr.size();i++){
    if(arr[i][0]>=arr[j][1]+2){
        ans++;
        cout<< arr[i][0]<<","<<arr[i][1]<<endl;
        j=i;

    }
}
cout<<"total count : ";
return ans;

}
int main(){
    vector<int> start = {1,4,7,12,9,17,15};
    vector<int> finish = {5,8,10,15,15,22,20};
    cout << activity(start,finish) << endl;

    return 0;
}