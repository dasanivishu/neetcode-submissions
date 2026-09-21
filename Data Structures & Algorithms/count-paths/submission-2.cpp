class Solution {
public:
    vector<vector<int>>memo;
    int dfs(int i,int j,int m,int n)
    {
        if(i==m-1 && j==n-1)return 1;
        if(i>=m||j>=n)return 0;
        if(memo[i][j]!=-1)
        return memo[i][j];
        int ways=0;
        ways+=dfs(i+1,j,m,n);
        ways+=dfs(i,j+1,m,n);
        return memo[i][j]=ways;

    }
    int uniquePaths(int m, int n) {
        memo.assign(m,vector<int>(n,-1));
        return dfs(0,0,m,n);
    }
};
