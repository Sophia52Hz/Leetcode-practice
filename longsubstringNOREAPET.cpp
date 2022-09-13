#include <vector>
#include<iostream>
#include<set>

using namespace std;
/* use set to store character, ues tow pointer to lead, 
once the reapet character show, j++,if not i++,
update the res */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<int> st;
        int i=0,j=0;
        int res = 0;
        while(i<s.size()){
            if(st.count(s[i])==0){
                st.insert(s[i]);
                i++;
                if(res < st.size()) {
                    res = st.size();
                }
            }
            else{
                st.erase(s[j]);
                j++;
        }
        }
        return res;
    }
};