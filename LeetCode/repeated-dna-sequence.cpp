class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map <string, int> hashTable;
        string current = s.substr(0, 10);
        hashTable[current] = 1;
        vector<string> result;
        for(int i=10; i<s.size();i++)
        {
            current = current.substr(1, current.length());
            current += s[i];
            hashTable[current]++;
        }
        
        for (auto entry : hashTable)
            if(hashTable[entry.first] > 1)
                result.push_back(entry.first);
        return result;
    }
};
