#include <cstdio>
#include <queue>
#include <set>
#include <vector>
#include <cmath>
#include <iostream>
#include <map>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 10005;

int n;
char c[MAXN];
vector<int> a[MAXN];

void read() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        a[i].clear();
    }
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        -- x; -- y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
}

map < vector<int> , int > mp;
int cc;
map < pair<int, int> , int > dp;
map < pair< int , pair<int, int > > , bool > dp2;

int getNum(vector<int>& arr) {

    if (mp.find(arr) == mp.end()) mp[arr] = ++ cc;
    return mp[arr];
}

int go(int x, int prev = -1) {
    if (dp.find(make_pair(x, prev)) != dp.end()) return dp[make_pair(x, prev)];
    vector<int> h;

    for (int i = 0; i < (int)a[x].size(); i++) {
        if (a[x][i] != prev) {
            h.push_back(go(a[x][i], x));
        }
    }
    sort (h.begin(), h.end());
    h.push_back(c[x] - 'A');

    //printf ("%d %d\n", x, getNum(h));

    return dp[make_pair(x, prev)] = getNum(h);
}

int can(int x, int y, int prev = -1) {
    if (dp2.find(make_pair(x, make_pair(y, prev))) != dp2.end()) return dp2[make_pair(x, make_pair(y, prev))];
    vector<pair<int, int> > h;
  //  printf ("%d %d\n", x, (int)a[x].size());

    for (int i = 0; i < (int)a[x].size(); i++) {
        //printf (  " -- %d\n", a[x][i]);
        if (a[x][i] != prev) {
            h.push_back(make_pair(go(a[x][i], x), can(a[x][i], 1, x))); 
        }
    }
    sort(h.begin(), h.end());
    int need = 0;
/*
    printf ("hs\n");
    for (int i = 0; i < (int)h.size(); i++) {
        printf ("%d %d\n", h[i].first, h[i].second);
    }
    printf ("end\n");
*/
    for (int i = 0; i < (int)h.size(); i++ ) {
        int group = 1, canDo = h[i].second;
        while (i + 1 < (int)h.size() && h[i + 1].first == h[i].first) {
            ++ group; 
            canDo += h[i + 1].second;
            ++ i;
        }

        //printf ("NODE %d   GROUP = %d\n", x, group);
        
        if (group & 1) {
            if (!canDo) return dp2[make_pair(x, make_pair(y, prev))] = false;
            need += 1;
        }
    }
    //printf ("node = %d   need = %d   y = %d\n", x, need, y);
    if (need > y) return  dp2[make_pair(x, make_pair(y, prev))] = false;
    //printf ("%d %d return true\n", x, y);
    return  dp2[make_pair(x, make_pair(y, prev))] = true;
}

void solve() {
    dp.clear();
    dp2.clear();
    for (int i = 0; i < n; i++) {
        //printf ("%d\n", i);

        if (can(i, 2)) {
            printf ("SYMMETRIC\n");
            return ;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (int)a[i].size(); j++) {
            if (a[i][j] > i) {
                if (go(i, a[i][j]) == go(a[i][j], i)) {
                    printf ("SYMMETRIC\n");
                    return ;
                }
            }

        }
    }

    printf ("NOT SYMMETRIC\n");
}

int main() {
    int cases;

    cin >> cases;
    for (int i = 1; i <= cases; i++) {
        read();
        printf ("Case #%d: ", i);
        solve();
    }

    return 0;
}

