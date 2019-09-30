#include <iostream>
#include <unordered_map>

using namespace std;

using ull = uint64_t;

ull n, m;

ull sum[100010];
unordered_map<ull, ull> countmap;
ull ans = 0;

int main() {
    cin >> n >> m;
    for (ull i = 1; i <= n; i++) {
        int tmp;
        cin >> tmp;
        sum[i] = (sum[i - 1] + tmp) % m;
    }

    for (ull i = 0; i <= n; i++) {
        if (countmap.find(sum[i]) == countmap.end()) {
            countmap[sum[i]] = 0;
        }
        countmap[sum[i]]++;
    }

    for(auto&& p : countmap) {
        ans += p.second * (p.second - 1) / 2;
    }

    cout << ans << endl;

    return 0;
}