// {{{
#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
// }}}

using namespace std;

using ll [[maybe_unused]] = long long;
using ull [[maybe_unused]] = unsigned long long;
using ld [[maybe_unused]] = long double;

#define rep(i, n) for (ll i = 0; i < n; ++i)
#define pb push_back
#define fst first
#define snd second


int main() {
    // cin.tie(0);
    // ios_base::sync_with_stdio(false);
    ll A, B;
    cin >> A >> B;
    if ((A * B) % 2 == 0) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
} ./Main.cpp:25:12: warning: unknown attribute 'maybe_unused' ignored [-Wunknown-attributes]
using ll [[maybe_unused]] = long long;
           ^
./Main.cpp:26:13: warning: unknown attribute 'maybe_unused' ignored [-Wunknown-attributes]
using ull [[maybe_unused]] = unsigned long long;
            ^
./Main.cpp:27:12: warning: unknown attribute 'maybe_unused' ignored [-Wunknown-attributes]
using ld [[maybe_unused]] = long double;
           ^
3 warnings generated.