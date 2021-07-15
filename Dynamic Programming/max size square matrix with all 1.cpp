// Manish Kumar, IIIT Allahabad
// Easy
// Time Complexity : O(mn)
// Space Complexity : O(mn)

https://practice.geeksforgeeks.org/problems/largest-square-formed-in-a-matrix0806/1#

int maxSquare(int n, int m, vector<vector<int>> mat){
        int dp[n][m];
        for(int i = 0; i < m; i++)
            dp[0][i] = (mat[0][i] == 1) ? 1 : 0;
        for(int i = 0; i < n; i++){
            dp[i][0] = (mat[i][0] == 1) ? 1 : 0;
        }
        
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++)
                if(mat[i][j] == 1)
                    dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j]));
                else
                    dp[i][j] = 0;
        }
        
        int maxSize = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                maxSize = max(maxSize, dp[i][j]);
            }
        }
        
        return maxSize;
    }