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
	int n;
	cin>>n;
	int nt=0,nx=0,ny=0;
	FOR(i,0,n){
		int t,x,y;
		cin>>t>>x>>y;
		int d1=nx-x,d2=ny-y;
		if(d1<0)d1*=-1;
		if(d2<0)d2*=-1;
		if(d1+d2<=t-nt&&((t-nt-d1-d2)%2==0)){

		}else{
			cout<<"No";
			return 0;
		}
		nt=t,nx=x,ny=y;
	}
	cout<<"Yes"<<endl;

    return 0;
}