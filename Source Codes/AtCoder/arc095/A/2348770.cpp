// {{{
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdint>
#include <cstdio>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;
// }}}

using ll = long long;

int N, X[202020], Y[202020];

int main() {
    cin >> N;
    for (int j = 0; j < N; ++j) { cin >> X[j]; Y[j] = X[j]; }
    sort(Y, Y+N);
    for (int j = 0; j < N; ++j) {
        if (X[j] >= Y[N/2]) {
            cout << Y[(N-1)/2] << endl;
        } else {
            cout << Y[N/2] << endl;
        }
    }
    return 0;
}