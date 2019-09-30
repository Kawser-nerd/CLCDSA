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

static constexpr ull MOD = 1000000007;
static constexpr double pi = 3.14159265359;

ull N;
set<ull> ans;

bool is575(ull i) {
    set<char> s;
    for (char c : to_string(i)) {
        s.insert(c);
    }
    return s.count('3') && s.count('5') && s.count('7');
}

void dfs(ull i) {
    if (i > N) return;
    if (i != 0 && is575(i)) ans.insert(i);
    for (ull j : {3, 5, 7}) {
        dfs(10 * i + j);
    }
}

int main() {
    cin >> N;
    dfs(0);
    cout << ans.size() << endl;
}