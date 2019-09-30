#include<iostream>
#include <string>
using namespace std;

int main() {
    int w, h;
    cin >> w >> h;
    if (w%16 == 0 && h%9 == 0) cout << "16:9" << endl;
    else cout << "4:3" << endl;
}