#include <vector>
#include<iostream>

using namespace std;
//Given a string s, partition s such that every substring of the partition is a palindrome. 
//Return all possible palindrome partitioning of s.

class Solution {
   vector<vector<string> > res;
    vector<string> ans;
    //judge wether the string is palindrome
    bool isPartition(string s ,int start, int end){
         for (int i = start, j = end; i < j; i++, j--) {
            if (s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }
    //
    void backtracking(string s ,int start){
        // If the starting position is already greater than the size of s, it means that a set of segmentation schemes have been found
        if(start>=s.size()){
            res.push_back(ans);
            return;
        }
        // find every substr
        for(int i =start ;i<s.size();i++){
            //if the substr is palindrome,put it to ans
            if(isPartition(s,start,i)){
                string str = s.substr(start,i-start+1);
                ans.push_back(str);
            }
            else continue;
            //change the start position 
            backtracking(s,i+1);
            ans.pop_back();        
        }
    }
public:
    vector<vector<string> > partition(string s) {
         backtracking(s, 0);
         return res;
    }
};