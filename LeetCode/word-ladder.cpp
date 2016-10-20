class Solution {
public:
    //at each position in s, change a single char and add to result
    // if it is in the dictionary
    vector<string> getNeighbours(string s, unordered_set<string>& wordList) {
        vector<string> result;
        string t = s;
        int len = s.length();
        for(int i=0; i<len; i++) {
            t = s;
            for(int j=0; j<25; j++) {
                t[i] = 'a'+j;
                if(wordList.find(t) != wordList.end())
                    result.push_back(t);
            }
        }
        
        return result;
    }
    // typical BFS with depth as another variable in each entry
    // key of the problem is to find the neighbors effectively
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        queue<pair<string, int>> q;
        int depth=1;
        q.push(make_pair(beginWord, 1));
        wordList.erase(beginWord);                      // VERY IMPORTANT FOR SPEED
        while(!q.empty()) {
            string current = q.front().first;
            int depth = q.front().second;
            q.pop();
            //found the desired word
            if(current==endWord)
                return depth;
            vector<string> neighbours = getNeighbours(current, wordList);
            for(string s : neighbours) {
                q.push(make_pair(s, depth+1));
                wordList.erase(s);                      // VERY IMPORTANT FOR SPEED
            }
        }
        return 0;
    }
};
