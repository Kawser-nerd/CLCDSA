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
    string S;
    cin >> S;
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int l, r;
        cin >> l >> r;
        --l; --r;
        for (int p = 0; p <= (r - l) / 2; ++p) {
            swap(S[l + p], S[r - p]);
        }
    }
    cout << S << endl;
}