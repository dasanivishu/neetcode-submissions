class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int>s;
        for(auto it:nums)
        {
            if(s.count(it)>0)
            return true;
            s.insert(it);
        }
        return false;
    }
};