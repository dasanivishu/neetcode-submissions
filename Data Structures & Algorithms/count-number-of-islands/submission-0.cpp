class Solution {
public:
    int dir_x[4]={0,0,-1,1};
    int dir_y[4]={1,-1,0,0};
    bool isvalid(int i,int j,int n,int m)
    {
        return ((i>=0&&i<n)&&(j>=0&&j<m));
    }
    
    void bfs(vector<vector<char>>& grid,int i,int j,int n,int m)
    {
        queue<pair<int,int>>q;
        q.push({i,j});
        grid[i][j]='2';
        while(!q.empty())
        {
            pair<int,int> temp=q.front();
            q.pop();
            for(int dir=0;dir<4;dir++)
            {
                int new_i=temp.first+dir_x[dir];
                int new_j=temp.second+dir_y[dir];
                if(isvalid(new_i,new_j,n,m)&& grid[new_i][new_j]=='1')
                {
                    q.push({new_i,new_j});
                    grid[new_i][new_j]='2';
                }

            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1')
                {
                    bfs(grid,i,j,n,m);
                    count++;
                }
            }
        }
        return count;
        
    }
};
