class Solution {
private:
vector<pair<int,int>>directions={{1,0},{-1,0},{0,1},{0,-1}};
public:
    void dfs(vector<vector<char>>& board,int row,int col)
    {
        board[row][col]='#';//mark them as visited so we don't visit them and they are connected to edge 'O'
        for(int i=0;i<4;i++)
        {
            int n_row=row+directions[i].first;
            int n_col=col+directions[i].second;
            if(n_row >=0 && n_row<board.size() && n_col>=0 && n_col<board[0].size() && board[n_row][n_col]=='O')
            dfs(board,n_row,n_col);
        }

    }
    void solve(vector<vector<char>>& board) {
        int n=board.size(),m=board[0].size();
        for(int i=0;i<n;i++)
        {
            if(board[i][0]=='O')
            dfs(board,i,0);
            if(board[i][m-1]=='O')
            dfs(board,i,m-1);
        }
        for(int i=0;i<m;i++)
        {
            if(board[0][i]=='O')
            dfs(board,0,i);
            if(board[n-1][i]=='O')
            dfs(board,n-1,i);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='O')
                board[i][j]='X';
                else if(board[i][j]=='#')
                board[i][j]='O';
            }
        }

    }
};
