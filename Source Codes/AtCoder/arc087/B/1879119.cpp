#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

string s;
int x, y;
int l;

int dp(vector<int> v, int t) {
    int len = l + 2;
    if (t > len)
        return false;
    int dp[len];
    for (int i = 0; i < len; ++i) dp[i] = 0;
    dp[0] = 1;
    for (int vi : v) {
        for (int i = 0; i < len; ++i) {
            if ((i - vi >= 0 && dp[i - vi] == 1) || (i + vi < len && dp[i + vi] == 1)) {
                dp[i] = 2;
            }
        }
        for (int i = 0; i < len; ++i) {
            if (dp[i] == 1) dp[i] = 0;
            if (dp[i] == 2) dp[i] = 1;
        }
    }
    return dp[t] == 1;
}

int main(){
    cin >> s >> x >> y;

    l = s.size();

    int i;
    for (i = 0; i < s.size(); ++i) {
        if (s[i] == 'F')
            x--;
        else
            break;
    }

    x = abs(x);
    y = abs(y);

    vector<int> dx;
    vector<int> dy;

    dx.push_back(0);

    bool dirx = true;

    for (; i < s.size(); ++i) {
        if (s[i] == 'T') {
            dirx = !dirx;
            if (dirx) dx.push_back(0); else dy.push_back(0);
        } else {
            if (dirx)
                dx[dx.size() - 1]++;
            else
                dy[dy.size() - 1]++;
        }
    }

    //cout << endl;
    //for (int dxi : dx) {
    //    cout << dxi << " ";
    //}
    //cout << endl;

    cout << (dp(dx, x) && dp(dy, y) ? "Yes" : "No") << endl;
    return 0;
}