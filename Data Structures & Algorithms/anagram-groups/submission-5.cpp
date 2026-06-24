class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>res;
        unordered_map<string,vector<string>>mp;
        string pattern;
        for(auto it:strs)
        {
            pattern="";
            vector<int>freq(26,0);
            for(auto i:it)
            freq[i-'a']++;
            for(int i:freq)
            pattern+=i+'0';
            mp[pattern].push_back(it);
            
        }
        for(auto m:mp)
        {
            res.push_back(m.second);
        }
        return res;
    }
};
