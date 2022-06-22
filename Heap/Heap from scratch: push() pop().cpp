/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @desc: Heap push(), pop(), top() function implementation
* @TC: pop() & push(): O(logn);
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

class heap {

    private:
        int *arr;
        int n;

    public:
        heap(){
            arr = new int[1000];
            n = 0;
        }

        void pop(){
            if(n == 0){
                print("Empty!");
                return;
            }

            swap(arr[0], arr[n-1]);
            n--;
            int i = 0;
            while(1){
                int largest = i;
                int l = 2*i+1;
                int r = 2*i+2;
                if(l < n && arr[largest] < arr[l]){
                    largest = l;
                }
                if(r < n && arr[largest] < arr[r]){
                    largest = r;
                }
                
                if(largest == i){
                    break;
                }

                swap(arr[i], arr[largest]);
                i = largest;
            }
        }

        void push(int x){
            n++;
            arr[n-1] = x;

            int i = n-1;
            while(i > 0){
                int parent = (i-1)/2;
                if(arr[i] > arr[parent]){
                    swap(arr[i], arr[parent]);
                    i = parent;
                }
                else{
                    break;
                }
            }
        }


        int top(){  
            return arr[0]; 
        }

        int size(){
            return n;
        }
};

int solve(){
    
    heap *h1 = new heap();

    h1->push(3);
    h1->push(9);
    h1->push(4);
    h1->push(1);

    print(h1->top());

    h1->pop();
    h1->push(8);

    print(h1->top());

    print(h1->size());

    delete h1;

    return 0;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    solve();
}