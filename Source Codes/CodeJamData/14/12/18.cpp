#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <climits>
#include <cassert>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <bitset>
#include <utility>
#include <algorithm>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

const int N = 2000;

int n;
vector<int> nxt[N];

map<pair<int,int>,int> cnt;
map<pair<int,int>,int> z;

void process(int u, int v)
{
    pair<int,int> p(u, v);
    if (cnt.count(p))
        return;

    cnt[p] = 1;
    vector<int> zz;

    forn(i, nxt[v].size())
    {
        int to = nxt[v][i];
        if (to != u)
        {
            process(v, to);
            cnt[p] += cnt[make_pair(v, to)];
            zz.push_back(z[make_pair(v, to)]);
        }
    }

    z[p] = 1;
    
    sort(zz.begin(), zz.end());
    if (zz.size() >= 2)
        z[p] = max(z[p], 1 + zz[zz.size() - 1] + zz[zz.size() - 2]);

    // cout << u << " " << v << ": " << cnt[p] << " " << z[p] << endl;
}

int solve()
{
    forn(i, n)
        forn(j, nxt[i].size())
            process(i, nxt[i][j]);

    int result = 1;

    forn(i, n)
    {
        vector<int> zz;
        forn(j, nxt[i].size())
        {
            pair<int,int> p(i, nxt[i][j]);
            zz.push_back(z[p]);
        }
        sort(zz.begin(), zz.end());
        if (zz.size() >= 2)
            result = max(result, 1 + zz[zz.size() - 1] + zz[zz.size() - 2]);
    }        
    return n - result;
}

int main(int argc, char* argv[])
{
    int tt;
    cin >> tt;

    forn(tx, tt)
    {
        z.clear();
        cnt.clear();

        cin >> n;

        forn(i, n)
            nxt[i].clear();
        
        forn(i, n - 1)
        {
            int x, y;
            cin >> x >> y;
            x--, y--;
            nxt[x].push_back(y);
            nxt[y].push_back(x);
        }

        cout << "Case #" << (tx + 1) << ": " << solve() << endl;
    }
}
