class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
        return 0;
        if(n==1)
        return nums[0];
        return max(rob_helper(nums,0,n-2),rob_helper(nums,1,n-1));
    }
    int rob_helper(vector<int>&nums,int start,int end)
    {
        int prev2=0,prev1=0;
        for(int i=start;i<=end;i++)
        {
            int curr=max(prev2+nums[i],prev1);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
};
