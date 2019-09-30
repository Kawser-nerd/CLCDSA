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


int main() {
    set<int> memo;
    int A, B, C;
    cin >> A >> B >> C;
    for (int i = 1; ; ++i) {
        int m = (A * i) % B;
        if (memo.count(m)) break;
        memo.insert(m);
        if (m == C) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}