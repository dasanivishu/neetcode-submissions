class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_string="";
        for(auto it: strs)
        {
            int n=it.size();
            encoded_string+=to_string(n)+"#";
            encoded_string+=it;
        }
        return encoded_string;

    }

    vector<string> decode(string s) {
        vector<string>decoded_strings;
        int i=0;
        while(i<s.size())
        {
            int j=i;
            while(s[j]!='#')
            {
                j++;
            }
            int sz=stoi(s.substr(i,j-i));
            //extract word
            string word=s.substr(j+1,sz);
            decoded_strings.push_back(word);

            i=j+1+sz;
        }
        return decoded_strings;
    }
};
