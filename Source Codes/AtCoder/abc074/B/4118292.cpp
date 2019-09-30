#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
using ull = unsigned long long;

int main() {
    int N, K;
    cin >> N >> K;
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;
        ans += 2 * min(x, abs(x - K));
    }
    cout << ans << endl;
}