#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <bitset>
#include <queue>
#include <set>
//#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;

#define LL long long 
#define ULL unsigned long long
#define eps 1e-9
#define N 100010
#define M 600050
#define pii pair<int,int>
#define MP make_pair
#define inf 100000000
#define md (ll+rr>>1)
#define lson ll, md, ls
#define rson md + 1, rr, rs
#define ls rt<<1
#define rs rt<<1|1
#define Pi acos(-1.0)
#define mod 1000000007
#define ui unsigned int
#define pb push_back
LL powmod(LL a,LL b,LL p){
	if(b < 0) return 0;
	LL res = 1; a %= p;
	for(;b;b>>=1){
		if(b & 1) res = res * a % p;
		a = a * a % p;
	}
	return res;
}

LL ans = 0;
LL gcd(LL a,LL b){
	while(b){
		LL t = a % b;
		ans += a / b * b * 2;
		a = b;
		b = t;
	}
	return a;
}

int main(){
	LL n,x;
	cin>>n>>x;
	LL _gcd = gcd(n-x,x);
	ans += n - _gcd;
	cout<<ans<<endl;
	return 0;
}