#include<string>

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int result=0;
        for(string token : tokens)
        {
            if(token=="+" || token=="-" || token=="*" || token=="/")
            {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                int result;
                
                if(token=="+")
                    result = a+b;
                else if(token=="-")
                    result = b-a; 
                else if(token=="*")
                    result = a*b; 
                else if(token=="/")
                    result = b/a;
                    
                st.push(result);
            }
            else
            {
                st.push(stoi(token));
            }
        }
        return st.top();
    }
};
