#include <iostream>
using namespace std;

int main(){
    int a, b, c;
    int ans;
    cin >> a >> b >> c;

    if(a == c) ans = b;
    else if(b == c) ans = a;
    else if(a == b) ans = c;
    else ans = 0;

    cout << ans << endl;
    return 0;
}