#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, k;
vector<int> T;
int main(void){
    // Your code here!
    cin >> n >> k;
    T.resize(n);
    for(int i = 0; i < n; i++){
        cin >> T[i];
    }
    
    sort(T.begin(), T.end());
    
    int s = 0;
    int l = k-1;
    int diff = 1000000001;
    while(l < n){
        if(T[l] - T[s] < diff){
            diff = T[l] - T[s];
        }
        s++;
        l++;
        
    }
    
    cout << diff << endl;
    
    
    
}