#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main(void){
    int a, b, c;
    int ans;
    cin >> a >> b >> c;
    if(a == b){
        ans = c;
    }else if(b == c){
        ans = a;
    }else{
        ans = b;
    }
    cout << ans << endl;
    return 0;
}