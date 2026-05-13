/*You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, which results in repetition of one number and loss of another number.

You are given an integer array nums representing the data status of this set after the error.

Find the number that occurs twice and the number that is missing and return them in the form of an array.

 

Example 1:

Input: nums = [1,2,2,4]
Output: [2,3]
Example 2:

Input: nums = [1,1]
Output: [1,2]
*/

#include<iostream>
#include <vector>
using namespace std;

vector<int> findErrorNums(vector<int>& nums) {
    int n = nums.size();
    vector<int> count(n + 1, 0); // 1 theke n porjonto count rakhar jonno
    int duplicate = -1, missing = -1;

    // Protiti sonkhya koybar ache ta count kori
    for (int x : nums) {
        count[x]++;
    }

    // Ekhon 1 theke n porjonto check kori
    for (int i = 1; i <= n; i++) {
        if (count[i] == 2) {
            duplicate = i; // Jeita duibar ache
        } else if (count[i] == 0) {
            missing = i;    // Jeita ekbaro nei
        }
    }

    return {duplicate, missing};
}

int main(){
    vector<int> num = {1,2,2,4};

    vector<int> res = findErrorNums(num);

cout << "[" << res[0] << ", " << res[1] << "]" << endl;
return 0;

}