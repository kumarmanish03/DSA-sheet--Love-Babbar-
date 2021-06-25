// Manish Kumar, IIIT Allahabad
// Easy
// Time Complexity : O(n)
// Space Complexity : O(1)

https://practice.geeksforgeeks.org/problems/ncr1019/1#

long long int binExp(long long int a, long long int b, long long m){
        a %= m;
        long long res = 1;
        while(b > 0){
            if(b & 1)
                res = res * a % m;
            a = a * a % m;
            b >>= 1;
        }
        
        return res;
    }

    int nCr(int n, int r){
        long long int m = 1000000007;
        
        if(r > n)
            return 0;
        
        if(r > n-r)
            r = n-r;
        
        long long int res = 1;
        for(long long int i = 1; i <= r; i++){
            res = (res * (n-i+1)) % m;
            res = res * binExp(i, m-2, m) % m;
        }
        
        return res;
    }