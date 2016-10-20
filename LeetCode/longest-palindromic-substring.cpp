class Solution {
public:
    string expandAroundCenter(int l, int r, string s){
        int len = s.length();
        while(l>=0 && r<len && s[l]==s[r]){
            l--;
            r++;
        }
        return s.substr(l+1, r-l-1);
    }

    string longestPalindrome(string s) {
        if(s.length()==0 || s.length()==1) return s;
        string max, sub;
        for(int i=0; i<s.length()-1; i++){
            sub = expandAroundCenter(i, i, s);
            if(sub.length() > max.length())
                max = sub;
            sub = expandAroundCenter(i, i+1, s);
            if(sub.length() > max.length())
                max = sub;
        }
        return max;
    }
};
