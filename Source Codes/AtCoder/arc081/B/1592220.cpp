#include <iostream>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s >> s;
    int b = s[0] == s[1];
    int64_t a = b * 3 + 3;
    for(int i = b + 1; i < n; i++)
        b = s[i] == s[i+1] ? b | 2 : ((a *= b ? b : 2) %= 1000000007, b >> 1);
    cout << a << endl;
    return 0;
}