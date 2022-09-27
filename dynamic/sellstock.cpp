#include <vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<=1)
            return 0;
        int minprice = prices[0],maxprice = 0;
        for(int i=1;i<prices.size();i++){
            maxprice = max(maxprice,prices[i]-minprice);
            minprice = min(minprice,prices[i]);
        }
        return maxprice;
    }
};