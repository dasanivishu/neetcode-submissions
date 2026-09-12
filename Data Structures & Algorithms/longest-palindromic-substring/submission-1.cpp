class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        int reslen=0,residx=0;
        for(int i=0;i<n;i++)
        {
            //odd length palindrome from its centre
            int l=i,r=i;
            while(l>=0&&r<n&&s[l]==s[r])
            {
                if(r-l+1>reslen)
                {
                    reslen=r-l+1;
                    residx=l;
                }
                l--;
                r++;
            }
            l=i,r=i+1;
            while(l>=0&&r<n&&s[l]==s[r])
            {
                if(r-l+1>reslen)
                {
                    reslen=r-l+1;
                    residx=l;
                }
                l--;
                r++;
            }

        }
        return s.substr(residx,reslen);
    }
};
