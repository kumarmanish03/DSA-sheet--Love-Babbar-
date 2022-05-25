/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://practice.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1#
* @desc: Solution 1 [best solution]
*
*/

// Solution 1: Try to calculate for each index the water trap above it

#include <bits/stdc++.h> 
long getTrappedWater(long *arr, int n){
    vector<long> left(n, 0), right(n, 0);
    left[0] = arr[0];
    right[n-1] = arr[n-1];
    for(int i = 1; i < n; i++){
        left[i] = max(arr[i], left[i-1]);
    }
    for(int i = n-2; i >= 0; i--){
        right[i] = max(arr[i], right[i+1]);
    }
    
    long ans = 0;
    for(int i = 1; i < n-1; i++){
        ans += max(0L, min(left[i-1], right[i+1]) - arr[i]);
    }
    return ans;
}


// Solution 2: Using next greater and previous greater precomputation
class Solution{
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

