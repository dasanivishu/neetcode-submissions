class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1,r=*max_element(piles.begin(),piles.end());
        int res=r;
        while(l<=r)
        {
            int k=l+(r-l)/2;
            int total_time=0;
            for(auto p:piles)
            total_time+=(p+k-1)/k;
            if(total_time<=h)
            {
                res=k;
                r=k-1;
            }
            else
            {
                l=k+1;
            }
        }
        return res;
        
    }
};
