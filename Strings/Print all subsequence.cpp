// Manish Kumar, IIIT Allahabad
// Easy
// Time Complexity : O(2^n)
// Space Complexity : O(1)

https://www.geeksforgeeks.org/print-subsequences-string/

// s.substr(1) return substring from pos 1 to end

void printsubseq(string s, string out){
    if(s.empty()){
        cout << out << "\n";
        return;
    }

    printsubseq(s.substr(1), out + s[0]);
    printsubseq(s.substr(1), out);
}

int32_t main(){
    OJ;
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s = "abcds";
    string out = "";
    
    printsubseq(s, out);
}