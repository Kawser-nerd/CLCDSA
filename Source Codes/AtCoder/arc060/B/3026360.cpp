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

const double pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342;
const int mod=1000000007;

int main(){
	LL n,s,b=-1;
	cin>>n>>s;

	if(n==s){
		cout<<n+1;
		return 0;
	}
	int t=sqrt(n)+3;
	FOR(i,2,t){
		LL ii=i,nn=n,d=0;
		while(nn>0){
			d+=nn%ii;
			nn/=ii;
		}
		if(d==s){
			b=ii;
			break;
		}
	}
	if(b==-1){
		FOR(p,1,t){
			LL pp=p,q=s-p,d=(n-q)/p;
			if(q>=0&&d>=0&&n==p*d+q&&q<d){
				b=d;
				//cerr<<p<<"*"<<d<<"+"<<q<<"="<<n<<endl;
			}
		}
	}
	cout<<b;
    return 0;
}