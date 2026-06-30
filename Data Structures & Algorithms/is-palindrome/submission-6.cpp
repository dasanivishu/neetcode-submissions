class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        int i=0,j=s.size()-1;
        while(i<j)
        {
            while(!isalnum(s[i]))
            i++;
            while(!isalnum(s[j]))
            j--;
            if(i<j&&s[i]!=s[j])
            return false;
            else
            {
                i++,j--;
            }
        }
        return true;
        
    }
};
