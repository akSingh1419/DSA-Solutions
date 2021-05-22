// Link to Problem: https://leetcode.com/problems/largest-rectangle-in-histogram/

class Solution {
public:
    int largestRectangleArea(vector<int>& v) {
        int n=v.size();
        stack<int> stk;
        int nlea[n],plea[n];
        // Find the next smallest element
        stk.push(0);
        for(int i=1;i<n;i++) {
            while(!stk.empty() && v[i]<v[stk.top()]) {
                nlea[stk.top()]=i;
                stk.pop();
            }
            stk.push(i);
        }
        while(!stk.empty()) {
            nlea[stk.top()]=n;
            stk.pop();
        }
        // Find the previous smallest element
        stk.push(n-1);
        for(int i=n-2;i>=0;i--) {
            while(!stk.empty() && v[i]<v[stk.top()]) {
                plea[stk.top()]=i;
                stk.pop();
            }
            stk.push(i);
        }
        while(!stk.empty()) {
            plea[stk.top()]=-1;
            stk.pop();
        }
        // Calculating the answer by considering all the possibilities
        int ans=0;
        for(int i=0;i<n;i++) {
            int l=plea[i]+1,r=nlea[i]-1;
            ans=max(ans,(r-l+1)*v[i]);
        }
        return ans;
    }
};
