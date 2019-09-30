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

std::hash<std::string> hash_fn;

double getTime(){
	return (double)clock()/(double)CLOCKS_PER_SEC;
}

int main(int argc, char *argv[]){
	READ(T);
	FOR(t, T){
		READ(n);
		READV(pre,n);
		vector<char> vc(n);
		FOR(i, n) cin>>vc[i];
		READ(m);
		vector<string> words(m );
		FOR(i, m) cin>>words[i];

		auto begin = getTime();
		vi found(m, 0);
		double repeats = 0;
		set<ll> hashed;

		vector<int> compsize(n,0);
		FOR(i,n){
			int a = i;
			while(pre[a]!=0){
				compsize[a]++;
				a=pre[a]-1;
			}
			compsize[a]++;
		}
		while(getTime()-begin<1.5){
			
			vpii possible;
			possible.reserve(n);
			vector<int> completed(n, 0);
			stringstream ss, rr;
			FOR(k,n){
				possible.clear();
				int w = 0;
				FOR(i,n){
					if(completed[i]) continue;
					if(pre[i]!=0 && !completed[pre[i]-1]) continue;
					possible.pb(mp(i, compsize[i]));
					w+=compsize[i];
				}
				int r = rand()%w;
				int i = 0;
				int a = 0;
				while(true){
					if(r<possible[i].ss){
						a = possible[i].ff;
						break;
					}
					r-=possible[i].ss;
					i++;
				}
				//cerr<<a<<endl;
				completed[a]=1;
				ss<<vc[a];
				rr<<"."<<a;
			}
			//cerr<<ss.str()<<endl;
			ll hash = hash_fn(rr.str());
			if(hashed.insert(hash).second){
				repeats++;
				string s = ss.str();
				FOR(i,m){
					if(s.find(words[i]) != std::string::npos){
						found[i]++;
					}
				}
			}
		}
		cerr<<repeats<<endl;
		cout<<"Case #"<<(t+1)<<":";
		FOR(i, m){
			cout<<" "<<((double)found[i]/repeats);
		}
		cout<<endl;
		next: continue;
	}
	
	return 0;
}