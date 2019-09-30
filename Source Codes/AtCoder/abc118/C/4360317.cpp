//
// Created by Suganami Shuya on 2019-02-18.
//
#include <iostream>

using namespace std;


int n;
long token;

long calc_Gcd(long x, long y) {
    long tmp;
    if (x < y) {
        tmp = x;
        x = y;
        y = tmp;
    }
    tmp = x % y;
    if (tmp) {
        return calc_Gcd(y, tmp);
    } else {
        return y;
    }
}

void solve() {
    cin >> n;
    long hp[n];
    for (int i = 0; i < n; i++) {
        cin >> hp[i];
    }
    token = calc_Gcd(hp[0], hp[1]);
    for (int j = 2; j < n; j++) {
        token = calc_Gcd(hp[j], token);
    }
    cout << token << endl;
}

int main() {
    solve();
    return 0;
}