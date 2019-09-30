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


int main() {
    int L, H;
    cin >> L >> H;
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int A;
        cin >> A;
        if (A < L) {
            cout << L - A << endl;
        } else if (A > H) {
            cout << -1 << endl;
        } else {
            cout << 0 << endl;
        }
    }
}