// Manish Kumar, IIIT Allahabad
// Easy
// Time Complexity : O(n)
// Space Complexity : O(1)

https://practice.geeksforgeeks.org/problems/count-the-reversals0401/1

int countRev (string x)
{
    stack<int> s;
    int ans = 0;
    for(auto i : x){
        if(i == '{')
            s.push(i);
        else {
            if(s.empty())
                s.push(i);
            else
                if(s.top() == '{')
                    s.pop();
                else
                    s.push(i);
        }
    }
    
    if(s.size()%2==1) return -1;
    
    x = "";
    while(!s.empty()){
        x.push_back(s.top());
        s.pop();
    }
    
    for(auto i: x){
        if(s.empty()){
            s.push(i);
        } else {
            if(i != s.top()){
                ans+=2;
                s.pop();
            }else{
                ans++;
                s.pop();
            }
        }
    }
    
    return ans;
}