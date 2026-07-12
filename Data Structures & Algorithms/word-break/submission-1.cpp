class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // memo[i] = true/false means whether s[i:] can be segmented
        int n=s.size();
        vector<bool>dp(n+1,false);
        dp[n]=true;//empty is true
        for(int i=n-1;i>=0;i--)
        {
            for(auto w:wordDict)
            {
                if(i+w.size()<=n && s.substr(i,w.size())==w)
                dp[i]=dp[i+w.size()];
                if(dp[i])
                break;
            }
            
        }
        return dp[0];
        
        
    }
};
