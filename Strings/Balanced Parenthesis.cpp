// Manish Kumar, IIIT Allahabad
// Easy
// Time Complexity : O(n)
// Space Complexity : O(n)

https://practice.geeksforgeeks.org/problems/parenthesis-checker2744/1

bool ispar(string x)
    {
        stack<int> s;
        for(auto i : x){
            if(i == '(' || i == '{' || i == '['){
                s.push(i);
            }
            else {
                if(s.empty())
                    return false;
                else{
                    int t = s.top();
                    if(t == '(' and i == ')')
                        s.pop();
                    else if(t == '{' and i == '}')
                        s.pop();
                    else if(t == '[' and i == ']')
                        s.pop();
                    else
                        return false;
                }
            }
        }
        if(s.empty())
            return true;
        else
            return false;
    }