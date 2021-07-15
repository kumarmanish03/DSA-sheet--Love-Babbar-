// Manish Kumar, IIIT Allahabad
// Easy, Greedy
// Time Complexity : O(nlogn)
// Space Complexity : O(n)

https://practice.geeksforgeeks.org/problems/pairs-with-specific-difference1533/1#

int maxSumPairWithDifferenceLessThanK(int arr[], int N, int K)
    {
        sort(arr, arr + N);
        int maxSum = 0;
        for(int i = N-1; i > 0; i--){
            if(arr[i]-arr[i-1] < K){
                maxSum += arr[i] + arr[i-1];
                i--;
            }
        }   
        return maxSum;
    }