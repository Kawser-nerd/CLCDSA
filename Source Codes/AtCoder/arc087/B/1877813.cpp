#include <algorithm>
#include <complex>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

using std::string;
using std::to_string;
using std::vector;
using std::set;
using std::queue;
using std::priority_queue;

using std::min;
using std::max;
using std::sort;
using std::abs;

bool solve(const vector<int>& a, int k) {
    const int BIAS = 8000;
    int n = a.size();

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    if (abs(k) > sum) {
        return false;
    }

    vector<vector<bool>> dp(n + 1,
                            vector<bool>(BIAS + BIAS + 1));  // bias 8000!!

    dp[0][0 + BIAS] = true;

    for (int i = 1; i <= n; i++) {
        for (int j = -BIAS; j <= BIAS; j++) {
            dp[i][j + BIAS] = false;

            int ind;
            ind = j + a[i - 1];
            if (-BIAS <= ind && ind <= BIAS && dp[i - 1][ind + BIAS]) {
                dp[i][j + BIAS] = true;
            }

            ind = j - a[i - 1];
            if (-BIAS <= ind && ind <= BIAS && dp[i - 1][ind + BIAS]) {
                dp[i][j + BIAS] = true;
            }
        }
    }

    return dp[n][k + BIAS];
}

int main(void) {
    string s;
    cin >> s;
    const int slen = s.length();

    int x, y;
    cin >> x >> y;

    int fcnt = 0;
    for (int i = 0; i < slen && s[i] == 'F'; i++) {
        fcnt++;
    }

    const int init_x = fcnt;
    const int init_y = 0;

    const int diff_x = x - init_x;
    const int diff_y = y - init_y;

    vector<int> xs;
    vector<int> ys;
    int cnt;
    int phase = 1;  // 1 : x, -1 : y
    for (int i = fcnt; i < slen; i += cnt) {
        if (s[i] == 'T') {
            phase *= -1;
            cnt = 1;
            continue;
        }

        cnt = 0;
        for (int j = i; j < slen && s[j] == 'F'; j++) {
            cnt++;
        }

        if (phase == 1) {
            xs.push_back(cnt);
        } else {
            ys.push_back(cnt);
        }
    }

    /*
    for(int i : xs){
        cout << i << " ";
    }
    cout << endl;
    for(int i : ys){
        cout << i << " ";
    }
    cout << endl;
    */

    bool ans = solve(xs, diff_x) && solve(ys, diff_y);
    cout << (ans ? "Yes" : "No") << endl;

    return 0;
}