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

int main(int argc, char *argv[]){
	READ(T);
	FOR(t, T){
		READ(n);
		READ(l);
		vector<string> vs(n);
		FOR(i, n) cin>>vs[i];
		string b;
		cin>>b;
		stringstream x,y;
		FOR(i, l-1){
			if(b[i]=='0'){
				x<<"10";
			}else{
				x<<"01";
			}
		}
		if(b.back()=='0'){
			x<<"1";
		}else{
			x<<"0";
		}
		FOR(i, l){
			if(b[i]=='0'){
				y<<"1?";
			}else{
				y<<"0?";
			}
		}
		FOR(i, n){
			if(b==vs[i]){
				cout<<"Case #"<<(t+1)<<": IMPOSSIBLE"<<endl;
				goto next;
			}
		}
		cout<<"Case #"<<(t+1)<<": "<<x.str()<<" "<<y.str()<<endl;
		next: continue;
	}
	
	return 0;
}