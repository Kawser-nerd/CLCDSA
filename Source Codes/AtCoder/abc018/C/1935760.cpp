#include <algorithm>
#include <cmath>
#include <complex>
#include <iomanip>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::cerr;

using std::string;
using std::to_string;
using std::vector;
using std::set;
using std::queue;
using std::stack;
using std::priority_queue;
using std::pair;
using std::make_pair;

using std::min;
using std::max;
using std::sort;
using std::abs;
using std::swap;

using std::fixed;
using std::setprecision;
using std::setw;

typedef long long int ll;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 314;

int main() {
    int r, c, k;
    cin >> r >> c >> k;

    vector<string> s(r);
    for (int i = 0; i < r; i++) {
        cin >> s[i];
    }

    vector<vector<int>> up(r, vector<int>(c));
    vector<vector<int>> down(r, vector<int>(c));

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            int cnt;

            cnt = 0;
            for (int l = i; l >= 0 && s[l][j] == 'o'; l--) {
                cnt++;
            }
            up[i][j] = cnt;

            cnt = 0;
            for (int l = i; l < r && s[l][j] == 'o'; l++) {
                cnt++;
            }
            down[i][j] = cnt;
        }
    }

    int cnt = 0;
    for (int i = k - 1; i <= r - k; i++) {
        for (int j = k - 1; j <= c - k; j++) {
            bool hisigata = true;
            for (int l = 0; l < k; l++) {
                if (!(up[i][j - l] >= k - l && down[i][j - l] >= k - l &&
                      up[i][j + l] >= k - l && down[i][j + l] >= k - l)) {
                    hisigata = false;
                    break;
                }
            }
            if (hisigata) {
                cnt++;
            }
        }
    }
    cout << cnt << endl;

    return 0;
}