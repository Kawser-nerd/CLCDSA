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
    int N, A, B;
    cin >> N >> A >> B;
    int pos = 0;
    for (int i = 0; i < N; ++i) {
        string s;
        int d;
        cin >> s >> d;
        d = max(A, min(B, d));
        if (s == "East") {
            pos += d;
        } else {
            pos -= d;
        }
    }
    if (pos == 0) {
        cout << pos << endl;
    } else if (pos > 0) {
        cout << "East " << pos << endl;
    } else {
        cout << "West " << -pos << endl;
    }
}