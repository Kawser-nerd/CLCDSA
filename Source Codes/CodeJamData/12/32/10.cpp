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
 
void _main(istream &inp){
	int T;
	inp >> T >>ws;
	REP(tt,T){
		cout << "Case #" << tt+1 << ":" << endl;
		double D;
		int N,A;
		inp >> D >> N >> A;
		vd ts(N), xs(N);
		vd as(A);
		REP(i,N){
			inp >> ts[i] >> xs[i] ;
		}
		REP(i,A){
			inp >> as[i];
		}
		vd tc,xc;
		REP(i,N){
			if(xs[i]<=D){
				tc.pb(ts[i]);
				xc.pb(xs[i]);
			}
			else if(i>=1 && xs[i-1]<=D){
				double p=(D-xs[i-1])/(xs[i]-xs[i-1]);
				tc.pb(ts[i-1]+p*(ts[i]-ts[i-1]));
				xc.pb(D);
			}
		}
		//debug(tc);debug(xc);
		REP(ia,as.size()){
			double a=as[ia];
			double rem=0.0;
			REP(i,xc.size()){
				double t=sqrt(2*xc[i]/a);
				rem=max(rem, tc[i]-t);
			}
			printf("%.18f\n", sqrt(2*D/a)+rem);
		}
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