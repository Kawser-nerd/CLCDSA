#include <iostream>
using namespace std;

const long long MOD = (1e9)+7;
long long factorial(long long key) {
	long long ans=1;
	do {
		ans *= key;
		ans %= MOD;
	}while(--key);
	return ans%MOD;
}
int main() {
	long long n,m;
	cin>>n>>m;
	if (m<n) {
		long long t=m; m=n; n=t;
	}
	// n<=m
	if (n + 1 == m) {
		long long ans=factorial(n)*factorial(m);
		cout<<ans%MOD<<endl;
	}
	else if (n==m) {
		long long ans=factorial(n)*factorial(m)*2;
		cout<<ans%MOD<<endl;
	}
	else {
		cout<<"0"<<endl;
	}
	return 0;
}