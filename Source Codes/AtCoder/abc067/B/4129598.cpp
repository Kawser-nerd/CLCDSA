#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
using ull = unsigned long long;


int main() {
    int N, K;
    cin >> N >> K;
    vector<int> l;
    for (int i = 0; i < N; ++i) {
        int tmp;
        cin >> tmp;
        l.push_back(tmp);
    }
    sort(l.rbegin(), l.rend());
    int ans = 0;
    for (int i = 0; i < K; ++i) {
        ans += l[i];
    }
    cout << ans << endl;
}