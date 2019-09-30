#include <array>
#include <bitset>
#include <deque>
#include <map>
#include <queue>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
#define U(v) cerr << #v << ": " << (v) << endl

int main() {
    int K;
    cin >> K;
    vector<int> a(K);
    for (int& i : a) cin >> i;
    reverse(a.begin(), a.end());
    if (a[0] != 2) {
        cout << -1 << endl;
        return 0;
    }
    long long beg = 2;
    long long end = 4;
    for (int i = 1; i < K; ++i) {
        long long p = beg;
        if (beg % a[i])
            p = beg + a[i] - beg % a[i];
        long long q = end;
        if (end % a[i])
            q = end + a[i] - end % a[i];
        if (p < end) {
            beg = p;
            end = q;
        } else {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << beg << ' ' << end - 1 << endl;
    return 0;
}