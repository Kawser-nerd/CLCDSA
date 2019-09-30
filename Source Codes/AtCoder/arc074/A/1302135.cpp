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

const LL INF = 0x3f3f3f3f3f3f3f3fll;
LL h, w;
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

        LL ans = min(h, w);
        for(LL i=1; i<h; i++)
        {
            LL s1 = i * w;

            LL v1 = w / 2;
            LL v2 = w - v1;

            LL s2 = v1 * (h - i);
            LL s3 = v2 * (h - i);

            LL maxi = max(s1, max(s2, s3));
            LL mini = min(s1, min(s2, s3));
            LL cur = maxi - mini;

            if( (maxi - mini) < ans)
            {
                ans = maxi - mini;
            }
            //debug(i, cur, ans);
        }

        for(LL i=1; i<w; i++)
        {
            LL s1 = i * h;

            LL v1 = h / 2;
            LL v2 = h - v1;

            LL s2 = v1 * (w - i);
            LL s3 = v2 * (w - i);

            LL maxi = max(s1, max(s2, s3));
            LL mini = min(s1, min(s2, s3));

            LL cur = maxi - mini;

            if( (maxi - mini) < ans)
            {
                ans = maxi - mini;
            }
            //debug(i, cur, ans);
        }

        cout << ans << endl;


    }
    return 0;
}