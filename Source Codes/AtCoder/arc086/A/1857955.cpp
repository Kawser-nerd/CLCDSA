#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define U(v) cerr << #v << ": " << (v) << endl

int main() {
    int N, K;
    while (cin >> N) {
        cin >> K;
        vector<int> a(N + 1, 0);
        for (int i = 0; i < N; ++i) {
            int p;
            cin >> p;
            ++a[p];
        }
        vector<pair<int, int>> b;
        for (int i = 1; i <= N; ++i) {
            if (a[i])
                b.emplace_back(a[i], i);
        }
        sort(b.begin(), b.end());
        reverse(b.begin(), b.end());
        int ct = 0;
        while ((int)b.size() > K) {
            ct += b.back().first;
            b.pop_back();
        }
        cout << ct << endl;
    }
    return 0;
}