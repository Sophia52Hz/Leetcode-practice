#include <vector>
#include<iostream>
using namespace std;

int main(){
    cout<<"please input the number:  ";
    int num;
    cin>>num;
    vector<vector< int> > nums(num);
    for(int i=0;i<num;i++){
        nums[i].resize(i+1);
        nums[i][0]=1;
        nums[i][i]=1;
        for(int j=1;j<i;j++){
            nums[i][j]=nums[i-1][j]+nums[i-1][j-1];
        }
    }
    for(int i=0;i<nums.size();i++){
        for(int j=0;j<nums[i].size();j++){
            cout<<nums[i][j]<<" ";
        }
    }
    return 0;
}
