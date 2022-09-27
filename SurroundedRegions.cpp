#include <vector>
#include<iostream>
using namespace std;
//lt130
//Given an m x n matrix board containing 'X' and 'O', capture all regions that are 4-directionally surrounded by 'X'.
//A region is captured by flipping all 'O's into 'X's in that surrounded region.
class Solution {
public:

    void solve(vector<vector< char > >& board) {
        if(board.size() == 0) return;
        int m = board.size();
        int n = board[0].size();
        //Write a boundary O and its adjacent O as 1
        for(int i = 0;i< m ;i++){
            dfs(board,i,0);
            dfs(board,i,n-1);
        }
         for(int j = 0;j< n ;j++){
            dfs(board,0,j);
            dfs(board,m-1,j);
        }
        for(int i = 0;i<m ;i++){
            //turn 1 into O
            for(int j = 0;j<n;j++){
                if(board[i][j]=='1')
                    board[i][j]='O';
                //Change the remaining O to X
                else
                    board[i][j]='X';
            }
        }
    }
    void dfs(vector<vector<char> >& board,int i,int j)//把边界的‘O’变成'1’
    {
        if(i>=0&&j>=0&&i<board.size()&&j<board[0].size()&&board[i][j]=='O') 
        {
            board[i][j]='1';
            dfs(board,i+1,j);
            dfs(board,i-1,j);
            dfs(board,i,j+1);
            dfs(board,i,j-1);
        }
    }
};