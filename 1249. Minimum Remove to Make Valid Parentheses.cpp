// Link to Problem: https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<int> indx(s.size());
        stack<pair<int,char>> st;
        for(int i=0;i<s.size();i++) {
            if(s[i]=='(') {
                st.push({i,'('});
            } else if(s[i]==')') {
                if(!st.empty() && st.top().second=='(') {
                    st.pop();
                } else {
                    indx[i]=-1; //remove this
                } 
            }
        }
        while(!st.empty()) {
            indx[st.top().first]=-1;
            st.pop();
        }
        string ans;
        for(int i=0;i<s.size();i++) {
            if(indx[i]!=-1) ans+=s[i];
        }
        return ans;
    }
};
