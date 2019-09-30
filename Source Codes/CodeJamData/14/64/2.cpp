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
#include <mutex>
#include <thread>
using namespace std;
typedef long long lng;
typedef unsigned long long ulng;
typedef unsigned int uint;
typedef unsigned char uchar;
typedef double ld;
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
#define unlink asdunlink
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
const ld EPS = 1e-9;
const int INF = 1000*1000*1000;
const char CINF = 102;
const lng LINF = INF * 1ll * INF;
const ld DINF = 1e200;
const ld PI = 3.1415926535897932384626433832795l;
int gcd(int a,int b){return a?gcd(b%a,a):b;}
lng gcd(lng a,lng b){return a?gcd(b%a,a):b;}
lng powmod(lng a,lng p,lng m){lng r=1;while(p){if(p&1)r=r*a%m;p>>=1;a=a*a%m;}return r;}
#define FAIL { log() << "failed assertion on line " << __LINE__; exit(1); }

ostream& log() { return cerr; }

struct sol{
	int tc;
	stringstream out;
	ostream& log(){cerr<<tc<<": ";return cerr;}

	vector<string> A;
	int v0;

	sol(int tc):tc(tc){
		int n;
		cin>>n>>v0;
        A.resize(n);
        forn(i,n){
			cin>>A[i];
		}
	}

#define NOPE { out << "IMPOSSIBLE"; log() << __LINE__ << endl; return; }

	vector<char> can;
	vector<char> was;

	void dfs(int v,int d){
		if(was[v] || !can[v])
			return;
		was[v]=true;
		forv(p,A){
			if(A[v][p]=='Y')
				dfs(p,d+1);
		}
	}

	bool check(int vv){
		if(vv==v0){
			forv(i,A){
				if(can[i] && A[i][vv]=='Y')
					return false;
			}
			return true;
		}

		was.assign(sz(A),0);
		dfs(v0,0);
		bool f=false;
		forv(i,was){
			if(!was[i] && can[i] && A[vv][i]!='Y')
				return false;
			if(can[i] && A[i][vv]=='Y')
				f=true;
        }
		return f;
	}

	void solve(){
		can.resize(sz(A),1);
		vector<int> ans(sz(A));
		int vv=-1;
		forv(i,A){
			bool f=false;
			for(ans[i]=0;ans[i]<sz(A);++ans[i]){
				if(!can[ans[i]])
					continue;
				can[ans[i]]=false;
				int vvv=vv;
				if(vv==-1 || A[ans[i]][vv]=='Y')
					vvv=ans[i];
				if(check(vvv)){
					f=true;
					vv=vvv;
					break;
				}
				can[ans[i]]=true;
			}
			if(!f){
				if(i)
					FAIL
				else
					NOPE
			}
		}
		forv(i,ans){
			out<<ans[i]<<' ';
		}
	}
};

const int THREADS=1;
int main(){
#ifdef __ASD__
	freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);
#endif

	vector<thread> ts(THREADS);
	int tc;
	cin>>tc;
	vector<string> ans(tc);
	int ti=0;
	mutex m;
	forv(i,ts){
		ts[i]=thread([&]{
			while(true){
				unique_ptr<sol> s;
				{
					unique_lock<mutex> l(m);
					if(ti==tc)
						break;
					s.reset(new sol(ti++));
					cerr<<s->tc<<" started"<<endl;
				}
				s->solve();
				ans[s->tc]=s->out.str();
				cerr<<s->tc<<" finished"<<endl;
			}
		});
	}
	forv(i,ts)
		ts[i].join();

	forv(i,ans){
		cout<<"Case #"<<i+1<<": "<<ans[i]<<endl;
	}

	return 0;
}
