class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>freq1(26,0),freq2(26,0);
        for(auto it:s)
        freq1[it-'a']++;
        for(auto it:t)
        freq2[it-'a']++;
        return freq1==freq2;
    }
};
