class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //use kadane algo track everytime currmax and currmin
        int res=nums[0];
        int currmin=1,currmax=1;
        for(int num:nums)
        {
            int tmp=currmax*num;
            currmax=max(max(tmp,num*currmin),num);
            currmin=min(min(tmp,num*currmin),num);
            res=max(res,currmax);
        }
        return res;
        
    }
};
