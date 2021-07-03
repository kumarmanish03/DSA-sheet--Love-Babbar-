// Manish Kumar, IIIT Allahabad
// Easy
// Time Complexity : O(n)
// Space Complexity : O(1)

https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1#

int maxSubarraySum(int arr[], int n){
        
    int curr = 0, mx = INT_MIN;
    for(int i = 0; i < n; i++){
        if(curr < 0){
            curr = 0;
        }
        curr += arr[i];
        mx = max(mx, curr);
    }
        
    return mx;
}