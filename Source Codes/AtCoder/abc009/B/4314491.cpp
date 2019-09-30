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
const double pi = 3.14159265359;


int main() {
    int N;
    cin >> N;
    set<int> A;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        A.insert(a);
    }
    auto it = A.rbegin();
    ++it;
    cout << *it << endl;
}