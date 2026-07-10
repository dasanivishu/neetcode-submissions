class Solution {
public:
    
    vector<vector<int>>res;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        
        
        vector<int>curr;
        dfs(0,nums,curr,target);
        return res;


        
    }
    void dfs(int i,vector<int>&nums,vector<int>&curr,int target)
    {
        if (target==0)
        {
            res.push_back(curr);
            return;

        }
        if(i>=nums.size() or target<0)
        return;
        curr.push_back(nums[i]);
        dfs(i,nums,curr,target-nums[i]);
        curr.pop_back();
        dfs(i+1,nums,curr,target);

    }
};

// time complexity : O(2^Target/m) m -min element bcoz T/m will be height of recursion tree
// everytime to prevent duplicates one side what element we have taken we will not take on left side as we want combinatiions not permutations and height of recursion tree can be target/m
// space complexity : will be O(Target/m) as in recursion stack there will be max this much element