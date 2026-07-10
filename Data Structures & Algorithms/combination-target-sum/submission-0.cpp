class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>res;
        int total=0;
        vector<int>curr;
        dfs(0,nums,curr,total,target,res);
        return res;


        
    }
    void dfs(int i,vector<int>&nums,vector<int>&curr,int total,int target,vector<vector<int>>&res)
    {
        if (total==target)
        {
            res.push_back(curr);
            return;

        }
        if(i>=nums.size() or total>target)
        return;
        curr.push_back(nums[i]);
        dfs(i,nums,curr,total+nums[i],target,res);
        curr.pop_back();
        dfs(i+1,nums,curr,total,target,res);

    }
};
