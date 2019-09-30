#pragma comment(linker, "/STACK:512000000")
#define _CRT_SECURE_NO_DEPRECATE
#define _USE_MATH_DEFINES
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <climits>
#include <ctime>
#include <numeric>
#include <vector>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <complex>
#include <deque>
#include <functional>
#include <list>
#include <map>
#include <string>
#include <sstream>
#include <set>
#include <stack>
#include <queue>
using namespace std;
typedef long long lng;
typedef unsigned long long ulng;
typedef unsigned int uint;
typedef unsigned char uchar;
typedef long double ld;
typedef pair<int, int> PII;
typedef pair<short, short> PSS;
typedef pair<PII, int> PIII;
typedef pair<lng, lng> PLL;
typedef pair<ulng, ulng> PUU;
typedef pair<lng, int> PLI;
typedef pair<int, lng> PIL;
typedef pair<ld, ld> PDD;
template<class T> inline T sqr(T x) { return x * x; }
template<class T> inline string tostr(const T & x) { stringstream ss; ss << x; return ss.str(); }
inline lng parse(const string & s) { stringstream ss(s); lng x; ss >> x; return x; }
#define left asdleft
#define right asdright
#define link asdlink
//#define unlink asdunlink
#define next asdnext
#define prev asdprev
#define y0 asdy0
#define y1 asdy1
#define mp make_pair
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define clr(ar,val) memset(ar, val, sizeof(ar))
#define istr stringstream
#define forn(i,n) for(int i=0;i<(n);++i)
#define forv(i,v) forn(i,sz(v))
#define X first
#define Y second
#define hash asdhash
#define move asdmove
const ld EPS = 1e-12;
const int INF = 1000*1000*1000;
const char CINF = 102;
const lng LINF = INF * 1ll * INF;
const ld DINF = 1e200;
const ld PI = 3.1415926535897932384626433832795l;
int gcd(int a,int b){return a?gcd(b%a,a):b;}
lng gcd(lng a,lng b){return a?gcd(b%a,a):b;}
lng powmod(lng a,lng p,lng m){lng r=1;while(p){if(p&1)r=r*a%m;p>>=1;a=a*a%m;}return r;}
#define TASKA "iota"

struct edge{
	int v,i;
	int cap,cost;
};

struct graph{
	vector<vector<edge> > gr;
	vector<int> P;
	int S,T;
	
	graph(int n):gr(n),P(n){}
	
	void add(int a,int b,int cap,int cost){
		edge e1={b,sz(gr[b]),cap,cost};
		edge e2={a,sz(gr[a]),0,-cost};
		gr[a].pb(e1);
		gr[b].pb(e2);
	}
	
	int augment(){
		vector<pair<int,PII> > D(sz(gr),mp(INF,mp(-1,-1)));
		D[S].X=0;
		priority_queue<PII> qu;
		qu.push(mp(-0+P[S],S));
		while(!qu.empty()){
			int v=qu.top().Y;
			int d=-qu.top().X+P[v];
			qu.pop();
			if(d!=D[v].X)
				continue;
			forv(i,gr[v]){
				edge &e=gr[v][i];
				if(e.cap<0)
					exit(123);
				if(!e.cap)
					continue;
				if(d+e.cost<D[e.v].X){
					D[e.v]=mp(d+e.cost,mp(v,i));
					qu.push(mp(-D[e.v].X+P[e.v],e.v));
				}
			}
		}
		
		if(D[T].X==INF)
			return 0;
		
		int f=INF;
		{
			int v=T;
			while(v!=S){
				int i=D[v].Y.Y;
				v=D[v].Y.X;
				f=min(f,gr[v][i].cap);
			}
		}
		
		int res=0;
		{
			//vector<int> path(1,T);
		
			int v=T;
			while(v!=S){
				int i=D[v].Y.Y;
				v=D[v].Y.X;
				res+=gr[v][i].cost*f;
				gr[v][i].cap-=f;
				gr[gr[v][i].v][gr[v][i].i].cap+=f;
				
				//path.pb(v);
			}
			
			/*
			reverse(all(path));
			cout<<"augmenting";
			forv(i,path){
				cout<<' '<<path[i];
			}
			cout<<": "<<f<<' '<<res<<endl;//*/
		}
		
		forv(i,P){
			P[i]=D[i].X;
		}
		
		return res;
	}
	
	int mincost(){
		int r=0;
		while(true){
			int c=augment();
			if(c>=0)
				break;
			r+=c;
		}
		return r;
	}
};

vector<pair<char,int> > A;
int ans;
const int B=11000;

