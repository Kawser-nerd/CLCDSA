#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#define ll long long
#define maxn 100006
using namespace std;
ll ans=0;int n;
struct li{
	ll v;
	int lo;
	int san;
}mmp[maxn];
bool cmp(li a,li b){
	return a.v<b.v;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%lld",&mmp[i].v);
		mmp[i].lo=i;
	}
	sort(mmp+1,mmp+1+n,cmp);
	for(int i=1;i<=n;i++)mmp[i].san=i;
	for(int i=1;i<=n;i++){
		if(abs(mmp[i].san-mmp[i].lo)%2==1)ans++;
	}
	cout<<ans/2;
	return 0;
}