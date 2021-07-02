// Manish Kumar, IIIT Allahabad
// Hard
// Time Complexity : O((n+m)log(n+m)) & O(n*m)
// Space Complexity : O(1)

// Soln 1 
// TC : (n+m)log(n+m);
// Optimized

void merge(int arr1[], int arr2[], int n, int m) {
	   int i = 0;
	   int j = 0;
	   int k = n-1;
     // Sending all less elemtns to arr1 and greater to arr2
	   while(j < m and i <= k){
	       if(arr1[i] > arr2[j]){
	           swap(arr1[k], arr2[j]);
	           j++;
	           k--;
	       }
	       else {
	           i++;
	       }
	   }
	   sort(arr1, arr1+n);
	   sort(arr2, arr2+m);
	}


// Soln 2
// TC: O(n*m)

  void merge(int arr1[], int arr2[], int n, int m) {
	   int i = n-1;
	   int j = m-1;
	   while(j >= 0){
	       if(arr1[i] > arr2[j]){
	           swap(arr1[i], arr2[j]);
	           int k = i-1;
	           int t = i;
	           while(k >= 0 and arr1[k] > arr1[t]){
	               swap(arr1[k], arr1[t]);
	               k--;
	               t--;
	           }
	           i = n-1;
	           j--;
	       }
	       else{
	           j--;
	       }
	   }
	}