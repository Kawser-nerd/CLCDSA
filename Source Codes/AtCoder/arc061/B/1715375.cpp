//
// D - ???????? / Snuke's Coloring
//

#include <iostream>
#include <unordered_map>

using namespace std;
using ULL =  unsigned long long;

int main() {

    int H, W, N;
    cin >> H >> W >> N;

    unordered_map<string, ULL> map;

    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        for (int y = a - 2; y <= a; y++) {
            for (int x = b - 2; x <= b; x++) {
                if (y > 0 && y <= H - 2 && x > 0 && x <= W - 2) {
                    string k = to_string(y) + "-" + to_string(x);
                    if (map.find(k) == map.end()) {
                        map[k] = 1;
                    } else {
                        map[k]++;
                    }
                }
            }
        }
    }

    ULL ans[10] = {0};
    ULL zero = (ULL)(H - 2) * (ULL)(W - 2);

    for (auto it = map.begin(); it != map.end(); it++) {
        ans[it->second]++;
        zero--;
    }
    ans[0] = zero;

    for (int i = 0; i < 10; i++) {
        cout << ans[i] << endl;
    }
}