// Manish Kumar, IIIT Allahabad

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

// pre[i]: stores max profit earn in 1 transaction 1 till ith day
// -suf[i]: stores max profit earn in 1 transaction from last to ith day
// Then our ans = max(pre[i], -suf[i+1]);
// we also take max from 0, if profit is -ve then we don't consider it

class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size();
        vector<int> pre(n), suf(n);
        pre[0] = 0;
        int mn = p[0];
        int mx = INT_MIN;
        for(int i = 1; i < n; i++){
            mx = max(mx, p[i]-mn);
            pre[i] = mx;
            mn = min(mn, p[i]);
        }
        
        suf[n-1] = 0;
        mn = INT_MAX;
        mx = p[n-1];
        for(int i = n-2; i >= 0; i--){
            mn = min(mn, p[i] - mx);
            suf[i] = mn;
            mx = max(mx, p[i]);
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++){
            int curr = max(pre[i], 0) + max(-suf[i], 0);
            ans = max(curr, ans);
        }
        return ans;
    }
};