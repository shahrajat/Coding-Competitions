class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0)
            return "";
        else if(strs.size()==1)
            return strs[0];
        
        string prefix="";
        int len = INT_MAX;
        for(string s: strs)
            if(s.length() < len)
                len = s.length();
        for(int i=0; i <len; i++)
        {
            bool matched = true;
            char current = strs[0][i];
            for(string s: strs)
            {
                if(s[i]!=current)
                {
                    matched = false;
                    break;   
                }
            }
            if(matched)
                prefix += current;
            else
                break;
        }
        return prefix;
    }
};
