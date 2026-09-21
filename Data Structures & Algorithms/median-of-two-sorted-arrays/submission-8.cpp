class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(),n=nums2.size();
        int total=m+n;
        if(m>n)
        swap(nums1,nums2);
        int half=(total+1)/2;
        int l=0,r=nums1.size();
        while(l<=r)
        {
            int i=l+(r-l)/2;//how many elements in A half and B half 
            int j=half-i;
            int Aleft=i>0?nums1[i-1]:INT_MIN;
            int Aright=i<nums1.size()?nums1[i]:INT_MAX;
            int Bleft=j>0?nums2[j-1]:INT_MIN;
            int Bright=j<nums2.size()?nums2[j]:INT_MAX;
            if(Aleft<=Bright && Bleft<=Aright)
            {
                if(total%2!=0)
                return max(Aleft,Bleft);
                return (max(Aleft,Bleft)+min(Aright,Bright))/2.0;
            }
            else if(Aleft>Bright)
            r=i-1;
            else
            l=i+1;
           

        }
        return -1;

    }
};
