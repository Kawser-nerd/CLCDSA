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

vl a,A,b,B;

ll memo[110][110];
ll rec(int i1, int i2, ll r1, ll r2){
	//deb(i1);deb(i2);deb(r1);deb(r2);debl;
	if(i1==a.size() || i2==b.size())return 0;
	assert(r1<=a[i1] && r2<=b[i2]);
	if(r1==0 && r2==0){
		ll ret=memo[i1][i2];
		if(ret!=-1)return ret;
	}
	ll ans=0;
	if(A[i1]!=B[i2]){
		ans=max(ans, rec(i1+1,i2,0,r2));
		ans=max(ans, rec(i1,i2+1,r1,0));
	}
	else{
		ll v1=a[i1]-r1, v2=b[i2]-r2;
		ll v=min(v1,v2);
		if(v1>v2)ans=v+rec(i1,i2+1,r1+v,0);
		else ans=v+rec(i1+1, i2, 0, r2+v);
	}
	if(r1==0 && r2==0){
		return memo[i1][i2]=ans;
	}
	return ans;
}

void _main(istream &inp){
	int T;
	inp >> T >>ws;
	REP(tt,T){
		a.clear();
		A.clear();
		b.clear();
		B.clear();
		cout << "Case #" << tt+1 << ": ";
		nclr(memo);
		int N,M;
		inp >> N >> M;
		a=vl(N);
		A=vl(N);
		b=vl(M);
		B=vl(M);
		REP(i,N){
			inp >> a[i] >> A[i]; 
		}
		REP(i,M){
			inp >> b[i] >> B[i];
		}
		//debug(a);debug(A);
		//debug(b);debug(B);
		
		ll ret=rec(0,0,0, 0);
		cout << ret << endl;
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