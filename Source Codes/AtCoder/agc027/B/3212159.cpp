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
	 LL n,x;
	 cin>>n>>x;
	 vector<LL> d(n),dd(n+1,0);
	 LL ans=2*n*x,as=(n+1)*x;
	 FOR(i,0,n){
		 cin>>d[i];
		 ans+=5*d[i];
		 dd[i+1]=d[i];
		 dd[i+1]+=dd[i];
	 }

	 FOR(t,1,n){//???????
		 LL scr=n*x+t*x;
		 int tmp=n-t;
		 int mx=(n+t-1)/t;
		 int mn=n/t;
		 int last=n%t;
		 int range=0;
		 if(mx>=2)range=(n-last)/mn;
		 /*
		 vector<LL> num(n,1);
		 FOR(i,0,last)num[i]=mx;
		 int itr=-1;
		 FORD(i,mn+1,1){
			 itr++;
			 FOR(j,0,range){
				 num[j+last+itr*range]=i;
			 }
		 }
		 FOR(i,0,n){
			 if(num[i]==1){
				 scr+=5*d[i];
			 }else{
				 scr+=((num[i]+1)*(num[i]+1)-num[i]*num[i])*d[i];
			 }
		 }
		 //*/
		 scr=min(ans,scr+(2*mx+1)*(dd[last]));
		 FORD(i,mn+1,1){
			 if(scr==ans)break;
			 if(i==1){
				 scr=min(ans,scr+5*(dd[last+(mn-i+1)*range]-dd[last+(mn-i)*range]));

			 }else{
				 scr=min(ans,scr+(2*i+1)*(dd[last+(mn-i+1)*range]-dd[last+(mn-i)*range]));
			 }
		 }
		 ans=min(ans,scr);
		 //cerr<<t<<" scr:"<<scr<<endl;
	 }
	 cout<<ans<<endl;
   return 0;
 }