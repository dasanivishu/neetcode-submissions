class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>>mp;
        vector<vector<string>>ans;
        for(auto it:strs)
        {
            vector<int>freq(26,0);
            for(auto i:it)
            {
                freq[i-'a']++;
            }
            //lets form key
            string s ="";
            for(int i=0;i<26;i++)
            {
                s+=','+to_string(freq[i]);
            }
            mp[s].push_back(it);
        }
        for(auto &pair: mp)
        {
            ans.push_back(pair.second);
        }

        return ans;
    }
};
