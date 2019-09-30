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
#define md 1000000007
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
const int z = 500001;
const int lim = 524288;
const int inf = 1324162729;
const ll lnf =  653556257326348742LL;
const int dx[]={-1, 0, 1,  0, -1, -1,  1, 1};
const int dy[]={ 0, 1, 0, -1, -1,  1, -1, 1};

int i, j, k, l, n, m, u, y, res, ntst, tall;
ll X, Y, Z, sum[524289], bst[524289], all, pls;
int a[z], b[z], g[z], h[z], ans;
int fs[z];
vi v;

int find_(int x)
{
    int i=0, j=n-1, mid;
   while (j-i>1) {
       mid=(i+j)/2;
     if (x<a[mid]) j=mid-1; else i=mid;
   }
     if (a[i]==x) return i; else return j;
}

int main()
{
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   for(i=1; i<=lim; i++) bst[i]=i-(i&(i-1));
     scanf("%d", &tall);
   for(ntst=1; ntst<=tall; ntst++) {
      scanf("%d%d%d%d%d", &n, &m, &X, &Y, &Z);
    f(i, m) scanf("%d", &g[i]); ans=0;
     for(i=0; i<n; i++) {
           a[i]=g[i%m]; b[i]=a[i]; h[i]=1;
         g[i%m]=((ll)X*(ll)g[i%m]+(ll)Y*((ll)i+1LL))%Z;
     }
        sort(a, a+n);
     memset(sum, 0, sizeof(sum));   
      i=0; j=1; m=n;
     while (j<n) { if (a[i]<a[j]) i++, a[i]=a[j]; j++; }
      n=i+1;
     f(i, m) b[i]=find_(b[i])+1;  
      for(i=0; i<m; i++) {
          all=0; j=b[i]-1;
        while (j) {
           all=(all+sum[j])%md; j-=bst[j];
        }
         pls=(all+1)%md;
          ans=(ans+pls)%md;
         j=b[i];
        while (j<=lim) {
            sum[j]=(sum[j]+pls)%md; j+=bst[j];
        }
      }
       printf("Case #%d: %d\n", ntst, ans);
       
   }
      return 0;
} 
