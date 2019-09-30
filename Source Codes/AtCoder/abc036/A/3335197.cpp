#include<iostream>
#include <string>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    if (b%a == 0) cout << b/a << endl;
    else cout << b/a + 1 << endl;
    return 0;
}