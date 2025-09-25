#include <iostream>      // <-- needed for cout
#include <vector>
#include <string>
using namespace std;

// to place the queens recursively in n different rows 
class Solution
{
    public :

    bool isSafe(vector<string> &board,int row,int col,int n) //O(n)
    {
        //horizontal
        for(int j=0;j<n;j++)
        {
            if(board[row][j] == 'Q')
            {
                return false;
            }
        }

        //vertical
        for(int i=0;i<n;i++)
        {
            if(board[i][col] == 'Q')
            {
                return false;
            }
        }

        //left diagonal
        for(int i=row,j=col;i>=0 && j>=0; i--,j--)
        {
            if(board[i][j]=='Q')
            {
                return false;
            }
        }

        //right diagonal
        for(int i=row, j=col; i>=0 && j>=0; i--,j++)
        {
            if(board[i][j]=='Q')
            {
                return false;
            }
        }

        return true;
    }
    void nQueens(vector<string> &board, int row,int n,vector<vector<string>> &ans)
    {
        if(row ==n)
        {
            ans.push_back({board});
            return;
        }
         for(int j=0;j<n;j++)
         {
            if(isSafe(board,row,j,n))
            {
                board[row][j] = 'Q';
                nQueens(board,row+1,n,ans);
                 board[row][j] = '.';
            }
         }
    }
    vector<vector<string>> solveNQueens(int n)
    {
        
        //board creation
        vector<string> board(n,string(n,'.'));
        vector<vector<string>> ans;

        nQueens(board,0,n,ans);
        return  ans;

         
    }
};

int main() {
    Solution s;
    auto res = s.solveNQueens(4);   // example n = 4
    for (auto &b : res) {
        for (auto &row : b) cout << row << "\n";
        cout << "----\n";
    }
    return 0;
}