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
const int z = 1000;
const int inf = 1324162729;
const ll lnf =  653556257326348742LL;
const int dx[]={-1, 0, 1,  0, -1, -1,  1, 1};
const int dy[]={ 0, 1, 0, -1, -1,  1, -1, 1};

int i, j, k, l, n, m, u, y, res, ntst, tall, a[z];
char s[20];
vi v;

void gen(int np)
{
    if (np==l) {
        ll g=0, t=s[0]-48;
        bool p=1;
       for(int i=1; i<l; i++)
         if (a[i]==0) {
            t=t*10+s[i]-48;
         } else
         if (a[i]==1) {
           if (p) g+=t; else g-=t; t=s[i]-48; p=1;
         } else {
           if (p) g+=t; else g-=t; t=s[i]-48; p=0;
         }
        if (p) g+=t; else g-=t; 
        if (g%2==0 || g%3==0 || g%5==0 || g%7==0) res++;  
    } else {
        a[np]=0; gen(np+1); a[np]=1; gen(np+1); a[np]=2; gen(np+1);
    }
}

int main()
{
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
     scanf("%d\n", &tall);
   for(ntst=1; ntst<=tall; ntst++) {
        gets(s); res=0;
     for(l=0; s[l] && s[l]>='0' && s[l]<='9'; l++); gen(1);
        printf("Case #%d: %d\n", ntst, res);
       
   }
      return 0;
} 
