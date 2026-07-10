class Solution {
public:
   int n,m;
    bool exist(vector<vector<char>>& board, string word) {
      n=board.size();
      m=board[0].size();
        set<pair<int,int>>visited;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(dfs(i,j,board,word,0))
                return true;
            }
        }
        return false;
        
    }
    bool dfs(int i,int j,vector<vector<char>>& board,string word,int idx)
    {
        if(idx==word.size())
        return true;
        if(i<0||j<0 || i>=n|| j>=m|| word[idx]!=board[i][j]|| board[i][j]=='#')
        return false;
        
        board[i][j]='#'; //meaning visited
        bool res=(dfs(i,j+1,board,word,idx+1)||
             dfs(i,j-1,board,word,idx+1)||
             dfs(i+1,j,board,word,idx+1)||
             dfs(i-1,j,board,word,idx+1));
        board[i][j]=word[idx];
        return res;


    }
};
