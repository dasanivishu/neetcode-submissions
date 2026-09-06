class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {

        unordered_set<string> dictionary(wordList.begin(), wordList.end());

        if (!dictionary.count(endWord))
            return 0;

        queue<string> bfsQueue;
        bfsQueue.push(beginWord);
        dictionary.erase(beginWord);

        int level = 1;

        while (!bfsQueue.empty()) {

            int levelSize = bfsQueue.size();

            for (int i = 0; i < levelSize; i++) {

                string currentWord = bfsQueue.front();
                bfsQueue.pop();

                if (currentWord == endWord)
                    return level;

                for (int pos = 0; pos < currentWord.size(); pos++) {

                    char originalChar = currentWord[pos];

                    for (char ch = 'a'; ch <= 'z'; ch++) {

                        if (ch == originalChar)
                            continue;

                        currentWord[pos] = ch;

                        if (dictionary.count(currentWord)) {
                            bfsQueue.push(currentWord);
                            dictionary.erase(currentWord);
                        }
                    }

                    currentWord[pos] = originalChar;
                }
            }

            level++;
        }

        return 0;
    }
};