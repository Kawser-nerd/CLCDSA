

#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <complex>


#include <time.h>
#include <stdlib.h>



using namespace std;

#define rep(i,b) for(int i=(0);i<(b);++i)
#define fo(i,a,b) for(int i=(a);i<=(b);++i)
#define ford(i,a,b) for(int i=(a);i>=(b);--i)
#define fore(a,b) for(__typeof((b).begin()) a = (b).begin();a!=(b).end();++a)
#define vv vector
#define pb push_back
#define ll long long
#define ld long double
#define ss(a) (int)(a).size()
#define all(x) (x).begin(),(x).end()
#define clr(x,a) memset(x,a,sizeof(x))
#define vi vv<int>
#define vs vv<string>

int cond = (ll)1;
#define db(x) { if (cond > 0) { cond--; rep (xxx, 1) cerr << __LINE__ << " " << #x << " " << x << endl; cerr.flush(); } }

int a[11111];
int n;

void solve() {
    scanf("%d", &n);
    rep (i, n)
        scanf("%d", &a[i]);
    int cnt = 0;
    rep (i, n) if (a[i] >= i) cnt++;
    if (cnt <= 515)
        printf("GOOD");
    else
        printf("BAD");

}


int good(int n) {
    rep (i, n)
        a[i] = i;
    rep (k, n) {
        int p = rand() % (n-k) + k;
        swap(a[k], a[p]);
    }
    int cnt = 0;
    rep (i, n) if (a[i] >= i) cnt++;
    printf("%d ", cnt);
    //rep (i, n) if (a[i] == i) cnt++;
    return cnt;
}

int bad(int n) {
    rep (i, n)
        a[i] = i;
    rep (k, n) {
        int p = rand() % (n);
        swap(a[k], a[p]);
    }
    int cnt = 0;
    rep (i, n) if (a[i] >= i) cnt++;
    //rep (i, n) if (a[i] == i) cnt++;
    return cnt;
}



int main(int argc, char ** argv) {
    //  freopen("../1.in","r",stdin); 
    //  freopen("../2.in","r",stdin); 
    //  freopen("../3.in","r",stdin); 
    //  freopen("../C-small.in","r",stdin); freopen("../C-small.out","w",stdout);
    //  freopen("../C-small-attempt0.in","r",stdin);freopen("../C-small-attempt0.out","w",stdout);
    //  freopen("../C-small-attempt1.in","r",stdin);freopen("../C-small-attempt1.out","w",stdout);
    //  freopen("../C-small-attempt2.in","r",stdin);freopen("../C-small-attempt2.out","w",stdout);
    //  freopen("../C-large.in","r",stdin); freopen("../C-large.out","w",stdout)
    //
    srand(time(NULL));

    int a = 0, b = 0;
    int N = 100000;
    rep (i, N) {
      //  a += good(1000);
     //   b += bad(1000);
    }
    //printf("%Lf %Lf\n", ((ld)a/N), ((ld)b/N));

    cond = argc >= 2 && argv[1][0] == 'q' ? 1 << 30 : 0;
    int t;
    scanf("%d", &t);
    fo (i, 1, t) {
        if (cond)
            cerr << __LINE__ << " " << i << endl;
        printf("Case #%d: ", i);
        solve();
        printf("\n");
        fflush(stdout);
        cerr.flush();
    }
	return 0;
}

