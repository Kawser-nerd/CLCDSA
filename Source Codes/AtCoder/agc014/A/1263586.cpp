#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;

int main(void) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a % 2 == 1 || b % 2 == 1 || c % 2 == 1) {
        cout << 0 << endl;
        return 0;
    }
    if (a == b && b == c) {
        cout << -1 << endl;
        return 0;
    }
    int cnt = 0;
    while (a % 2 == 0 && b % 2 == 0 && c % 2 == 0) {
        int ha = a / 2;
        int hb = b / 2;
        int hc = c / 2;
        a = ha + hb;
        b = ha + hc;
        c = hb + hc;
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}