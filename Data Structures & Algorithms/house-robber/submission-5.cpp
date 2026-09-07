class Solution {
public:
    int rob(vector<int>& nums) {
        int prev2=0;
        int prev1=0;
        for(auto it:nums)
        {
            int curr=max(it+prev2,prev1);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;

        
    }
};
