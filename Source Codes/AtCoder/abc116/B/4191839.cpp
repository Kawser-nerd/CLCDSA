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


int f(int n) {
    if (n % 2 == 0) return n / 2;
    return 3 * n + 1;
}

int main() {
    int s;
    cin >> s;
    set<int> memo;
    int a = s;
    int m = 1;
    while (true) {
        if (memo.count(a)) break;
        ++m;
        memo.insert(a);
        a = f(a);
    }
    cout << m << endl;
}