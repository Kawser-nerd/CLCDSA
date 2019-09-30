#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int mod = 1000000007;
const int N = 100005;
#define ll long long 
ll q_mod(ll a,ll b){
	ll tmp = 1;
	a = a%mod;
	while (b){
		if (b&1) tmp = tmp * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return tmp;
}
int x[N];
int a[N];
int main(){
	int n;
	cin>>n;
	int flag = 0;
	for (int i = 0; i < n; ++i){
		cin>>x[i];
		if (x[i] == 0 && n % 2 != 0) flag++;
		else if (x[i] == 0 && n%2 == 0) flag = 2;
		a[x[i]]++;	
	}
	for (int i = 0; i < n; ++i){
		if (x[i]!=0 && a[x[i]]!=2) flag = 2;
	}
	if (flag > 1) printf("0\n");
	else{
		ll t = n/2;
		ll ans = q_mod(2,t);
		printf("%lld\n",ans);
	}
	return 0;
}