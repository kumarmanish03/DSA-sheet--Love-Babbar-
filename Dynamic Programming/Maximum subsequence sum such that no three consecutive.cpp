// Manish Kumar, IIIT Allahabad
// Medium
// Time Complexity : O(n)
// Space Complexity : O(n)

// See tricky condn line:22 

https://www.geeksforgeeks.org/maximum-subsequence-sum-such-that-no-three-are-consecutive/

int findSum(vector<int> A, int N){
  // sum[i] is the max sum st no 3 consecutive
  int sum[N];

  if(N >= 1)
    sum[0] = arr[0];
  if(N >= 2)
    sum[1] = arr[0] + arr[1];
  if(N >= 3)
    sum[2] = max(sum[1], max(arr[0] + arr[2], arr[1] + arr[2]));

  for(int i = 3; i < N; i++){
    sum[i] = max(sum[i-1], max(sum[i-2] + arr[i], sum[i-3] + arr[i-1] + arr[i]));
  }

  return sum[n-1];

}

