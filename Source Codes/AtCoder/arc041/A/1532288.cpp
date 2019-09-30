#include <iostream>
using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    if(b >= c) cout << a + c << endl;
    else cout << a + 2 * b - c << endl;
    return 0;
}