void solve(){
	graph G(sz(A)+2);
	G.S=sz(A);
	G.T=sz(A)+1;
	int need=0;
	ans=0;
	forv(i,A){
		if(A[i].Y){
			if(A[i].X=='E'){
				int ii=i+1;
				while(ii<sz(A) && A[ii].Y!=A[i].Y)
					++ii;
				bool req=true;
				if(ii<sz(A) && A[ii].X=='L'){
					req=false;
					G.add(i,ii,1,0);
				}else if(ii<sz(A))
					++need;
				else
					req=false;
				for(int k=i+1;k<ii;++k){
					if(A[k].X=='L' && !A[k].Y){
						G.add(i,k,1,req?-B:0);
						break;
					}
				}
			}else{
				int ii=i-1;
				while(ii>=0 && A[ii].Y!=A[i].Y)
					--ii;
				bool req=true;
				if(ii>=0 && A[ii].X=='E'){
					req=false;
				}else if(ii>=0)
					++need;
				else
					req=false;
				for(int k=i-1;k>ii;--k){
					if(A[k].X=='E' && !A[k].Y){
						G.add(k,i,1,req?-B:0);
						break;
					}
				}
			}
		}else{
			int ii=i+1;
			while(ii<sz(A) && A[ii]!=A[i])
				++ii;
			if(ii<sz(A))
				G.add(i,ii,B,0);
				
			if(A[i].X=='E'){
				ii=i+1;
				while(ii<sz(A) && A[ii]!=mp('L',0))
					++ii;
				if(ii<sz(A))
					G.add(i,ii,1,0);
			}
		}
		if(A[i].X=='E'){
			G.add(G.S,i,1,0);
			++ans;
		}else{
			G.add(i,G.T,1,-1);
		}
	}
	
	G.P[G.S]=B*2;
	forv(i,A){
		G.P[i]=-B*2*i;
	}
	G.P[G.T]=-B*2*sz(A);
	
	int r=G.mincost();
	if(r>-need*B){
		ans=-1;
		return;
	}
	ans-=-need*B-r;
}

void input(){
	int n;
	cin>>n;
	A.resize(n);
	forn(i,n){
		cin>>A[i].X>>A[i].Y;
	}
}

void output(){
	if(ans==-1)
		cout<<"CRIME TIME\n";
	else
		cout<<ans<<endl;
}

int doit(int a,int mx){
	if(a==sz(A)){
		vector<char> in(mx+1, 2);
		int d=0;
		int mind=0;
		forv(i,A){
			if(A[i].Y){
				if(in[A[i].Y] !=2 && ((A[i].X=='L') != in[A[i].Y]))
					return INF;
				in[A[i].Y]=A[i].X=='E';
			}else{
				d+=A[i].X=='E'?1:-1;
				mind=min(mind,d);
			}
		}
		int r=0;
		forv(i,in){
			if(in[i]==1)
				++r;
		}
		r+=d-mind;
		return r;
	}
	if(A[a].Y)
		return doit(a+1,mx);
	int r=INF;
	for(A[a].Y=0;A[a].Y<=mx;++A[a].Y){
		r=min(r,doit(a+1,mx));
	}
	A[a].Y=0;
	return r;
}

int brute(){
	auto A0=A;
	
	vector<int> vs;
	vs.pb(0);
	forv(i,A){
		vs.pb(A[i].Y);
	}
	sort(all(vs));
	vs.erase(unique(all(vs)),vs.end());
	forv(i,A){
		A[i].Y=lower_bound(all(vs),A[i].Y)-vs.begin();
	}

	int mx=0;
	forv(i,A){
		mx=max(mx,A[i].Y);
	}
	
	int lim=1000000;
	forv(i,A){
		if(A[i].Y==0)
			lim/=(mx+1);
	}
	if(!lim){
		A=A0;
		return -2;
	}
	
	int r=doit(0,mx);
	if(r==INF)
		r=-1;
	A=A0;
	return r;
}

int main(){
#ifdef __ASD__
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen(TASKA".in", "r", stdin); freopen(TASKA".out", "w", stdout);
#endif
	
	int tc;
	cin>>tc;
	forn(qqq,tc){
		cerr<<qqq<<endl;
		input();
		solve();
		cout<<"Case #"<<qqq+1<<": ";
		output();
		
		//*
		int b=brute();
		if(b==-2)
			cerr<<"not tested "<<qqq<<endl;
		else if(ans!=b){
			cout<<"failed "<<qqq<<": "<<b<<' '<<ans<<endl;
			cout<<1<<endl;
			cout<<sz(A)<<endl;
			forv(i,A){
				cout<<A[i].X<<' '<<A[i].Y<<endl;
			}
			return 1;
		}//*/
	}
	
	return 0;
}
