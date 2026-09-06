class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>words(wordList.begin(),wordList.end());
        if(!words.count(endWord))return 0;
        queue<string>q;
        q.push(beginWord);
        words.erase(beginWord);
        int level=0;
        while(!q.empty())
        {
            int n=q.size();
            level++;
            for(int ele=0;ele<n;ele++)
            {
            string node=q.front();
            q.pop();
            if(node==endWord)return level;
            for(int i=0;i<node.size();i++)
            {
                char orig=node[i];
                for(char c='a';c<='z';c++)
                {
                    node[i]=c;
                    if(words.count(node))
                    {
                        q.push(node);
                        words.erase(node);
                    }
                
                }
                node[i]=orig;
            }
            }

        }
        return 0;

        
        
    }
};
