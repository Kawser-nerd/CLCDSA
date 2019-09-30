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
ull e = 10007;
const double pi = 3.14159265359;


int main() {
    int N;
    cin >> N;
    multiset<int> L;
    for (int i = 0; i < N; ++i) {
        int l;
        cin >> l;
        L.insert(l);
    }
    auto it = L.rbegin();
    int max_ = *it;
    ++it;
    int sum = 0;
    while (it != L.rend()) {
        sum += *it;
        ++it;
    }
    if (max_ < sum) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}