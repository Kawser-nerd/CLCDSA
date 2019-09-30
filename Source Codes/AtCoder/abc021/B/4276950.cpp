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
    int a, b;
    cin >> a >> b;
    int K;
    cin >> K;
    set<int> P;
    P.insert(a);
    P.insert(b);
    for (int i = 0; i < K; ++i) {
        int p;
        cin >> p;
        P.insert(p);
    }
    if (P.size() == K + 2) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}