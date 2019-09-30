#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<cstring>
#define ll long long
using namespace std;
const int maxn=200005;
int n,a[maxn];
ll ans;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	if(a[1]){ puts("-1"); return 0;}
	
	for(int i=2;i<=n;i++){
		if(a[i]>a[i-1]+1){ puts("-1"); return 0;}
		if(a[i]==a[i-1]+1) ans++;
		else ans+=(ll)a[i];
	}
	
	cout<<ans<<endl;

	return 0;
}