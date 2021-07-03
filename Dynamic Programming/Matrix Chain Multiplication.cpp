// Manish Kumar, IIIT Allahabad
// Hard
// Time Complexity : O(n^3)
// Space Complexity : O(n^2)

int dp[101][101];
    int mcm(int st, int en, int arr[]){
        if(st >= en)
            return 0;
            
        if(dp[st][en] != -1)
            return dp[st][en];
            
        int mn = INT_MAX;
        for(int k = st; k <= en-1; k++){
            int left = mcm(st, k, arr);
            int right = mcm(k+1, en, arr);
            int cost = arr[st-1]*arr[k]*arr[en];
            mn = min(cost+left+right, mn);
        }
        
        return dp[st][en] = mn;
    }

    int matrixMultiplication(int N, int arr[])
    {
        memset(dp, -1, sizeof(dp));
        return mcm(1, N-1, arr);
    }