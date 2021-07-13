// Manish Kumar, IIIT Allahabad
// Easy
// Time Complexity : O(n*m)
// Space Complexity : O(n*m)

// Simple Knapsack

https://practice.geeksforgeeks.org/problems/gold-mine-problem2608/1

int fun(int x, int y, vector<vector<int>> &M){
      if(y == M[0].size()){
        return 0;
      }
    
      int a = M[x][y] + fun(x, y+1, M);
      int b = INT_MIN;
      int c = INT_MIN;
      if(x > 0)
        b = M[x][y] + fun(x-1, y+1, M);
      if(x < M.size()-1)
        c = M[x][y] + fun(x+1, y+1, M);
        
        return max(a, max(b, c));
    }
    
    int maxGold(int n, int m, vector<vector<int>> M){
        int maxSum = INT_MIN;
      for(int i = 0; i < M.size(); i++){
          maxSum = max(fun(i, 0, M), maxSum);
      }
      return maxSum;
    }