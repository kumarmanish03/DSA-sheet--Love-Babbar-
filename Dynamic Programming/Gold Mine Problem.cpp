// Manish Kumar, IIIT Allahabad
// Easy
// Time Complexity : O(n*m)
// Space Complexity : O(n*m)

// Simple Knapsack

https://practice.geeksforgeeks.org/problems/gold-mine-problem2608/1

 int dp[55][55];

    int fun(int x, int y, vector<vector<int>> &M){
      if(y == M[0].size()){
        return 0;
      }
      
      if(dp[x][y] != -1){
          return dp[x][y];
      }
    
      int a = M[x][y] + fun(x, y+1, M);
      int b = INT_MIN;
      int c = INT_MIN;
      if(x > 0)
        b = M[x][y] + fun(x-1, y+1, M);
      if(x < M.size()-1)
        c = M[x][y] + fun(x+1, y+1, M);
        
        return dp[x][y] = max(a, max(b, c));
    }
    
    int maxGold(int n, int m, vector<vector<int>> M){
        int maxSum = INT_MIN;
        memset(dp, -1, sizeof(dp));
      for(int i = 0; i < M.size(); i++){
          dp[i][0] = fun(i, 0, M);
          maxSum = max(dp[i][0], maxSum);
      }
      return maxSum;
    }