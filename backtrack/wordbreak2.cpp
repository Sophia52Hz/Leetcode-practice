#include <vector>
#include<iostream>
#include<unordered_set>

using namespace std;
class Solution {
public:
    vector<string> ans;
    int n;
    void dfs(string s, vector<string>& wordDict, int idx, string it) {
        if(idx==n) {
            it.pop_back();
            ans.push_back(it);
            return;
        }

        for(string word : wordDict) {
            int l=word.length();
            if(idx+l<=n&&s.substr(idx, l)==word)
                dfs(s, wordDict, idx+l, it+word+" ");
        }

    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        n=s.length();
        dfs(s, wordDict, 0, "");
        return ans;
    }
};