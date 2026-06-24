class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        unordered_map<string,vector<string>>mp;
        for(auto it:strs)
        {
            //first we will form key
            vector<int>freq(26,0);
            string key="";
            for(auto ch:it)
            {
                freq[ch-'a']++;
            }
            for(auto fq:freq)
            {
                key+=fq;
                key+=',';
            }
            mp[key].push_back(it);
            
        }
        for(auto it:mp)
        {
            ans.push_back(it.second);
        }
        return ans;
        
    }
};
