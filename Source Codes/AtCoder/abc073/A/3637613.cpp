#include <iostream>
#include <string>
using namespace std;

int main() {
    string st; cin >> st;
    if(st[0] == '9' || st[1] == '9') {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}