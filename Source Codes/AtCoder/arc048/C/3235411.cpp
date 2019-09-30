#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
using namespace std;
 
#define mod 1000000007
#define FOR(x,to) for(int x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
#define long long long
inline int rei(){int x;cin>>x;return x;}
inline long rel(){long x;cin>>x;return x;}
inline string res(){string x;cin>>x;return x;}
//------------------------------------------------------- 
long L[100000];
long pow(long X0){
	long X = X0;
	long ans = 1;
	long c = 2;
	while(X){
		if(X % 2){
			ans *= c;
			ans %= mod;
		}
		X /= 2;
		c = c*c%mod;
	}
	return ans;
}
long gcd(long X,long Y){
	if(!Y){
		return X;
	}
	return gcd(Y,X%Y);
}
void Calc(){
	int N = rei();
	for(int i=0;i<N;i++){
		L[i] = rel();
	}
	long minL = 1000000000;
	for(int i=0;i<N;i++){
		minL = min(minL,L[i]);
	}
	long g = 0;
	for(int i=0;i<N;i++){
		g = gcd(L[i]-minL,g); 
	}
	cout << pow((g+1)/2+minL) << endl;
}
int main(int argc,char** argv){
	ios::sync_with_stdio(false), cin.tie(0);
	cout.tie(0); Calc(); return 0;
}