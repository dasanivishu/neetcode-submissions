class Solution {
public:
    int dir_x[4]={0,0,-1,1};
    int dir_y[4]={1,-1,0,0};
    int orangesRotting(vector<vector<int>>& grid) {
        // mutli source bfs , we will keep all roteen oranges in queue and do level order traversal
        int n=grid.size();
        int m=grid[0].size();
        int time=0;
        int fresh=0;
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                fresh++;

                if(grid[i][j]==2)
                {
                    q.push({i,j});
                }
                

            }   
        }
        
        while(fresh>0&&!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                int row=q.front().first;
                int col=q.front().second;
                q.pop();
                for(int j=0;j<4;j++)
                {
                    int n_row=row+dir_x[j];
                    int n_col=col+dir_y[j];
                    if(n_row>=0 && n_row<n && n_col>=0 && n_col<m && grid[n_row][n_col]==1)
                    {
                        q.push({n_row,n_col});
                        grid[n_row][n_col]=2;
                        fresh--;

                    }

                }
               


            }
            time++;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                return -1;
            }
        }
        return time;
        
    }
};
