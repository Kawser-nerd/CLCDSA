#include <iostream>

#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

#include <cassert>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdint>
#include <ctime>

#include <fstream>

#include <cassert>

using namespace std;

#define MY_PI 3.14159265358979323846264338327950288
using LL = long long;
const int INF = 1e9;
const int MAXN = 1e5 + 10;

const long double kek = 1.0;
const float eps = 1e-9;
#define DB(x) cerr << #x << " " << x << endl;

//vector < int > dp (MAXN, -1);

int dfs(int v, int p, const vector < vector < int > > &g){
    //if (dp[v])
    vector < int > ans;
    //cout << v << " : ";
    for (auto to: g[v]) {
        //cout << v <<  " -> " << to << " ";
        if (to == p) {
            continue;
        }

        ans.push_back(dfs(to, v, g));
    }
    //cout << endl;
    sort(ans.rbegin(), ans.rend());
    int res = 0;
    int add = 1;
    //cout << v << " : ";
    for (int i = 0; i < ans.size(); ++i) {
        //cout << ans[i] << " ";
        res = max(res, ans[i] + add);
        add++;
    }
    //cout << endl;
    return res;
}


int main()
{
    //gen(1001);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    //cout << fixed;
    //cout.precision(6);
    int n;
    cin >> n;
    vector < vector < int > > gr(n);
    for (int i = 1; i < n; ++i){
        int a;
        cin >> a;
        a--;
        gr[a].push_back(i);
        gr[i].push_back(a);
        //cin >> a[i] >> b[i];
    }

    cout << dfs(0, -1, gr);
    return 0;
}