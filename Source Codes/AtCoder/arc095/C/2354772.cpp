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

ll H,W;
vector<string> S;

bool check(vector<int> f){
	vector<string> u;
	for(int j=0; j<W; j++){
		string s;
		for(int i=0; i<H; i++){
			s.push_back(S[f[i]][j]  );
		}
		u.push_back(s);
	}
	vi used(W);
	int center = 0;
	for(int j=0; j<W; j++){
		if(used[j])continue;
		bool ok = false;
		string s1 = u[j];
		reverse(s1.begin(), s1.end());
		for(int k=j+1; k<W; k++){
			if(used[k])continue;
			string s2 = u[k];

			if(s1==s2){
				ok = true;
				used[k]=1;
				break;
			}
		}
		if(!ok){
			if(s1==u[j])center++;
			else return false;
		}
	}
	return center<=1;
}

vector<int> gen(int p){
	int w = H - (H+1)%2;
	//deb(p);deb(w);debl;
	vi used(H);
	vi ret(H);
	if(H%2==1){
		int n = p%w; p/=w; w-=2;
		ret[H/2] = n;
		used[n]=1;
	}
	for(int step=0; step<H/2; step++){
		int k=0;
		while(used[k])k++;
		ret[step]=k;
		used[k]=1;
		k++;		while(used[k])k++;
		//debug(used);
		//debug(ret);
		{
			int n = p%w; p/=w; w-=2;
			//debug(n);
			for(int j=0; j<n; j++){
				k++; while(used[k])k++;
			}
			ret[H-1-step] = k;
			used[k]=1;
		}
	}
	//debug("gen_end");
	return ret;

}

void _main(istream &inp){
	inp >> H >> W;
	rep(ii,H){
		string s;
		inp >> s;
		S.push_back(s);
	}
	int num_of_pat = 1;
	for(int i=1; i<=H; i+=2){
		num_of_pat *= i;
	}
	int cnt = 0;
	//debug("part1");
	for(int p=0; p<num_of_pat; p++){
		vector<int> f = gen(p);
		//debug(f);
		if(check(f))cnt++;
	}
	if(cnt>0){
		cout << "YES" << endl;
	}
	else{
		cout << "NO" << endl;
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