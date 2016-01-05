class Solution {    
public:
    vector<string> generateParenthesis(int n) {
        set<string> ret;
        if(n==0)
            return vector<string>();
        else if(n==1)
        {
            vector<string> r1;
            r1.push_back("()");
            return r1;
        }
        else
        {
            vector<string>prev = generateParenthesis(n-1);
            for(auto p : prev)
            {
                for(int i=0;i<p.size();i++)
                {
                    if(p[i]=='(')
                    { 
                        string s = p;
                        s.insert(i+1,"()");
                        ret.insert(s);
                    }
                }
                ret.insert("()"+p);
            }
        }
        return vector<string>(ret.begin(),ret.end());
    }
};
