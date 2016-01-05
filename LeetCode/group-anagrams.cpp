class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> m;
        vector<vector<string>> result;
        for(string s : strs)
        {
            string t=s;
            sort(t.begin(),t.end());
            m[t].push_back(s);
        }
        for(auto i = m.begin(); i != m.end(); i++)
        {
            sort((i->second).begin(),(i->second).end());
            result.push_back(i->second);
        }
        return result;
    }
};
