#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <vector>

using namespace std;
using ull = unsigned long long;
using P = pair<int, int>;


ull E = 1000000007;

int a[100];

int main() {
    int N;
    cin >> N;
    int sum = 0;
    for (int n = 0; n < N; ++n) {
        cin >> a[n];
        sum += a[n];
    }
    if (sum % N != 0) {
        cout << -1 << endl;
        return 0;
    }
    int ans = 0;
    for (int i = 0; i < N - 1; ++i) {
        int lsum = 0;
        for (int l = 0; l <= i; ++l) {
            lsum += a[l];
        }
        lsum /= (i + 1);
        int rsum = 0;
        for (int r = i + 1; r < N; ++r) {
            rsum += a[r];
        }
        rsum /= (N - i - 1);
        if (lsum != rsum) {
            ++ans;
        }
    }
    cout << ans << endl;
}