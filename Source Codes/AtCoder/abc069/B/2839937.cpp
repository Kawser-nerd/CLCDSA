#include <iostream>
#include <string>

using namespace std;

int main() {
    string str; cin >> str;
    int n = str.length();
    cout << str[0] << n - 2 << str[n-1] << endl;
    return 0;
}