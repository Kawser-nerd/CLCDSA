#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string>

using namespace std;


int main() {
    string s; cin >> s;
    int ans = 1000000;
    for (int i = 0; i < s.length() - 2; i++) {
        int a = s[i] - '0';
        int b = s[i + 1] - '0';
        int c = s[i + 2] - '0';
        int x = 100 * a + 10 * b + c;
        ans = min(ans, abs(x - 753));
    }
    // int s; cin >> s;
    // int array[10];
    // int ans = 10000;
    // int nd = log10(s)+1;
    // cout << "nd: " << nd << endl;
    // for (int i = nd; i > 2; i--) {
    //     cout << "i: " << i << endl;
    //     // 3?????
    //     int target = 0;
    //     for (int j = 1; j <= 3; j++) {
    //     int y = pow(10, i - j);
    //     int x = s / y;
    //     cout << "x: " << x << endl;
    //     target += x * pow(10, 2 - j);
    //     }
    //     cout << "target: " << target << endl;
    //     int aa = target - 753;
    //     cout << "aa: " << aa << endl;

    // }
    cout << ans << endl;
    return 0;
}