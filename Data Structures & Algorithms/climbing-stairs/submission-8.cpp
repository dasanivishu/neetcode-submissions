class Solution {
public:
    vector<int>dp;
    int climbStairs(int n) {
        dp.resize(n+1,-1);
        return climbStairs_helper(n);
    }
    int climbStairs_helper(int i)
    {
        if(i<=2)
        return dp[i]=i;
        if(dp[i]!=-1)return dp[i];
        return dp[i]=climbStairs_helper(i-1)+climbStairs_helper(i-2);
    }
};
