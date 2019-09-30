#include <iostream>
using namespace std;
typedef long long ll;
const int maxp=1000000;
bool prime[1000001];
int main(){
	for (int i=0;i<=maxp;++i)
		prime[i]=true;
	prime[0]=prime[1]=false;
	for (int i=0;i<=maxp;++i)
		if (prime[i])
			for (int j=i+i;j<=maxp;j+=i)
				prime[j]=false;
	int tnum,tcou=0;cin>>tnum;
	while (tnum--){
		ll ans=1;
		ll n;cin>>n;
		for (ll i=0;i<=maxp;++i)
			if (prime[i]){
				ll m=n/i;
				while (m>=i){
					++ans;
					m/=i;
				}
			}
		if (n==1)
			ans=0;
		cout<<"Case #"<<++tcou<<": "<<ans<<endl;
	}
	return 0;
}
