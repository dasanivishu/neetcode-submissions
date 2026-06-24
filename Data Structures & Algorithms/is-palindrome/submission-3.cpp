class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.size();
        if(n==0)
        return true;
        int l=0,r=n-1;
        while(l<r)
        {
            while(l<r && !isalnum(s[l]))l++;
            while(l<r && !isalnum(s[r]))r--;

            if(tolower(s[l])!=tolower(s[r]))return false;
            l++,r--;
        }
        return true;
    }
   
};
