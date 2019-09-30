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
#define rep(i,n)  FOR(i,0,n)
#define REP(i,n)  FOR(i,0,n)
#define each(i,c) for(auto i=(c).begin(); i!=(c).end(); ++i)
#define EACH(i,c) for(auto i=(c).begin(); i!=(c).end(); ++i)
#define exist(s,e) ((s).find(e)!=(s).end())

#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
#define deb(x) cerr << #x << " = " << (x) << " , ";
#define debl cerr << " (L" << __LINE__ << ")"<< endl;
#define sz(s) (int)((s).size())


#define clr(a) memset((a),0,sizeof(a))
#define nclr(a) memset((a),-1,sizeof(a))
#define pb push_back
#define INRANGE(x,s,e) ((s)<=(x) && (x)<(e))
#define MP(x,y) make_pair((x),(y))

double pi=3.14159265358979323846;

using namespace std;
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

typedef unsigned int uint32_t;
struct RND{
	uint32_t x;
	uint32_t y;
	uint32_t z;
	uint32_t w;
	RND(){
		x=123456789;
		y=362436069;
		z=521288629;
		w=88675123;
	}
	void init(int seed){
		x=123456789;
		y=362436069;
		z=521288629;
		w=seed+100;
		REP(i,10)get();
	}
	uint32_t get(){
		uint32_t t;
		t=x^(x<<11);
		x=y;y=z;z=w;
		w=(w^(w>>19))^(t^(t>>8));
		return w;
	}
};
RND rnd;

int N;
vector<int> visit;
int g[800][800];
vector<int> G[800];
bool possible = true;

int cnt[2];
void rec(int v, int color){
//	deb(v);deb(color);debl;
	if(visit[v]!=-1){
		if(visit[v]!=color)possible = false;
		return;
	}
	visit[v]=color;
	cnt[color]+=1;
	rep(y,N) if(y!=v && g[v][y]==0){
		rec(y, 1-color);
	}
}

void _main(istream &inp){
	inp >> N;
	visit = vector<int>(N,-1);
	int M;
	inp >> M;
	clr(g);
	rep(i,M){
		int x,y;
		inp >> x >> y;
		x--;
		y--;
		g[x][y]=1;
		g[y][x]=1;
	}
	set<int> state;
	state.insert(0);
	rep(x,N) if(visit[x]==-1){
		rep(j,2) cnt[j]=0;
		rec(x,0);
//		deb(x);deb(visit);debl;deb(cnt[0]);deb(cnt[1]);debl;
		set<int> new_state;
		for(int m:state){
			new_state.insert(m+cnt[0]);
			new_state.insert(m+cnt[1]);
		}
		state = new_state;
	}
	if(!possible){
		cout << -1 << endl;
		return;
	}
	ll ret = 1e9;
	for(int m:state){
		ll val = m*(m-1)/2+(N-m)*(N-m-1)/2;
		ret=min(ret, val);
	}
	cout << ret << endl;


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