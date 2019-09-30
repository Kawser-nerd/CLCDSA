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

const int MAX = 24 * 60 + 10;
int d[MAX][MAX][2][2], bad[MAX][2], T, cnt[2];

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
        scanf("%d%d", &cnt[0], &cnt[1]);
        forn(i, MAX) bad[i][0] = bad[i][1] = 0;
        forn(k, 2) {
            forn(i, cnt[k]) {
                int x, y;
                scanf("%d%d", &x, &y);
                assert(y < MAX);
                forab(j, x, y)
                    bad[j][k] = 1; 
            }
        }
        forn(i, MAX) forn(j, MAX) d[i][j][0][0] = d[i][j][1][0] = d[i][j][0][1] = d[i][j][1][1] = 1e9;
        d[0][0][0][0] = 0;
        d[0][0][1][1] = 0;
        forn(i, MAX - 1) {
            forn(j, i + 1) {
                forn(l, 2) {
                    forn(k, 2) {
                        if (!bad[i][k]) d[i + 1][j + 1][k][l] = min(d[i + 1][j + 1][k][l], d[i][j][k][l]);
                        if (!bad[i][1 - k]) d[i + 1][i + 1 - j][1 - k][l] = min(d[i + 1][i + 1 - j][1 - k][l], d[i][j][k][l] + 1);
                    }
                }
            }
        }
        printf("Case #%d: %d\n", ttt + 1, min(min(d[24 * 60][12 * 60][0][0], d[24 * 60][12 * 60][1][1]), min(d[24 * 60][12 * 60][0][1], d[24 * 60][12 * 60][0][1]) + 1));
    }
}


