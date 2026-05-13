/*Given the array nums, for each nums[i] find out how many numbers in the array are smaller than it. That is, for each nums[i] you have to count the number of valid j's such that j != i and nums[j] < nums[i].

Return the answer in an array.

 

Example 1:

Input: nums = [8,1,2,2,3]
Output: [4,0,1,1,3]
Explanation: 
For nums[0]=8 there exist four smaller numbers than it (1, 2, 2 and 3). 
For nums[1]=1 does not exist any smaller number than it.
For nums[2]=2 there exist one smaller number than it (1). 
For nums[3]=2 there exist one smaller number than it (1). 
For nums[4]=3 there exist three smaller numbers than it (1, 2 and 2).*/


#include <iostream>
#include <vector>
#include <algorithm> // sort করার জন্য
#include <unordered_map> // map ব্যবহার করার জন্য

using namespace std;

vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
    // ১. অরিজিনাল অ্যারের একটি কপি তৈরি করা
    vector<int> sorted_nums = nums;
    
    // ২. কপি করা অ্যারেটি ছোট থেকে বড় সাজানো (O(n log n))
    sort(sorted_nums.begin(), sorted_nums.end());
    
    // ৩. ম্যাপে প্রতিটি সংখ্যার প্রথম পজিশন সেভ করা
    unordered_map<int, int> mp;
    for (int i = 0; i < sorted_nums.size(); i++) {
        // যদি সংখ্যাটি ম্যাপে আগে থেকে না থাকে, তবেই ইনডেক্সটি রাখবো
        // কারণ একই সংখ্যা বারবার থাকলে শুধু প্রথম ইনডেক্সটাই আমাদের দরকার
        if (mp.find(sorted_nums[i]) == mp.end()) {
            mp[sorted_nums[i]] = i;
        }
    }
    
    // ৪. অরিজিনাল অ্যারের প্রতিটি মানের জন্য ম্যাপ থেকে রেজাল্ট বের করা
    vector<int> result;
    for (int x : nums) {
        result.push_back(mp[x]);
    }
    
    return result;
}

int main() {
    vector<int> nums = {8, 1, 2, 2, 3};
    vector<int> ans = smallerNumbersThanCurrent(nums);
    
    cout << "Output: ";
    for (int x : ans) {
        cout << x << " ";
    }
    return 0;
}