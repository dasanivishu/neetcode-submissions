class Solution {
public:
vector<pair<int,int>>directions={{0,1},{0,-1},{1,0},{-1,0}};
    void dfs(int row,int col,vector<vector<int>>&heights,set<pair<int,int>>&visit)
    {
        visit.insert({row,col});
        for(int i=0;i<4;i++)
        {
            int n_row=row+directions[i].first;
            int n_col=col+directions[i].second;
            if(n_row>=0&& n_row<heights.size() && n_col>=0 && n_col<heights[0].size()&& !visit.count({n_row,n_col})&&heights[n_row][n_col]>=heights[row][col])
            dfs(n_row,n_col,heights,visit);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        set<pair<int,int>>pac,atl;
        vector<vector<int>>res;
        
        for(int col=0;col<m;col++)
        {
            dfs(0,col,heights,pac);
            dfs(n-1,col,heights,atl);
        }
        for(int row=0;row<n;row++)
        {
            dfs(row,0,heights,pac);
            dfs(row,m-1,heights,atl);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(pac.count({i,j})>0 && atl.count({i,j})>0)
                res.push_back({i,j});
            }
        }
        return res;
        
    }
};
