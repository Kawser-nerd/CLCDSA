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

using ll = long long;

int main() {
    int N, M;
    cin >> N >> M;
    int t = 100 * (N - M) + M * 1900;
    cout << t * (1 << M) << endl;
    return 0;
}