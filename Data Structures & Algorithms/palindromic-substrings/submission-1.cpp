class Solution {
public:
    int countSubstrings(string s) {
        //take every char as center and see no of palindromes are possible
        //by keeping it as center
        int res=0;
        int n=s.size();
        for(int i=0;i<s.size();i++)
        {
            //odd palindrome by keeping one char as center
            int l=i,r=i;
            while(l>=0&&r<n&&s[l]==s[r])
            {
                res++;
                l--;r++;
            }
            //even palindrome
            l=i;r=i+1;
            while(l>=0&&r<n&&s[l]==s[r])
            {
                res++;
                l--;r++;
            }


        }
        return res;
        //this will be O(n^2) Time 
        
    }
};
