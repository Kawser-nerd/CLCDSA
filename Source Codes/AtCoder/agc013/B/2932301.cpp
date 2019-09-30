/*
ID:wmj20041
TASK:
LANG:C++
*/
#include<functional>
#include<algorithm>
#include<exception>
#include<stdexcept>
#include<streambuf>
#include<iterator>
#include<string.h>
#include<stdlib.h>
#include<typeinfo>
#include<valarray>
#include<iostream>
#include<sstream>
#include<istream>
#include<stdio.h>
#include<climits>
#include<clocale>
#include<complex>
#include<csetjmp>
#include<csignal>
#include<cstdarg>
#include<cstddef>
#include<ctype.h>
#include<cassert>
#include<cstdlib>
#include<utility>
#include<cstring>
#include<numeric>
#include<ostream>
#include<cwctype>
#include<fstream>
#include<iomanip>
#include<math.h>
#include<bitset>
#include<cctype>
#include<string>
#include<vector>
#include<limits>
#include<locale>
#include<memory>
#include<cerrno>
#include<time.h>
#include<iosfwd>
#include<cfloat>
#include<cstdio>
#include<cwchar>
#include<cmath>
#include<ctime>
#include<deque>
#include<queue>
#include<stack>
#include<list>
#include<ios>
#include<map>
#include<set>
#include<new>
#define ll long long
#define pb push_back
#define pob pop_back
#define mp make_pair
#define FILL(a,v) memset((void*)a,v,sizeof(a))
#define FILL0(a) FILL(a,0)
#define FILL1(a) FILL(a,-1)
#define FILLBIG(a) FILL(a,0x7f)
#define ALL(a) (a).begin(),(a).end()
#define Inf ((int)0x7f7f7f7f)
#define Mod 1000000007
#define foreach(it,x) for(__typeof(x.begin()) it=x.begin();it!=x.end();it++)
#define FOR(i,x) for(int i=0;i<x;i++)
#define RFOR(i,x) for(int i=x-1;i>=0;i--)
#define FFOR(i,a,b) for(int i=a;i<b;i++)
#define FRFOR(i,a,b) for(int i=a-1;i>=b;i--)
#define SZ(a) ((int)(a).size())
#define fi first
#define se second
#define OVER(a) return puts(a),0
#define fastio ios::sync_with_stdio(0)
#define filei(f) freopen(f,"r",stdin)
#define fileo(f) freopen(f,"w",stdout)
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#define MASK(a) (1<<(a))
#define MASKX(x,a) ((x)<<(a))
#define BIT(a,b) ((a>>b)&1)
#define cddx(a) priority_queue<a >
#define cxdd(a) priority_queue<a,vector<a >,greater<a > >
#define deval(a) {cerr<<#a<<" = "<<a<<endl;}
#define dearr(be,en) {cerr<<#be;cerr<<" = {";for(auto i=be;i!=en;i++)cerr<<' '<<*i;cerr<<" }\n";}
#define reg register
using namespace std;
typedef pair<int,int> pii;
typedef unsigned long long UINT;
typedef unsigned int uint;
typedef long long INT;
typedef long double ldouble;
typedef pair<INT,INT> PII;
typedef stringstream sst;
typedef istringstream iss;
typedef vector<int> vint;
typedef vector<INT> VINT;
typedef vector<pii> vpii;
typedef vector<PII> VPII;
typedef priority_queue<int> pqi;
typedef priority_queue<INT> PQI;
typedef priority_queue<pii> pqp;
typedef priority_queue<PII> PQP;
typedef priority_queue<int,vint,greater<int> > xqi;
typedef priority_queue<INT,VINT,greater<INT> > XQI;
typedef priority_queue<pii,vpii,greater<pii> > xqp;
typedef priority_queue<PII,VPII,greater<PII> > XQP;
const int INF=1e9+7;
using namespace std;
int n,m;
vector<int> v[100005];
vector<int> path;
string s;
int vis[100005];
int prime(int x)
{
	if (x==1) return 0;
	for (int i=2;i*i<=x;i++)
	if (x%i==0) return 0;
	return 1;
}
int check(int x,int y)
{
	if (x>n||x<1||y>=m||y<0) return 0;
	return 1;
}
long long gcd(long long a, long long b){
    if(b == 0){
        return a;
    }
    return gcd(b, a % b);
}
void dfs(int x)
{
	vis[x]=1;
	path.push_back(x);
	for (int i=0;i<v[x].size();i++)
	if (!vis[v[x][i]])
	{
	    dfs(v[x][i]);
	    return ;
	}
}
int main()
{
	//freopen("input.in","r",stdin);
	//freopen("output.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=m;i++)
	{
		int a,b;
		cin>>a>>b;
		v[a].push_back(b); 
		v[b].push_back(a); 
	}
	dfs(1);
	reverse(path.begin(),path.end());
	int tmp=path.back();
	path.pop_back();
	dfs(tmp);
	cout<<path.size()<<endl;
	for (int i=0;i<path.size();i++)
	cout<<path[i]<<" ";
	return 0;
}