#include<iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    string a, b, c;
    cin >> a >> b >> c;
    a = toupper(a[0]);
    b = toupper(b[0]);
    c = toupper(c[0]);
    cout << a << b << c << endl;
}