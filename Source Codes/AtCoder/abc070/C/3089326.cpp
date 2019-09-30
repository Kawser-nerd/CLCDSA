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

long long gcd(long long a,long long b){
	if(b==0)return a;
	return gcd(b,a%b);
}

long long lcm(long long a,long long b){
	long long g=gcd(a,b);
	return a/g*b;
}

int main(){
	LL n,t[111]={};
	cin>>n;
	FOR(i,0,n){
		cin>>t[i];
	}
	LL ans=t[0];
	FOR(i,1,n){
		ans=lcm(ans,t[i]);
	}
	cout<<ans;
    return 0;
}