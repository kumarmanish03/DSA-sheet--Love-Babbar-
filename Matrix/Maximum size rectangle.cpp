/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://practice.geeksforgeeks.org/problems/max-rectangle/1#
* @desc: applying concept of 'max area histogram ques' for each row
* @TC: O(nlogn)
*
*/

class Solution{
  public:
  int largestRectangleArea(int ht[], int n) {
        vector<int> left(n, -1), right(n, n);
        stack<int> st;
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && ht[i] < ht[st.top()]){
                left[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        
        while(!st.empty()) st.pop();
        
        for(int i = 0; i < n; i++){
            while(!st.empty() && ht[i] < ht[st.top()]){
                right[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++){
            // cout << left[i] << " " << right[i] << "\n";
            int curr = (right[i] - left[i] - 1) * ht[i];
            ans = max(ans, curr);
        }
        return ans;
    }
  
    int maxArea(int a[MAX][MAX], int n, int m) {
        int ans = 0;
        
        for(int i = 1; i < n; i++){
            for(int j = 0; j < m ; j++){
                if(a[i][j] == 1)
                    a[i][j] += a[i-1][j];
            }
        }
        
        for(int i = 0; i < n; i++){
            ans = max(ans, largestRectangleArea(a[i], m));
        }
        return ans;
    }
};