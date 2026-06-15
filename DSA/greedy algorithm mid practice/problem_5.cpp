#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// আইটেমের নাম রাখার জন্য একটি স্ট্রাকচার বা গ্লোবাল ম্যাপ ব্যবহার করা যায়
string itemNames[] = {"Saffron", "Sugar", "Salt", "Rice"};

// Comparison function: value/weight ratio অনুযায়ী বড় থেকে ছোট ক্রমানুসারে সাজাবে
bool compare(const vector<double>& a, const vector<double>& b) {
    double r1 = a[0] / a[1]; // value / weight
    double r2 = b[0] / b[1];
    return r1 > r2;
}

int main() {
    // items[i][0] = value, items[i][1] = weight, items[i][2] = original index (নামের জন্য)
    vector<vector<double>> items = {
        {2000, 8, 0}, // Saffron
        {500, 5, 1},  // Sugar
        {870, 10, 2}, // Salt
        {840, 12, 3}  // Rice
    };

    sort(items.begin(), items.end(), compare);

    int capacity = 9;
    int thiefCount = 0;
    int i = 0; // বর্তমান আইটেম ইনডেক্স

    // যতক্ষণ দোকানে আইটেম বাকি আছে
    while (i < items.size()) {
        thiefCount++;
        double currentCapacity = capacity;
        double currentProfit = 0.0;

        cout << "Thief " << thiefCount << " enters:" << endl;

        // একজন চোর তার ৯ কেজি পূর্ণ করবে বা দোকানের আইটেম শেষ করবে
        while (currentCapacity > 0 && i < items.size()) {
            if (items[i][1] <= currentCapacity) {
                // পুরো আইটেমটি নিয়ে নেবে
                currentProfit += items[i][0];
                currentCapacity -= items[i][1];
                cout << "- Took " << items[i][1] << " kg of " << itemNames[(int)items[i][2]] << endl;
                i++; // এই আইটেম শেষ, পরেরটায় যাও
            } else {
                // আইটেমের কিছু অংশ নেবে
                double fractionValue = (items[i][0] / items[i][1]) * currentCapacity;
                currentProfit += fractionValue;
                
                // আইটেমের বাকি অংশ আপডেট করা
                items[i][0] -= fractionValue;
                items[i][1] -= currentCapacity;
                
                cout << "- Took " << currentCapacity << " kg of " << itemNames[(int)items[i][2]] << endl;
                currentCapacity = 0; // ব্যাগ ভরে গেছে
            }
        }
        cout << "Total Profit for Thief " << thiefCount << ": " << currentProfit << " taka" << endl << endl;
    }

    cout << "Total thieves needed: " << thiefCount << endl;

    return 0;
}