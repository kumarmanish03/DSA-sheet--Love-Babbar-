// Manish Kumar, IIIT Allahabad

// Solution 1: Using Merge sort algo
// Solution 2: Using coordinate compression & Fenwick tree

// Solution 1: O(nlogn)
#include <bits/stdc++.h> 
int a[100005];
long long cnt = 0;
void merge(int l, int mid, int r){
    int b[r-l+1];
    int i = l;
    int j = mid+1;
    int k = 0;
    while(i <= mid && j <= r){
        if(a[i] <= a[j]){
            b[k++] = a[i++];
        }
        else{
            b[k++] = a[j++];
            cnt += 1LL * (mid - i + 1);
        }
    }
    while(i <= mid){
        b[k++] = a[i++];
    }
    while(j <= r){
        b[k++] = a[j++];
    }
    for(int t = l; t <= r; t++){
        a[t] = b[t-l];
    }
}

void mergeSort(int l, int r){
    if(l < r){
        int mid = (l + r) / 2;
        mergeSort(l, mid);
        mergeSort(mid+1, r);
        merge(l, mid, r);
    }
}

long long getInversions(long long *arr, int n){
    for(int i = 0; i < n; i++)
        a[i] = arr[i];
    
    mergeSort(0, n-1);
    
    return cnt;
}


// Solution 2: O(nlogn)
#include <bits/stdc++.h> 
const int N = 1e5+5;
int bit[N];

int sum(int i){
    int cnt = 0;
    for(; i>0; i -= (i & -i)){
        cnt += bit[i];
    }
    return cnt;
}

void update(int i){
    for(; i < N; i += (i & -i)){
        bit[i] += 1;
    }
}

long long getInversions(long long *arr, int n){
    map<int, int> compress;
    for(int i = 0; i < n; i++){
        compress[arr[i]];
    }
    int ind = 1;
    for(auto &i:compress){
        i.second = ind++;
    }
    for(int i = 0; i < n; i++){
        arr[i] = compress[arr[i]];
    }
    
    long long cnt = 0;
    for(int i = 0; i < n; i++){
        cnt += 0LL + i - sum(arr[i]);
        update(arr[i]);
    }
    return cnt;
}