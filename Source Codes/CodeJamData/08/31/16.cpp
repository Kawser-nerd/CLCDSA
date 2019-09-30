#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <set>
#include <queue>
#include <map>

using namespace std;

#define W while
#define all(v) v.begin(), v.end()
#define sz(v) int((v).size())
#define pb push_back
#define mp make_pair
#define md 100000007
#define P pair<int, int>
#define ll long long
#define vi vector <int>
#define vs vector <string>
#define f(i, n) for(int i=0; i<(n); i++)
#define F(i, n, m) for(int i=(n); i<=(m); i++)
#define d(i, n) for(int i=(n)-1; i>=0; i--)
#define D(i, n, m) for(int i=(n); i>=(m); i--)

inline ll sqr(ll x) { return x*x; }
inline ll gcd(ll x, ll y) { return y ? gcd(y, x%y) : x; }
inline ll lcm(ll x, ll y) { return x/gcd(x, y)*y; }

const double eps = 1e-11;
const int z = 1001;
const int inf = 1324162729;
const ll lnf =  653556257326348742LL;
const int dx[]={-1, 0, 1,  0, -1, -1,  1, 1};
const int dy[]={ 0, 1, 0, -1, -1,  1, -1, 1};

int i, j, p, k, l, n, nk, np, m, u, y, ntst, tall, a[z], b[z];
vi v;
ll res;

int main()
{
   freopen("A-large.in", "r", stdin);
   freopen("output.txt", "w", stdout);
     scanf("%d", &tall);
   for(ntst=1; ntst<=tall; ntst++) {
      scanf("%d%d%d", &p, &k, &l);
    f(i, l) scanf("%d", &a[i]);
         sort(a, a+l);
     np=1; nk=1; i=l-1; res=0;
    while (i>=0) {
        res+=(ll)np*(ll)a[i];
      if (nk==k) nk=1, np++; else nk++;
        i--;
    }
       printf("Case #%d: %I64d\n", ntst, res);
       
   }
      return 0;
}
