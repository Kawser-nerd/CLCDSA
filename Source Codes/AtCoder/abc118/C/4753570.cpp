#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> L;

int gcd(int a, int b){
    if(b == 0) return a;
    
    return gcd(b, a % b);
    
}

int solve(int i, int res, int next){
    if (i == n) return res;

    return solve(i+1, gcd(res, next) , L[i+1]);
}


int main(void){
    // Your code here!
    cin >> n;
    L.resize(n);
    
    for(int i = 0; i < n; i++){
        cin >> L[i]; 
    }
    
    cout << solve(0, L[0], L[0]) << endl;
    
}