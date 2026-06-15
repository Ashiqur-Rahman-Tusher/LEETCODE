#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

string itemname[] = {"safron","suger","salt","rice"};

bool compare(vector<double> &a , vector<double> & b){
    double r1 = a[0] / a[1];
    double r2 = b[0] / b[1];
    return r1 > r2;
}

int main(){

    vector<vector<double>> items = {
        {2000,8,0},
        {500,5,1},
        {870,10,2},
        {840,12,3}
    };

    sort(items.begin(),items.end(),compare);

    int capacity = 9;
    int theifcount = 0;
    int i = 0;

    while(i<items.size()){
        theifcount++;
        double currentcapacity = capacity;
        double currentprofit = 0.0;
        cout<<"Theif : "<<theifcount<<"Enter : "<<endl;

        while (currentcapacity>0 && i<items.size())
        {
            if(items[i][1] <= currentcapacity){
                currentprofit += items[i][0];
                currentcapacity -= items[i][1];
                cout<<"took "<<items[i][1]<<"kg of "<<itemname[(int)items[i][2]] << endl;
                i++;
            }
            else{
                double fractionvalue = (items[i][0] / items[i][1] * currentcapacity);
                currentprofit += fractionvalue;

                items[i][0] -= fractionvalue;
                items[i][1] -= currentcapacity;

                                cout << "- Took " << currentcapacity << " kg of " << itemname[(int)items[i][2]] << endl;
                                currentcapacity = 0;

            }
        }
        cout << "Total Profit for Thief " << theifcount << ": " << currentprofit << " taka" << endl << endl;

    }

 cout << "Total thieves needed: " << theifcount << endl;

    return 0;
}