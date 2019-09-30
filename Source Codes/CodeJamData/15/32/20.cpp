#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <map>
#include <cassert>
using namespace std;
#pragma warning(disable: 4996)

#define _ (size_t)
#define all(a) a.begin(), a.end()
#define forint(i, a, b) for(int i=int(a); i<=int(b); ++i)
#define forintdown(i, a, b) for(int i=int(a); i>=int(b); --i)
#define forn(i, n) forint(i, 0, (n)-1)
#define forndown(i, n) forintdown(i, (n)-1, 0)
#define fillchar(a, x) memset(a, x, sizeof(a))
#define fi first
#define se second
#define PB push_back
#define MP make_pair
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
typedef vector<LL> VL;
typedef vector<int> VI;
typedef vector<PII> VPI;
typedef vector<string> VS;
template<class T> void setmax(T &a, T b) { if(b>a) a=b; }
template<class T> void setmin(T &a, T b) { if(b<a) a=b; }
template<class T> T gcd(T a, T b) { return b==0?a:gcd(b,a%b); }

// ------------------------ template ends here ------------------------ //

const int MAXN = 110;

int freq[MAXN]; char alphabet[MAXN];
int num, totfreq;
int word[MAXN];
int wn;
int n;

int sfx[MAXN], trans[MAXN][MAXN];
double go() {
    sfx[0] = 0;
    forint(c, 1, num) trans[0][c] = 0;
    trans[0][word[1]] = 1;
    forint(i, 1, wn) {
        if (i == 1)
            sfx[i] = 0;
        else
            sfx[i] = trans[sfx[i - 1]][word[i]];
        forint(c, 1, num) {
            if (i < wn && word[i + 1] == c)
                trans[i][c] = i + 1;
            else
                trans[i][c] = trans[sfx[i]][c];
        }
    }

    static double f[MAXN][MAXN][MAXN];
    fillchar(f, 0);
    f[0][0][0] = 1;
    forint(i, 1, n) {
        forint(s, 0, wn) forint(t, 0, n) {
            forint(c, 1, num) {
                int s2 = trans[s][c];
                int t2 = t + (s2 == wn);
                double prob = (double)freq[c] / (double)totfreq;
                f[i][s2][t2] += f[i - 1][s][t] * prob;
               // printf("{%d,%d,%d} += %.4lf\n", i, s2, t2, f[i - 1][s][t] * prob);
            }
        }
    }
    int hi = 0;
    forint(s, 0, wn) forint(t, 0, n) {
       // printf("f[%d,%d]=%.4lf\n", s, t, f[n][s][t]);
        if (f[n][s][t] > 0)
            hi = max(hi, t);
    }
    double ans = 0;
    forint(s, 0, wn) forint(t, 0, n) {
        ans += f[n][s][t] * (hi - t);
    }
    return ans;
}

double solve() {
    int K, L, S;
    scanf("%d%d%d", &K, &L, &S);
    n = S;

    static char buf[MAXN]; scanf("%s", buf); auto len = strlen(buf);
    assert(len == K);
    num = 0;
    forn(i, len) {
        int j = 1; while (j <= num && alphabet[j] != buf[i]) ++j;
        if (j > num) {
            ++num;
            freq[num] = 0;
            alphabet[num] = buf[i];
        }
        ++freq[j];
    }
    totfreq = (int)len;

    //forint(i, 1, num) fprintf(stderr, "a[%d]=%c\n", i, alphabet[i]);

    scanf("%s", buf); len = strlen(buf);
    assert(len == L);
    wn = (int)len;
    forint(i, 1, wn) {
        int j = 1; while (j <= num && alphabet[j] != buf[i - 1]) ++j;
        if (j > num) return 0.0;
        assert(j <= num);
        word[i] = j;
        //fprintf(stderr, "word[%d]=%d\n", i, word[i]);
    }

    return go();
}

int main() {
    freopen("C:\\Users\\dell\\OneDrive\\temp\\gcj-2015-1c\\data\\b_in.txt", "r", stdin);
    freopen("C:\\Users\\dell\\OneDrive\\temp\\gcj-2015-1c\\data\\b_out.txt", "w", stdout);

    int cs; scanf("%d", &cs);
    forint(fcs, 1, cs) {
        fprintf(stderr, "%d %d\n", fcs, cs);
        double ans = solve();
        printf("Case #%d: %.9lf\n", fcs, ans);
    }
	return 0;
}
