class Solution {
public:
    vector<int>dp;//dp[i]=no of ways to decode from that index to last
    int numDecodings(string s) {
        dp.resize(s.size()+1,-1);
        return dfs(s,0);
        
    }
    int dfs(string s,int i)
    {
        if(i==s.size())
        return 1;
        if(s[i]=='0')
        return 0;
        if(dp[i]!=-1)return dp[i];
        int res=dfs(s,i+1);
        if(i+1 <s.size() && (s[i]=='1' || (s[i]=='2' && s[i+1]<'7')))
        res+=dfs(s,i+2);
        return dp[i]=res;
    }
};
