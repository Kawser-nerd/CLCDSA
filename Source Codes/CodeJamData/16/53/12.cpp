#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <queue>
#include <cstring>
#include <string>
#include <complex>
#include <unordered_map>
#include <valarray>

#define vi vector<int>
#define vpii vector< pair<int,int> >
#define pii pair<int,int>
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define FOREACH(it,x) for (auto it = (x).begin(); it!=(x).end(); ++it) 
#define sz(x) (int)(x).size()
#define sqr(x) ((x)*(x))
#define FOR(i,n) for (ll i = 0; i < ll(n); i++)
#define ROF(i,n) for (ll i = ((ll)n-1); i >= 0; i--)
#define FOR1(i,n) for (ll i = 1; i < ll(n); i++)
#define REP(i,a,b) for (ll i = a; i < ll(b); i++)
#define READ(a) int a; scanf("%d", &a);
#define READV(v,n) vi v(n);FOR(i,n){scanf("%d", &v[i]);}
#define WRITE(v) FOR(i,sz(v))cout<<v[i]<<" ";
#define gmin(a,b) { if (b < a) a = b; }
#define gmax(a,b) { if (b > a) a = b; }
#define pb push_back
#define ff first
#define ss second
#define oo ((1LL<<62)+((1LL<<31)-1))
#define MOD 1000000007ll
const double PI = std::atan(1.0)*4;

typedef long long ll;
typedef unsigned long long ull;
using namespace std;



struct A{
public:
	int x,y,z;
	A(int a, int b, int c){
		x=a;
		y=b;
		z=c;
	}

};

double getdist(A& a, A& b){
	return sqrt(sqr(a.x-b.x) + sqr(a.y-b.y) + sqr(a.z-b.z));
}

vector<A> v;
int n;
vector<vector<double> > dist;

bool check(double c){
	queue<int> q;
	vector<int> used(n, 0);
	q.push(0);
	used[0]=1;
	while(!q.empty()){
		int a = q.front(); q.pop();
		if(a==1) return true;
		FOR(i, n){
			if(used[i]) continue;
			if(dist[a][i]<=c){
				q.push(i);
				used[i]=1;
			}
		}
	}
	return false;
}

int main(int argc, char *argv[]){
	READ(T);
	FOR(t, T){
		cin>>n;
		READ(s);
		v.clear();
		FOR(i, n){
			int a,b,c;
			cin>>a>>b>>c;
			v.pb(A(a,b,c));
			cin>>a>>b>>c;
		}
		dist = vector<vector<double> >(n);
		FOR(i, n){
			FOR(j, n){
				dist[i].pb(getdist(v[i],v[j]));
			}
		}
		double a = 0;
		double b = 4000;
		while(abs(a-b)>0.000002){
			double c = (a+b)/2;
			if(check(c)){
				b=c;
			}else{
				a=c;
			}
		}
		cout<<setprecision(12)<<"Case #"<<(t+1)<<": "<<((a+b)/2)<<endl;
		next: continue;
	}
	
	return 0;
}