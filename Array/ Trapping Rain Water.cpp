/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://practice.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1#
* @topic: Using next greater and previous greater precomputation
*
*/


class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        vector<int> nG(n, -1), pG(n, -1);
        stack<int> s;
        for(int i = 0; i < n; i++){
            while(!s.empty() && arr[s.top()] <= arr[i]){
                nG[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        
        while(!s.empty()) s.pop();
        
        for(int i = n-1; i >= 0; i--){
            while(!s.empty() && arr[s.top()] <= arr[i]){
                pG[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        
        vector<long long> v(n, 0);
        v[0] = 1LL * arr[0];
        for(int i = 1; i < n; i++){
            v[i] = v[i-1] + 0LL + arr[i];
        }
        
        long long ans = 0;
        int i = 0;
        while(i < n){
            if(nG[i] == -1){
                break;
            }
            ans += (nG[i] - i-1) * 1LL * arr[i]; 
            ans -= v[nG[i] -1] - v[i];
            i = nG[i];
        }
        
        if(i < n-1){
            int j = i;
            i = n-1;
            while(i >= 0){
                if(pG[i] == -1){
                    break;
                }
                ans += (i - pG[i]-1) * 1LL * arr[i]; 
                ans -= v[i -1] - v[pG[i]];
                i = pG[i];
                if(i == j){
                    break;
                }
            }
        }
        
        return ans;
    }
};
