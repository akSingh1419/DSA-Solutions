// Link to Problem: https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/

class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++) {
            if(s[i]=='(') {
                st.push('(');
            } else if(s[i]==')') { 
                string str;
                while(!st.empty() && st.top()!='(') {
                    str+=st.top();
                    st.pop();
                }
                st.pop();
                for(auto it:str) {
                    st.push(it);
                }
            } else {
                st.push(s[i]);
            }
        }
        string ans="";
        while(!st.empty()) {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
