/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: HeapSort
* @desc:
    # first building max-heap
    # then largest element is present at first index, hence swap top & last element
    # then heapify() again with array size n-1
    # repeat till all all elements gets consumed
* @TC: O(nlogn)
* 
*/

#include<bits/stdc++.h>
using namespace std;

template <typename T>
void print(T &&t)  { cout << t << "\n"; }
template <typename T, typename... Args>
void print(T &&t, Args &&... args)
{   cout << t << " ", print(forward<Args>(args)...); }
#define _print(v) for(auto i:(v)) cout<<i<<" "; cout<<"\n";
#define fs  first
#define sc  second
#define pb  push_back
#define int long long

void heapify(int arr[], int n, int i){
    int largest = i;
    int l = 2*i+1;
    int r = 2*i+2;
    if(l < n && arr[largest] < arr[l]){
        largest = l;
    }
    if(r < n && arr[largest] < arr[r]){
        largest = r;
    }

    if(largest != i){
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void build_heap(int arr[], int n){

    int st = n/2-1;

    for(int i = st; i >= 0; i--){
        heapify(arr, n, i);
    }

}

void print_heap(int arr[], int n){  

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
}

// O(nlogn)
int heap_sort(){
    int arr[] = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    build_heap(arr, n);
    for(int i = n-1; i > 0; i--){
        swap(arr[i], arr[0]);
        heapify(arr, i, 0);
    }

    print_heap(arr, n);
    
    return 0;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    heap_sort();
}