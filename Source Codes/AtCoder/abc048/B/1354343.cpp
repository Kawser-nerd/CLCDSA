#include <iostream>
using namespace std;
using ull = unsigned long long;
 
int main(){
    ull a, b, x, ans = 0;
    cin >> a >> b >> x;
    if(a == 0){ ans = b / x + 1; }
    else{
        ans = b / x - (a - 1) / x;
    }
 
    cout << ans << endl;
 
    return 0;
}