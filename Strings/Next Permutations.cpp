// Manish Kumar, IIIT Allahabad
// Easy
// Time Complexity : O(n)
// Space Complexity : O(1)

https://practice.geeksforgeeks.org/problems/next-permutation5226/1#

vector<int> nextPermutation(int N, vector<int> arr){
        int idx = -1;
        int target = -1;
        int n = arr.size();
        for(int i = 0; i < arr.size()-1; i++){
            if(arr[i] <= arr[i+1]){
                idx = i;
            }
            if(idx != -1 && arr[idx] < arr[i+1]){
                target = i+1;
            }
        }
        
        if(idx == -1){
            reverse(arr.begin(), arr.end());
            return arr;
        }
        
        swap(arr[idx], arr[target]);
        sort(arr.begin() + idx+1, arr.end());
        return arr;
    }