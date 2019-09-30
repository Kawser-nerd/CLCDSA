#include <algorithm>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
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
#define MAX(a,b) ((a)>(b))?((a):(b))
#define MIN(a,b) ((a)<(b))?((a):(b))

void solve() {
    int n, k;
    scanf("%d%d", &n, &k);
    bool ok = 1;
    rep (i, n) ok = ok && (k & (1<<i));

    printf(" %s", ok?"ON":"OFF");
}

int main(int argc, char ** argv) {
   int t;
   scanf("%d", &t);
   rep (i, t) {
       printf("Case #%d:", i+1);
       solve();
       printf("\n");
   }
   return 0;
}



