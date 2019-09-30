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

const int MAXN = 100;
const LD eps = 1e-8;

LD p[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

#ifdef LOCAL
    freopen(FNAME".in", "r", stdin);
    freopen(FNAME".out", "w", stdout);
#endif

    int T;
    scanf("%d", &T);
    forn(ttt, T) {
        int n, k;
        scanf("%d%d", &n, &k);
        LD h;
        scanf("%Lf", &h);
        forn(i, n) {
            scanf("%Lf", &p[i]);
        }
        sort(p, p + n);
        p[n] = 1;
        forab(i, 1, n + 1) {
            LD delta = min((p[i] - p[i - 1]), h / i);
            forn(j, i) p[j] += delta;
            h -= delta * i;
        }
        LD prod = 1;
        forn(i, n) prod *= p[i];
        printf("Case #%d: %.10Lf\n", ttt + 1, prod);


    }
}


