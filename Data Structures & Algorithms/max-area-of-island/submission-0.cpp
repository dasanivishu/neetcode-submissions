class Solution {
public:
    int dfs(int i,int j,int n,int m,vector<vector<int>>&grid)
    {
        if(i<0||i>=n||j<0||j>=m||grid[i][j]==0)return 0;
        grid[i][j]=0;
        int a=dfs(i+1,j,n,m,grid);
        int b=dfs(i-1,j,n,m,grid);
        int c=dfs(i,j-1,n,m,grid);
        int d=dfs(i,j+1,n,m,grid);
        return 1+a+b+c+d;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int res=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    int area=dfs(i,j,n,m,grid);
                    res=max(res,area);
                }
                
            }
        }
        return res;

        
        
    }
};
