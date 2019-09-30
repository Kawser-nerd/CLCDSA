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

int R,N,M,K;
LL prod[20];

LL cur[20];
double fact[20];
int cnt[10];

LL best[20];
LL bestprob;

map<int,int> freq[20000];
double base[20000];
int store[20000][20];

int top;

void doit() {

	fill(cnt,0);
	for(int i=0;i<N;i++)
		cnt[cur[i]]++;
	double ans = 1.0;
	for(int i=2;i<=8;i++)
	{
		ans = ans * fact[cnt[i]];
		//if(cnt[i]>5) return;
	}
	base[top] = ans;
	for(int i=0; i<N; i++)
		store[top][i] = cur[i];
		
	map<int,int> dict;
	for(int mask=0; mask<(1<<N); mask++) {
		LL p=1;
		for(int i=0;i<N;i++) {
			if(mask&(1<<i)) {
				p *= cur[i];
			}
		}
		dict[p]++;
	}
	freq[top] = dict;
	top++;
	if(top%100 == 0) debug(top);
}

void recurse(int ind) {
	if(ind==N) {
		doit();
		return;
	}
	
	int beg = 2;
	if(ind>0) beg = cur[ind-1];
	for(int i=beg; i<=M; i++) {
		cur[ind]=i;
		recurse(ind+1);
	}
}		
			
double getProb(int ind) {
	double ans = base[ind];
	map<int,int> &dict = freq[ind];
	for(int i=0; i<K; i++) {
		ans = ans * dict[prod[i]];
		if(ans == 0) return ans;
	}
	return ans;
}

void solve()
{
	bestprob=-1;

	sort(prod, prod+K);
	reverse(prod, prod+K);
	
	for(int i=0;i<top;i++) {
		double z = getProb(i);
		if(z > bestprob) {
			bestprob=z;
			for(int j=0; j<N; j++) {
				best[j] = store[i][j];
			}
		}
	}
	
	
	for(int i=0;i<N;i++)
		printf("%d",best[i]);
	printf("\n");
	
	if(testnum%100 == 0)
		debug(testnum);
}

bool input()
{
	for(int i=0;i<K;i++)
		sl(prod[i]);
	
	return true;
}


int main()
{
	int T; s(T);
	printf("Case #1:\n");
	s(R); s(N); s(M); s(K);
	
	fact[0]=1;
	for(int i=1;i<20;i++)
		fact[i] = fact[i-1]/i;
		
	top=0;
	recurse(0);
	
	for(testnum=1;testnum<=R;testnum++)
	{
		if(!input()) break;
		solve();
	}
}
