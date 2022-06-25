/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays5135/1#
* @desc: There may be two soln approach: https://www.youtube.com/watch?v=hVl2b3bLzBw&t=1s
    # 1. we can take pointer i for arr1 & j for arr2. if arr1[i] < arr[j] then swap arr[j] to arr1 
    # and place arr[i] in correct place in 2nd array. TC: O(n * m)
    # 2. This method is called gap method in which we swap elements in correct order with a gap and for every gap/2 till 1
    # for more see video
*
* TC: O((n+m)log(n+m))
*/

    void _swap(int i, int j, int arr1[], int arr2[], int n, int m){
        int *k;
        if(i < n){
            k = &arr1[i];
        }
        else{
            k = &arr2[i-n];
        }
        
        int *l;
        if(j < n){
            l = &arr1[j];
        }
        else{
            l = &arr2[j-n];
        }
        
        if(*k > *l)
            swap(*k, *l);
    }

	void merge(int arr1[], int arr2[], int n, int m) {
	    int gap = (n + m + 1) / 2;
	    while(gap){
	        int i = 0;
	        while(1){
    	       if(i+gap >= n+m){
    	            if(gap==1) gap = 0;
    	            gap = (gap+1) / 2;
    	            break;
    	        }
    	        _swap(i, i+gap, arr1, arr2, n, m);
    	        i++;
	        }
	    }
	}
