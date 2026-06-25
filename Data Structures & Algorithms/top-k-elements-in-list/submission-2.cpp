class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //bucket sort algo
        int n=nums.size();
        vector<int>ans;
       unordered_map<int,int>mp;
       for(auto it:nums)
       mp[it]++;
       vector<vector<int>>bucket(n+1);
       for(auto it:mp)
       {
        bucket[it.second].push_back(it.first);
       }
       
       for(int i=n;i>=0;i--)
       {
           
           for(auto it:bucket[i])
           {
            ans.push_back(it);
            if(ans.size()==k)
            return ans;
           }

       }
       return ans;
    }
};
