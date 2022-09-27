#include <vector>
#include<iostream>
#include<unordered_set>
using namespace std;


//use set to remove duplicate number


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> res;
        //First find the starting point of the sequence, i.e. no smaller number is set as the starting point
        for(int i=0;i<nums.size();i++){
            res.insert(nums[i]);
        }
        int l = 0;
        //Take this number as a starting point
       for(const int& num : res){
           if(!res.count(num-1)){
               int curNum = num;
               int curLen = 1;
               //look for one greater than him, two greater. . . numbers like this
               while(res.count(curNum+1)){
                   curNum = curNum+1;
                   curLen = curLen+1;
               }
               //update the length
                l = max(l,curLen);
           }          
       }
        return l;
    }
};