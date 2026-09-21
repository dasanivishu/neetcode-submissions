class Solution {
public:
    vector<int>dp;
    int coinChange(vector<int>& coins, int amount) {
        dp.assign(amount+1,-1);
        int minCoins=dfs(coins,amount);
        return minCoins>=1e9?-1:minCoins;
        
    }
    int dfs(vector<int>&coins,int amount)
    {
        if(amount==0)
        return 0;
        if(dp[amount]!=-1)
        return dp[amount];
        int res=1e9;
        for(int i=0;i<coins.size();i++)
        {
            if(amount>=coins[i])
            res=min(res,1+dfs(coins,amount-coins[i]));
        }
        return dp[amount]=res;


    }
};
