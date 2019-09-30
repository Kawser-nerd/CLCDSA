#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <numeric>
#include <valarray>
#include <complex>
using namespace std;

const double eps=1e-9;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef pair<double, double> pdd;
typedef vector<pdd> vpdd;
typedef complex<double> pnt;
typedef vector<pnt> vpnt;
typedef vector<vector<pair<int, long long> > > Graph;

#define fr(i,a,b) for(int i(a),_b(b);i<=_b;++i)
#define frd(i,a,b) for(int i(a),_b(b);i>=_b;--i)
#define rep(i,n) for(int i(0),_n(n);i<_n;++i)
#define repd(i,n) for(int i((n)-1);i>=0;--i)
#define reps(i,a) fr(i,0,sz(a)-1)
#define all(a) a.begin(),a.end()
#define pb push_back
#define mp make_pair
#define fore(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define maximum(a) (*max_element(all(a)))
#define minimum(a) (*min_element(all(a)))
#define clr(x,a) memset(x,a,sizeof(x))
#define findx(a,x) (find(all(a),x)-a.begin())
#define two(X) (1LL<<(X))
#define contain(S,X) (((S)&two(X))!=0)

template<class T> void print(T const &x) {ostringstream os; os<<x; cout<<os.str()<<endl;}
template<class T> void print(vector<T> const &v) {ostringstream os; for(int i=0; i<v.size(); ++i){if(i)os<<' ';os<<v[i];} cout<<os.str()<<endl;}
template<class T> void print(vector<vector<T> > const &v){ostringstream os; for(int i=0;i<v.size();++i) {for(int j=0;j<v[i].size();++j){if(j)os<<' ';os<<v[i][j];}os<<endl;}cout<<os.str()<<endl;}
template<class T> void print(valarray<T> const &v) {ostringstream os; for(int i=0; i<v.size(); ++i){if(i)os<<' ';os<<v[i];} cout<<os.str()<<endl;}
template<class T> int sz(const T&c){return (int)c.size();}
template<class T> void srt(T&c){std::sort(c.begin(),c.end());}
template<class T> void checkmin(T &a,T b){if(b<a) a=b;}
template<class T> void checkmax(T &a,T b){if(b>a) a=b;}
template<class T> T sqr(T x){return x*x;}
template<class T, class U> T cast (U x) { ostringstream os; os<<x; T res; istringstream is(os.str()); is>>res; return res; }
template<class T> vector<T> split(string s, string x=" ") {vector<T> res; for(int i=0;i<s.size();i++){string a; while(i<(int)s.size()&&x.find(s[i])==string::npos)a+=s[i++]; if(!a.empty())res.push_back(cast<T>(a));} return res;}
template<class T> T inside(T r,T c,T R, T C){return r>=0 && r<R && c>=0 && c<C;}
const int dr[]={-1,0,0,1};
const int dc[]={0,-1,1,0};

int h,w;
vvi a;
vs m;
char label;

char dfs(int i,int j){
	if(m[i][j]!=' ')return m[i][j];

	int besti=-1,bestj=-1,bestv=INT_MAX;
	rep(d,4){
		int i1=i+dr[d];
		int j1=j+dc[d];
		if(inside(i1,j1,h,w) && bestv>a[i1][j1])bestv=a[i1][j1],besti=i1,bestj=j1;
	}
	if(bestv<a[i][j]){
		return m[i][j]=dfs(besti,bestj);
	}
	return m[i][j]=++label;
}

int main( int argc, char* argv[] ) {
	freopen("C:/codejam/B-large.in","r",stdin);
	freopen("C:/codejam/B-large.out", "w", stdout);

	int testCases;
	cin>>testCases;
	for(int testCase=1;testCase<=testCases;testCase++){		
		cin>>h>>w;

		a.assign(h,vi(w,0));
		rep(i,h)rep(j,w)cin>>a[i][j];

		m.assign(h,string(w,' '));
		label='a'-1;

		rep(i,h)rep(j,w)if(m[i][j]==' ')dfs(i,j);

		cout << "Case #" << testCase << ": " << endl;
		rep(i,h){
			rep(j,w){
				if(j)cout<<" ";			
				cout<<m[i][j];
			}
			cout<<endl;
		}
		cout.flush();
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
