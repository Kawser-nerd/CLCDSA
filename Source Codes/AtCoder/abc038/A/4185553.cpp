#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

int main() {

    string s;
    cin >> s;
    if(s.at(s.length() - 1) == 'T') {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}