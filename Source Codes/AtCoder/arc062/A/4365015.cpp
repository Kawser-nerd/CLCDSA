#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
typedef unsigned int uint;
using namespace std;

int main() {
    int n;
    cin >> n;
    ll T = 1LL, A = 1LL;
    for (int i = 0; i < n; i++) {
        ll t, a;
        cin >> t >> a;
        ll n = max(T / t + (T % t > 0), A / a + (A % a > 0));
        T = n * t;
        A = n * a;
    }

    cout << T + A << "\n";
    return 0;
}