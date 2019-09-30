#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;
using ull = unsigned long long;

int main() {
    map<string, int> si;
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        string tmp;
        cin >> tmp;
        ++si[tmp];
    }

    map<string, int> ti;
    int M;
    cin >> M;
    for (int i = 0; i < M; ++i) {
        string tmp;
        cin >> tmp;
        ++ti[tmp];
    }

    int ans = 0;
    for (const auto& s : si) {
        ans = max(ans, s.second - ti[s.first]);
    }
    cout << ans << endl;
}