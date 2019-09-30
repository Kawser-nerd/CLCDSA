#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <set>
#include <string>
#include <vector>

using namespace std;
using ull = unsigned long long;

int main() {
    ull A, B, K;
    cin >> A >> B >> K;
    set<ull> ans;
    for (ull i = 0, p = A; i < K; ++p, ++i) {
        if (p > B) break;
        ans.insert(p);
    }
    for (ull i = 0, p = B; i < K; --p, ++i) {
        if (p < A) break;
        ans.insert(p);
    }
    for (ull p : ans) {
        cout << p << endl;
    }
}