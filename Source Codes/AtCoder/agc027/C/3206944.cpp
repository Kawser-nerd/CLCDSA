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
	 string str;
	 cin>>n>>m>>str;
	 vector<LL> a(m),b(m),s(n+1,0),v(n+1,1);
	 v[0]=0;
	 vector<vector<LL>> cnt=vector<vector<LL>>(n+1,vector<LL>(2,0));
	 vector<vector<LL>> g=vector<vector<LL>>(n+1,vector<LL>());
	 map<pll,int> mp;
	 FOR(i,0,n){
		 if(str[i]=='A'){
			 s[i+1]=1;
		 }
	 }
	 FOR(i,0,m){
		 cin>>a[i]>>b[i];
		 if(mp[MP(a[i],b[i])]==1)continue;
		 mp[MP(a[i],b[i])]=1;
		 mp[MP(b[i],a[i])]=1;
		 g[a[i]].PB(b[i]);
		 g[b[i]].PB(a[i]);
		 cnt[a[i]][s[b[i]]]++;
		 cnt[b[i]][s[a[i]]]++;

		 if(a[i]==b[i])cnt[b[i]][s[b[i]]]+=1000000;
	 }

	 FOR(t,0,2){
		 FORQ(i,1,n){
			 if(v[i]==0||(cnt[i][0]>0&&cnt[i][1]>0))continue;
			 queue<int> bad;
			 bad.push(i);
			 v[i]=0;
			 while(bad.size()){
				 int ii=bad.front();
				 bad.pop();
				 //cerr<<"bad:"<<ii<<endl;
				 int l=g[ii].size();
				 FOR(j,0,l){
					 int nw=g[ii][j];
					 cnt[nw][s[ii]]--;
					 if(v[nw]==1&&cnt[nw][s[ii]]<=0){
						 v[nw]=0;
						 bad.push(nw);
					 }
				 }
			 }
		 }
	 }
	 FORQ(i,1,n){
		 if(v[i]==1){
			 cout<<"Yes"<<endl;
			 return 0;
		 }
	 }
	 cout<<"No"<<endl;

   return 0;
 }