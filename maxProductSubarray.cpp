#include <vector>
#include<iostream>
#include<unordered_set>
using namespace std;

//Given an integer array nums, find a contiguous non-empty subarray within the array that has the largest product, and return the product.

class Solution {
public:
    
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;
        int maxnum = 1, minnum = 1;
        for (int i = 0; i < n; i++) {
            //If a negative number is encountered, the current maximum and minimum values ​​are swapped
            if (nums[i] < 0) swap(maxnum, minnum);
            //Record the maximum and minimum values
            maxnum = max(maxnum * nums[i], nums[i]);
            minnum = min(minnum * nums[i], nums[i]);
            ans = max(maxnum, ans);
        }
        return ans;
    }
};