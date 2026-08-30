class Solution {
private:
int ROWS,COLS;
vector<pair<int,int>>directions={{1,0},{-1,0},{0,1},{0,-1}};
public:
    void dfs(vector<vector<char>>& board,int row,int col)
    {
        board[row][col]='#';//mark them as visited so we don't visit them and they are connected to edge 'O'
        for(int i=0;i<4;i++)
        {
            int n_row=row+directions[i].first;
            int n_col=col+directions[i].second;
            if(n_row >=0 && n_row<ROWS && n_col>=0 && n_col< COLS && board[n_row][n_col]=='O')
            dfs(board,n_row,n_col);
        }

    }
    void solve(vector<vector<char>>& board) {
        ROWS=board.size(),COLS=board[0].size();
        for(int r=0;r<ROWS;r++)
        {
            if(board[r][0]=='O')
            dfs(board,r,0);
            if(board[r][COLS-1]=='O')
            dfs(board,r,COLS-1);
        }
        for(int c=0;c<COLS;c++)
        {
            if(board[0][c]=='O')
            dfs(board,0,c);
            if(board[ROWS-1][c]=='O')
            dfs(board,ROWS-1,c);
        }
        for(int r=0;r<ROWS;r++)
        {
            for(int c=0;c<COLS;c++)
            {
                if(board[r][c]=='O')
                board[r][c]='X';
                else if(board[r][c]=='#')
                board[r][c]='O';
            }
        }

    }
};
