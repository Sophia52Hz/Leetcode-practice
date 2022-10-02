#include <vector>
#include<iostream>

using namespace std;
//A peak element is an element that is strictly greater than its neighbors.
//Input: nums = [1,2,1,3,5,6,4]
//Output: 5
//Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;
        //Look in the direction of the rising peak, and you will definitely find the maximum value.
        while(l<r){
            int mid;
            mid = l+(r-l)/2;
            if(nums[mid]>nums[mid+1])
                r = mid;
            else
                l = mid+1;
        }
        return r;
    }
};