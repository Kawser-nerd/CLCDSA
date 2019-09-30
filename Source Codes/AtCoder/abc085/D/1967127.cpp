#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MOD 1e9+7
#define ll long long int

int main(void){
	ll n,h;
	cin>>n>>h;
	ll a=0;
	ll ak;
	ll b[100005];
	for(int i=0;i<n;i++){
		cin>>ak>>b[i];
		a=max(a,ak);
	}
	sort(b,b+n);
	reverse(b,b+n);
	ll ans=0;
	int i=0;
	while(h>0){
		if(i<n&&a<b[i]){
			h-=b[i];
			i++;
			ans++;
		}else{
			ans+=h/a;
			if(h%a!=0){
				ans++;
			}
			break;
		}
	}
	cout<<ans<<endl;
	return 0;
}