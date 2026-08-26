class Solution {
public:
   int dir_x[4]={0,0,1,-1};
   int dir_y[4]={1,-1,0,0};
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0)
                {
                     q.push({i,j});
                     visited[i][j]=1;
                }
               
            }
        }
        int level=0;
        while(!q.empty())
        {
            auto temp=q.front();q.pop();
            int row=temp.first,col=temp.second;
            for(int i=0;i<4;i++)
            {
                int n_row=row+dir_x[i];
                int n_col=col+dir_y[i];
                if(n_row>=0 && n_row<n &&n_col>=0&&n_col<m && !visited[n_row][n_col] && grid[n_row][n_col]!=-1)
                {
                    q.push({n_row,n_col});
                    visited[n_row][n_col]=1;
                    grid[n_row][n_col]= grid[row][col]+1;            
                }          
            }
        }
        
    }
};
