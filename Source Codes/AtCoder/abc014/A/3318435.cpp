#include<iostream>
#include <string>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    if (a==b) cout << 0 << endl;
    else cout << b - a%b << endl;
}