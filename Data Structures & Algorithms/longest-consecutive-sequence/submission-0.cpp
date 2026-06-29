class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto it:nums)
        mp[it]++;
        int lc=0;
        for(auto it:nums)
        {
            if(mp[it+1]==0)
            {
                int cnt=0;
                while(mp[it--]!=0)
                cnt++;
                lc=max(lc,cnt);
            }
        }
        return lc;
    }
};
