/**
 *    author:  itmo1
 *    created: 28.05.2016 17:03:25       
**/
#define __USE_MINGW_ANSI_STDIO 0
#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define mp make_pair
#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define eprintf(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(),a.end()
#define pw(x) (1LL<<(x))

using namespace std;

typedef long long ll;
typedef double dbl;
typedef vector<int> vi;
typedef pair<int, int> pi;

const int inf = 1.01e9;
const dbl eps = 1e-9;

/* --- main part --- */

const int N = 1e4;

int a[N];

int R, P, S;

string buildP(int n);
string buildS(int n);

string buildR(int n)
{
    if (n == 0) return "R";
    string s1 = buildR(n - 1);
    string s2 = buildS(n - 1);
    if (s1 > s2) swap(s1, s2);
    return s1 + s2;
}

string buildS(int n)
{
    if (n == 0) return "S";
    string s1 = buildP(n - 1);
    string s2 = buildS(n - 1);
    if (s1 > s2) swap(s1, s2);
    return s1 + s2;
}

string buildP(int n)
{
    if (n == 0) return "P";
    string s1 = buildR(n - 1);
    string s2 = buildP(n - 1);
    if (s1 > s2) swap(s1, s2);
    return s1 + s2;
}

string check(string ss)
{
    int r = 0, p = 0, s = 0;
    forn(i, sz(ss))
    {
        if (ss[i] == 'R') ++r;
        if (ss[i] == 'P') ++p;
        if (ss[i] == 'S') ++s;
    }
    if (r == R && p == P && s == S) return ss;
    return "Z";
}

int main()
{
    #ifdef home
        assert(freopen("1.in", "r", stdin));
        assert(freopen("1.out", "w", stdout));
    #endif
    int tn;
    scanf("%d", &tn);
    forn(tt, tn)
    {
        int n;
        scanf("%d%d%d%d", &n, &R, &P, &S);
        string res = "Z";
        res = min(res, check(buildR(n)));
        res = min(res, check(buildP(n)));
        res = min(res, check(buildS(n)));
        if (res == "Z") res = "IMPOSSIBLE";
        printf("Case #%d: %s\n", tt + 1, res.data());
    }

        

            
    #ifdef home
        eprintf("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
    #endif
    return 0;
}
