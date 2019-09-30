#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
#include <cassert>
#include <complex>
using namespace std;
#define rep(i,a,n) for (int i=a;i<(int)n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define ACCU accumulate
#define TWO(x) (1<<(x))
#define TWOL(x) (1ll<<(x))
#define clr(a) memset(a,0,sizeof(a))
#define POSIN(x,y) (0<=(x)&&(x)<n&&0<=(y)&&(y)<m)
#define PRINTC(x) printf("Case #%d: %d\n",++__,x)
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long ll;
typedef long double LD;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<ll> VL;
typedef vector<PII> VPII;
typedef complex<double> CD;
const int inf=0x20202020;
const ll mod=1000000007;
const double eps=1e-9;
const double pi=3.1415926535897932384626;
const int DX[]={1,0,-1,0},DY[]={0,1,0,-1};
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll powmod(ll a,ll b,ll mod) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

int _,__,r,c,m;
char brd[100][100];
int main() {
	for (scanf("%d",&_);_;_--) {
		scanf("%d%d%d",&r,&c,&m);
		printf("Case #%d:\n",++__);
		if (m==r*c-1) {
			putchar('c');
			rep(i,1,c) putchar('*');
			puts("");
			rep(i,1,r) { rep(j,0,c) putchar('*');puts("");}
		} else if (c==1) {
			puts("c");
			rep(i,1,r-m) puts(".");
			rep(i,0,m) puts("*");
		} else if (r==1){
			putchar('c');
			rep(i,1,c-m) putchar('.');
			rep(i,0,m) putchar('*');
			puts("");
		} else if (m>r*c-4) puts("Impossible");
		else {
			bool fg=0;
			rep(i,0,r) rep(j,0,c) brd[i][j]='*';
			int bk=r*c-m;
			rep(i,2,r+1) rep(j,2,c+1) {
				if (bk<=i*j&&bk>=2*i+2*j-4&&!fg) {
					fg=1;
					rep(c1,0,i) brd[c1][0]=brd[c1][1]='.';
					rep(c1,0,j) brd[0][c1]=brd[1][c1]='.';
					int ck=bk-2*i-2*j+4;
					rep(c1,2,i) rep(c2,2,j) if (ck) {
						brd[c1][c2]='.';
						--ck;
					}
				}
			}
			brd[0][0]='c';
			if (!fg) puts("Impossible");
			else {rep(i,0,r) { rep(j,0,c) putchar(brd[i][j]);puts("");}}
		}
	}
}
