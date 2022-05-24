// hash -ve subarray product only and if curr product is +ve then try 
// to maximize and if -ve then divide it with max -ve subarray product and try to maximize it 

long long maxProduct(vector<int> arr, int n) {
	    long long ans = -100000;
	    set<long long> s;
	    long long curr = 1;
	    for(int i = 0; i < n; i++){
	        if(arr[i] == 0){
	            ans = max(ans, 0LL);
	            s.clear();
	            curr = 1;
	        }
	        else{
	            curr *= arr[i];
	            ans = max(ans, curr);
	            if(!s.empty()){
	                ans = max(ans, curr / *s.rbegin());
	            }
	            if(curr < 0){
	                s.insert(curr);
	            }
	        }
	    }
	    return ans;
	}