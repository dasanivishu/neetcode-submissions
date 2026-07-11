class Solution {
public:
    string longestPalindrome(string s) {
        //O(n^3)-Brute check every palindrome
        //we will basically optimise it consider every index at center
        // and find palindrome -O(n^2)
        int start=-1;
        int maxlen=0;
        int n=s.size();
        
        for (int i=0;i<s.size();i++)
        {
            //odd palindrome
            int l=i,r=i;
            while(l>=0 && r<n && s[l]==s[r])
            {
                if(r-l+1>maxlen)
                {
                    maxlen=r-l+1;
                    start=l;
                }
                l--;
                r++;
            }
            //even palindrome
            l=i;r=i+1;
            while(l>=0&&r<n&&s[l]==s[r])
            {
                if(r-l+1>maxlen)
                {
                    maxlen=r-l+1;
                    start=l;
                }
                l--;
                r++;
            }
            
        }
        return s.substr(start,maxlen);
        
    }
};
