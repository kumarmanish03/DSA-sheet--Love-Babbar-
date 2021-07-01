// Manish Kumar, IIIT Allahabad
// Easy
// Time Complexity : O(n! * n)
// Space Complexity : O(n! * n)

https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1#

string permute = "";
	    string s;
	    void permutations(int n, vector<bool> &chosen, vector<string> &res){
	        if(permute.size() == n){
	            res.push_back(permute);
	            return;
	        }
	        
	        for(int i = 0; i < n; i++){
	            if(chosen[i]) continue;
	            chosen[i] = true;
	            permute.push_back(s[i]);
	            permutations(n, chosen, res);
	            chosen[i] = false;
	            permute.pop_back();
	        }
	    }
	
		vector<string>find_permutation(string S)
		{
		    s = S;
		    vector<string> res;
		    int n = S.size();
		    vector<bool> chosen(n, 0);
		    permutations(n, chosen, res);
		    sort(res.begin(), res.end());
		    return res;
		}