class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size(),m=board[0].size();
        set<pair<int,int>>visited;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(dfs(i,j,visited,board,word,0))
                return true;
            }
        }
        return false;
        
    }
    bool dfs(int i,int j,set<pair<int,int>>visit,vector<vector<char>>& board,string word,int idx)
    {
        if(idx==word.size())
        return true;
        if(i<0||j<0 || i>=board.size()|| j>=board[0].size()|| word[idx]!=board[i][j]||visit.count({i,j})>0)
        return false;
        visit.insert({i,j});
        bool res=(dfs(i,j+1,visit,board,word,idx+1)||
             dfs(i,j-1,visit,board,word,idx+1)||
             dfs(i+1,j,visit,board,word,idx+1)||
             dfs(i-1,j,visit,board,word,idx+1));
        visit.erase({i,j});
        return res;


    }
};
