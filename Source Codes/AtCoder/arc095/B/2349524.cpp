#include <array>
#include <bitset>
#include <deque>
#include <map>
#include <queue>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
#include <iostream>
#include <sstream>
#include <cmath>
#include <cstring>
using namespace std;
#define U(v) cerr << #v << ": " << (v) << endl

int main() {
    int N;
    while (cin >> N) {
        vector<int> a(N);
        for (auto& p : a)
            cin >> p;
        sort(a.begin(), a.end());
        int l = a.back();
        a.pop_back();
        int bi = -1;
        double be = 1e9;
        for (int p : a) {
            int q = p;
            if (l - p > p)
                q = l - p;
            double e = q / (double)l;
            if (be > e) {
                be = e;
                bi = p;
            }
        }
        cout << l << ' ' << bi << endl;
    }
    return 0;
}