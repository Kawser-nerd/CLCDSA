#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
int n,c,k,head=1,ci=1;
long long tim[111111],ans[111111];
bool cmp(long long a,long long b){
	return a<b;
}
int main(){
	cin>>n>>c>>k;
	bool flag=false;
	for(int i=1;i<=n;i++)scanf("%lld",&tim[i]);
	if(c==1){
		cout<<n;
		return 0;
	}
	sort(tim+1,tim+1+n,cmp);
	for(int i=1;i<=n;i++){
		if(i!=1&&ci!=c){
			if(tim[i]<=ans[head-1]&&tim[i]+k>=ans[head-1])ci++;
			else flag=true;
		}
		else if(ci==c||i==1){
			ans[head++]=tim[i]+k;
			flag=false;
			if(ci==c)ci=1;
		}
		if(flag){
			ans[head++]=tim[i]+k;
			flag=false;
			ci=1;
		}
	}
	cout<<head-1;
	return 0;
}