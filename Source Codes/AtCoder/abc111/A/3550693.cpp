#include <iostream>
#include <string>
using namespace std;

int main() {
    string st; cin >> st;
    for(int i = 0; i < 3; i++) {
        if(st[i] == '1') {
            cout << 9;
        } else {
            cout << 1;
        }
    }
    cout << endl;
}