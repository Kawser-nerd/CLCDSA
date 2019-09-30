#define FNAME ""

#include <bits/stdc++.h>

#define hash padjf9srpi
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define forn(i, n) for (int i = 0; i < (n); i++)
#define fornr(i, n) for (int i = (n) - 1; i >= 0; i--)
#define forab(i, a, b) for (int i = (a); i < (b); i++)
#define gcd __gcd
#define all(a) (a).begin(), (a).end()
 
#ifdef _WIN32
    #define I64 "%I64d"
#else
    #define I64 "%lld"
#endif

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair <int, int> pii;                                                                                                                                                                                      
typedef vector <int> vi;

template <class T> T sqr(const T &a) {return a * a;}

int cmp(pii x, pii y) {
    return 1ll * x.first * x.second < 1ll * y.first * y.second;
}

const int MAXN = 1005;
pii a[MAXN];
int n, k, T;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

#ifdef LOCAL
    freopen(FNAME".in", "r", stdin);
    freopen(FNAME".out", "w", stdout);
#endif

    scanf("%d", &T);
    forn(ttt, T) {
        scanf("%d%d", &n, &k);
        forn(i, n) scanf("%d%d", &a[i].second, &a[i].first);
        sort(a, a + n, cmp);
        reverse(a, a + n);
        LD ans = 0;
        forn(i, n) {
            int cnt = 1;
            LD h = 2.0 * a[i].first * a[i].second * M_PI;
            forn(j, n) {
                if (cnt == k) break;
                if (j == i || a[j].second > a[i].second) continue;
                cnt++;
                h += 2.0l * a[j].first * a[j].second * M_PI;
            }
            ans = max(ans, 1.0 * M_PI * a[i].second * a[i].second + h);
                        
        }
        printf("Case #%d: %.20Lf\n", ttt + 1, ans);
    }
     
}


