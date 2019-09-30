#include<map>
#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;
#define rep(i,n) for (int (i)=(0);(i)<(long long)(n);++(i))
using ll = long long;
using P = pair<int, int>;
#define fs first
#define sc second
using namespace std;

template<class T> void vin(vector<T>& v, int n) {
    v.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
}

int n;
string s;
map<int, map<string, map<string, ll>>> dp;
map<int, map<string, map<string, bool>>> flag;

ll solve(int idx, string r, string b) {
    if (idx >= n*2) {
        reverse(b.begin(), b.end());
        if (r == b) return 1;
        else return 0;
    }
    if (flag[idx][r][b]) return dp[idx][r][b];
    flag[idx][r][b] = true;
    ll res = 0;
    if (idx < n) {
        res += solve(idx+1, r+s[idx], b);
        res += solve(idx+1, r, b+s[idx]);
    }
    else {
        //
        if (r.size()+1 <= n and s[idx] == b[n-r.size()-1]) res += solve(idx+1, r+s[idx], b);
        if (b.size()+1 <= n and s[idx] == r[n-b.size()-1]) res += solve(idx+1, r, b+s[idx]);
    }
    return (dp[idx][r][b] = res);
}

int main() {
    cin >> n >> s;
    cout << solve(0, "", "") << endl;
    return 0;
}