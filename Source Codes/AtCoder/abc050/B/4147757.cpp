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
using P = pair<int, int>;


ull E = 1000000007;

int main() {
    int N;
    cin >> N;
    vector<int> T;
    for (int i = 0; i < N; ++i) {
        int t;
        cin >> t;
        T.push_back(t);
    }
    int M;
    cin >> M;
    vector<P> PX;
    for (int i = 0; i < M; ++i) {
        int p, x;
        cin >> p >> x;
        PX.push_back({p, x});
    }
    for (const auto& px : PX) {
        int time = 0;
        for (int i = 0; i < N; ++i) {
            if (i + 1 == px.first) {
                time += px.second;
            } else {
                time += T[i];
            };
        }
        cout << time << endl;
    }
}