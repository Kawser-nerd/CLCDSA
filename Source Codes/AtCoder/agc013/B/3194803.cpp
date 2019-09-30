#include <cstdio>
 #include <cstdlib>
 #include <iostream>
 #include <fstream>
 #include <sstream>
 #include <set>
 #include <map>
 #include <vector>
 #include <list>
 #include <algorithm>
 #include <cstring>
 #include <cmath>
 #include <string>
 #include <queue>
 #include <bitset>     //UWAGA - w czasie kompilacji musi byc znany rozmiar wektora - nie mozna go zmienic
 #include <cassert>
 #include <iomanip>        //do setprecision
 #include <ctime>
 #include <complex>
 using namespace std;

 #define FOR(i,b,e) for(int i=(b);i<(e);++i)
 #define FORQ(i,b,e) for(int i=(b);i<=(e);++i)
 #define FORD(i,b,e) for(int i=(b)-1;i>=(e);--i)
 #define REP(x, n) for(int x = 0; x < (n); ++x)

 #define ST first
 #define ND second
 #define PB push_back
 #define PF push_front
 #define MP make_pair
 #define LL long long
 #define ULL unsigned LL
 #define LD long double
 #define pii pair<int,int>
 #define pll pair<LL,LL>

 const double pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342;
 const int mod=1000000007;

int main(){
	int n,m;
	cin>>n>>m;
	vector<int> a,b,v(n+1,0);
	vector<vector<int>> g=vector<vector<int>>(n+1,vector<int>());
	deque<int> path;
	int s=-1,t=-1;
	FOR(i,0,m){
		int aa,bb;
		cin>>aa>>bb;
		a.PB(aa);b.PB(bb);
		g[aa].PB(bb);
		g[bb].PB(aa);
		if(s==-1){
			s=aa;
			t=bb;
		}
	}
	cerr<<"test"<<endl;
	v[s]=1;v[t]=1;
	path.PF(s);
	path.PB(t);
	while(1){
		LB:
		a=a;
		for(auto x:g[s]){
			if(v[x]==0){
				s=x;
				v[x]=1;
				path.PF(x);
				goto LB;
			}
		}
		for(auto x:g[t]){
			if(v[x]==0){
				t=x;
				v[x]=1;
				path.PB(x);
				goto LB;
			}
		}
		break;
	}
	cout<<path.size()<<endl;
	while(path.size()>1){
		cout<<path.front()<<" ";
		path.pop_front();
	}
	cout<<path.front()<<endl;
	return 0;
}