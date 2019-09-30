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
    vector<int> h;
    int M = 0;
    for (int i = 0; i < N; ++i) {
        int tmp;
        cin >> tmp;
        M = max(M, tmp);
        h.push_back(tmp);
    }

    int ans = 0;
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N;) {
            while (h[j] == 0) ++j;
            if (j >= N) break;
            while (h[j] != 0) --h[j++];
            ++ans;
        }
    }
    cout << ans << endl;
}