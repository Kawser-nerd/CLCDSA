#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstdlib>
#include <cmath>

using namespace std;

int gcd(int a, int b);

int main(void){
    int N, X;
    vector <int> x, y;
    int sub;
    int ans;
    
    cin >> N >> X;
    for(int i = 0; i < N; i++){
        cin >> sub;
        x.push_back(sub);
        y.push_back(abs(X - sub));
    }
    
    sort(y.begin(), y.end());
    
    bool judge = true;
    
    ans = gcd(y[0], y[1]);
    
    for(int i = 2; i < N; i++){
        ans = gcd(ans, y[i]);
    }
    
    cout << ans << "\n";
}

int gcd(int a, int b){
    if(b == 0)      return a;
    
    return gcd(b, a % b);
}