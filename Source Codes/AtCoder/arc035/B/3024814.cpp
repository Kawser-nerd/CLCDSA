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
 #define MP make_pair
 #define LL long long
 #define ULL unsigned LL
 #define LD long double
 #define pii pair<int,int>
 #define pll pair<LL,LL>

 const double pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342;
 const int mod=1000000007;

 int main(){
	 int n,t[10101]={};
 	cin>>n;
 	map<int,int> mp;
	LL ans=0LL,c=1LL,nw=0LL;
 	FOR(i,0,n){
 		cin>>t[i];
		mp[t[i]]++;
 	}
	for(auto x:mp){
		LL p=x.ST,q=x.ND,t=1LL;
		FOR(i,0,q){
			nw+=p;
			ans+=nw;
			t=(t*(q-i))%mod;
		}
		c=(c*t)%mod;
	}
	cout<<ans<<endl;
	cout<<c<<endl;
   return 0;
 }