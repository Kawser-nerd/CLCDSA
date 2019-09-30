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
	LL l=-1,r=-1,n,k,a[100010]={},b[100010]={};
	cin>>n>>k;
	FORQ(i,1,n){
		cin>>b[i];
		a[i]=b[i];
	}
	a[0]=0;b[0]=0;
	FORQ(i,1,n)a[i]=a[i]+a[i-1];
	FORQ(i,1,n){
		b[i]=max(b[i-1],b[i-1]+b[i]);
	}
	LL mx=0;
	FOR(i,0,n-k+1){
		int p=i+1,q=p+k-1;
		LL tmp=b[n]-b[q]+b[p-1]-b[0];
		mx=max(mx,tmp);
		tmp+=a[q]-a[p-1];
		mx=max(mx,tmp);

	}
	cout<<mx;
    return 0;
}