/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://practice.geeksforgeeks.org/problems/check-mirror-in-n-ary-tree1528/1#
* @TC: O(N)
* @desc: we will just check the child nodes are in reverse order of two trees or not
*
*/

int checkMirrorTree(int n, int e, int A[], int B[]) {
        unordered_map<int, vector<int>> adj1;
        unordered_map<int, vector<int>> adj2;
        for(int i = 0; i < 2*e; i+=2){
            adj1[A[i]].push_back(A[i+1]);
            adj2[B[i]].push_back(B[i+1]);
        }
        
        for(auto i: adj1){
            reverse(i.second.begin(), i.second.end());
            if(i.second != adj2[i.first])
                return false;
        }
        
        return true;
    }