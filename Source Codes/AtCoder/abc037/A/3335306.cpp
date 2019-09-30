#include<iostream>
#include <string>
using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    if (a<b) cout << c/a + (c%a)/b << endl;
    else cout << c/b + (c%b)/a << endl;
}