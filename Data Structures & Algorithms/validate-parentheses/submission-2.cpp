class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(auto it:s)
        {
            if(it=='{'||it=='('||it=='[')
            {
                st.push(it);
            }
            else if(st.empty())
            return false;
            else
            {
                char top_element=st.top();
                if(it=='}' && top_element=='{')
                st.pop();
                else if(it==')' && top_element=='(')
                st.pop();
                else if(it==']' && top_element=='[')
                st.pop();
                else
                return false;
            }
        }

        return st.empty()?true:false;

    }
};
