#include <cassert>
#include <stdio.h>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>
#include <stack>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef pair<LL, LL> PII;

#define debug(args...) {vector<string> _v = split(#args, ','); err(_v.begin(), args); puts("");}
vector<string> split(const string& s, char c) {vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(x); return v;}
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) {cerr << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << ", "; err(++it, args...);}

#if (( _WIN32 || __WIN32__ ) && __cplusplus < 201103L)
#define lld I64d
#else
#define lld lld
#endif

#define pb push_back
#define mp make_pair
#define all(x)  (x).begin(),(x).end()
#define tr(c, it)   for(auto it=c.begin(); it!=c.end(); it++)
#define clr(a, b)   memset(a, b, sizeof(a))
#define forn(i, n)   for(int i=0; i<n; i++)

const int INF = 0x3f3f3f3f;
LL h, w;

LL cal(LL pos, LL p, LL q, LL s1)
{
    LL s2 = pos * p;
    LL s3 = (q - pos) * p;

    LL maxi = max(s1, max(s2, s3));
    LL mini = min(s1, min(s2, s3));

    return maxi - mini;
}

LL fun(LL a, LL b)
{
    LL ret = min(a, b);

    for(LL i=1; i<a; i++)
    {
        LL s1 = i * b;

        if(b == 2)
        {
            LL s2 = a - i;
            LL cur = max(s1, s2) - min(s1, s2);
            ret = min(ret, cur);
            continue;
        }

        LL l = 1, r = b - 1;

        while(l + 1 < r)
        {
            LL mid = (l + r) / 2;
            LL mmid = (mid + r) / 2;
            //debug(l, r, mid, mmid);

            LL vmid = cal(mid, a-i, b, s1);
            LL vmmid = cal(mmid, a-i, b, s1);

            //debug(l, r, mid, mmid, vmid, vmmid);
            if(vmid < vmmid)
                r = mmid;
            else
                l = mid;
        }

        //debug(l ,r);


        LL vall = cal(l, a-i, b, s1);
        LL valr = cal(r, a-i, b, s1);
        LL pos;
        if(vall < valr) pos = l;
        else pos = r;
        //debug(pos)

        LL cur = cal(pos, a-i, b, s1);
        ret = min(cur, ret);

    }
    return ret;

}


int main()
{
#ifdef LOCAL
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif

    while(cin >> h >> w)
    {
        if(h % 3 == 0 || w % 3 == 0)
        {
            cout << 0 << endl;
            continue;
        }

        //LL ans = fun(h, w);

        LL ans = min(fun(h, w), fun(w, h));

        cout << ans << endl;

    }
    return 0;
}