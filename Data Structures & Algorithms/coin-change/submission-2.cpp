class Solution {
public:
    vector<int>dp;

    int solve(vector<int>&coins,int amount)
    {
        if(amount==0)return 0;
        if(amount<0)return 1e9;
        int ans=1e9;
        if(dp[amount]!=-1)return dp[amount];
        for(auto it:coins)
        {
            ans=min(ans,1+solve(coins,amount-it));
        }
        return dp[amount]=ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        dp.resize(amount+1,-1);
        int ans=solve(coins,amount);
        return ans>=1e9?-1:ans;
        
    }
};
