#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <cstring>
#include <assert.h>
#include <sys/time.h>
#include <fstream>
 
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
 
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
#define deb(x) cerr << #x << " = " << (x) << " , ";
#define debl cerr << " (L" << __LINE__ << ")"<< endl;
 
 
#define clr(a) memset((a),0,sizeof(a))
#define nclr(a) memset((a),-1,sizeof(a))
#define pb push_back
#define INRANGE(x,s,e) ((s)<=(x) && (x)<(e))
 
double pi=3.14159265358979323846;
 
using namespace std;
static const double EPS = 1e-5;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<string> vs;
 
template<typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& z){
	os << "[ ";
	REP(i,z.size())os << z[i] << ", " ;
	return ( os << "]" << endl);
}
 
template<typename T> std::ostream& operator<<(std::ostream& os, const set<T>& z){
	os << "set( "; 
	EACH(p,z)os << (*p) << ", " ;
	return ( os << ")" << endl);
}
 
template<typename T,typename U> std::ostream& operator<<(std::ostream& os, const map<T,U>& z){
	os << "{ "; 
	EACH(p,z)os << (p->first) << ": " << (p->second) << ", " ;
	return ( os << "}" << endl);
}
 
template<typename T,typename U> std::ostream& operator<<(std::ostream& os, const pair<T,U>& z){
	return ( os << "(" << z.first << ", " << z.second << ",)" );
}
 
double get_time(){
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return tv.tv_sec + tv.tv_usec*1e-6;
}

vvi G;
vi cnt;
bool diamond;

void f(int v){
	if(cnt[v]){
		diamond=true;
		return;
	}
	cnt[v]++;
	REP(i,G[v].size())f(G[v][i]);
}

void _main(istream &inp){
	int T;
	inp >> T >>ws;
	REP(tt,T){
		cout << "Case #" << tt+1 << ": ";
		int N;
		inp >> N;
		G=vvi(N);
		REP(i,N){
			int m;
			inp >> m;
			REP(j,m){
				int v;
				inp >> v;
				v--;
				G[i].pb(v);
			}
		}
		//debug(G);
		diamond=false;
		REP(i,N){
			cnt=vi(N);
			f(i);
		}
		if(diamond) cout << "Yes" << endl;
		else cout << "No" << endl;
	}

 
}
 
int main(){
	if(0){
		ifstream ifs("test.txt");
		_main(ifs);
	}
	else{
		_main(cin);
	}
	return 0;
}