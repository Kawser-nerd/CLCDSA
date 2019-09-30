#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
using ull = unsigned long long;


int B[100001];

int main() {
    int N;
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> B[i];
    }
    set<int> memo;
    int cur = 1;
    memo.insert(cur);
    int ans = 0;
    while (true) {
        cur = B[cur];
        ++ans;
        if (cur == 2) {
            cout << ans << endl;
            return 0;
        }
        if (memo.count(cur)) {
            cout << "-1" << endl;
            return 0;
        }
        memo.insert(cur);
    }
}