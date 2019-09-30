#include<stdio.h>
#include<stdlib.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
ll a[20010];
int main(){
	ll n;
	scanf("%lld",&n);
	a[0]=3;
	ll s=3;
	ll cnt=1;
	for(ll num=0;cnt<n-3&&num+25<=30000;num+=30){
		a[cnt++]=num+ 5;
		a[cnt++]=num+25;
		s+=num*2+30;
	}
	for(ll num=9;cnt<n-3&&num+6<=30000;num+=12){
		a[cnt++]=num;
		a[cnt++]=num+6;
		s+=num*2+6;
	}
	for(ll num=2;cnt<n-1;num+=2){
		a[cnt++]=num;
		s+=num;
	}
	//s?????
	//2,3,5??????????k?????s+k?30?????k???????????????????
	//a[cnt-1]?26002???????????????s?30000-a[cnt-1]??????????
	//[s,s+30000-a[cnt-1]]???ss?????k=30x-ss%30?????ss?k???????????????????
	//ss????2000??????ss???k????1000??????????????
	
	ll ss=s;
	while(1){
		while(ss%3==0||ss%5==0)ss+=2;
		for(ll k=30-ss%30;k<=30000;k+=30)if(k!=1&&ss%k==0){
			rep(i,0,n-2)printf("%d ",a[i]);
			printf("%d %d\n",a[cnt-1]+(ss-s),k);
			return 0;
		}
		ss+=2;
	}
} ./Main.c: In function ‘main’:
./Main.c:36:23: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘long long int’ [-Wformat=]
    rep(i,0,n-2)printf("%d ",a[i]);
                       ^
./Main.c:37:11: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘long long int’ [-Wformat=]
    printf("%d %d\n",a[cnt-1]+(ss-s),k);
           ^
./Main.c:37:11: warning: format ‘%d’ expects argument of type ‘int’, but argument 3 has type ‘long long int’ [-Wformat=]
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&n);
  ^