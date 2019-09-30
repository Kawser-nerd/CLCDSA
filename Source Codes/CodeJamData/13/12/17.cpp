#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<string>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<string>

using namespace std;

#define s(n)					scanf("%d",&n)
#define sl(n) 					scanf("%lld",&n)
#define sf(n) 					scanf("%lf",&n)
#define ss(n) 					scanf("%s",n)
#define sc(n)                   {char temp[4]; ss(temp); n=temp[0];}
#define INF						(int)1e9
#define LINF					(long long)1e18
#define EPS						1e-9
#define maX(a,b)				((a)>(b)?(a):(b))
#define miN(a,b)				((a)<(b)?(a):(b))
#define abS(x)					((x)<0?-(x):(x))
#define foreach(v,c)            for( typeof((c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define mp						make_pair
#define FF						first
#define SS						second
#define tri(a,b,c)				mp(a,mp(b,c))
#define XX						first
#define YY						second.first
#define ZZ						second.second
#define pb						push_back
#define fill(a,v) 				memset(a,v,sizeof a)
#define all(x)					x.begin(),x.end()
#define SZ(v)					((int)(v.size()))
#define DREP(a)					sort(all(a)); a.erase(unique(all(a)),a.end())
#define INDEX(arr,ind)			(lower_bound(all(arr),ind)-arr.begin())


#define debugger cerr
#define debug(args...)			{mdbg,args; debugger<<endl;}
#define PRINT_CONTAINER(o,v)    {if(v.size()==0) return o<<"{}"; o<<"{"; foreach(it,v) o<<*it<<" "; return o<<"\b}";}
struct multidebug {template<typename T> multidebug& operator , (const T &v) {debugger<<v<<" "; return *this;}} mdbg;
template<class T> ostream& operator << (ostream& o,const vector<T> &v) PRINT_CONTAINER(o,v)
template<class T> ostream& operator << (ostream& o,const set<T> &v) PRINT_CONTAINER(o,v)
template<class A,class B> ostream& operator << (ostream& o,const map<A,B> &v) PRINT_CONTAINER(o,v)
template<class A,class B> ostream& operator << (ostream& o,const pair<A,B> &p) {o<<"("<<p.first<<","<<p.second<<")"; return o;}
template<class T> void debugarr(T* v,int n) {debugger<<"{"; for(int i=0;i<n;i++) debugger<<v[i]<<" "; debugger<<"\b}"<<endl;}


typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef pair<int,PII> TRI;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VII;
typedef vector<TRI> VT;




/*Main code begins now */
int testnum;

LL E,R;
int N;
LL v[10005];
LL spend[10005];
LL reqd[10005];

void doit(int ind, int a, LL ae, int b, LL be) {
	LL cure = ae + R*(ind-a);
	if(cure > E) cure = E;
	LL nxte = be - R*(b-ind);
	if(nxte < 0) nxte = 0;
	
	LL z = max(0LL, cure-nxte);
	spend[ind] = z;
	reqd[ind] = cure;
	
	//debug(ind, a, ae, b, be, " : ", cure, nxte, z);
}

void solve()
{
	fill(reqd,-1);
	fill(spend,0);
	reqd[0] = E;
	reqd[N+1] = 0;
	VII arr;
	for(int i=1; i<=N; i++) arr.pb(mp(-v[i],i));
	sort(all(arr));
	for(int i=0; i<N; i++) {
		int ind = arr[i].SS;
		int a=-1;
		int b=-1;
		for(int j=ind-1; j>=0; j--) {
			if(reqd[j]>=0) {
				a=j;
				break;
			}
		}
		for(int j=ind+1; j<=N+1; j++) {
			if(reqd[j]>=0) { 	
				b=j;
				break;
			}
		}
		
		doit(ind, a, reqd[a]-spend[a], b, reqd[b]);
	}
	
	LL ans = 0;
	for(int i=1; i<=N; i++)
		ans += spend[i] * v[i];
	printf("Case #%d: ", testnum);
	printf("%lld\n",ans);
	
	fprintf(stderr, "Case #%d: %lld\n",testnum,ans);
		
	
}

bool input()
{
	sl(E); sl(R); s(N);
	for(int i=1;i<=N;i++) sl(v[i]);
	v[0]=0;
	v[N+1]=0;
	
	return true;
}


int main()
{
	int T; s(T);
	for(testnum=1;testnum<=T;testnum++)
	{
		if(!input()) break;
		solve();
	}
}
