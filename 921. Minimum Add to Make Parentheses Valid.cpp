// Link to Problem: https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/

class Solution {
public:
    int minAddToMakeValid(string S) {
        stack<char> st;
        int ans=0;
        for(char c:S) {
            if(c=='(') {
                st.push(c);
            } else {
                if(!st.empty()) {
                    st.pop();
                } else {
                    ans++;
                }
            }
        }
        ans+=st.size();
        return ans;
    }
};
