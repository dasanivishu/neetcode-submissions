class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>check;
        for(int i=0;i<nums.size();i++)
        {
            if(check.find(target-nums[i])!=check.end())
            {
                return {check[target-nums[i]],i};
            }
            check[nums[i]]=i;
        }
        return {-1,-1};
    }
};
