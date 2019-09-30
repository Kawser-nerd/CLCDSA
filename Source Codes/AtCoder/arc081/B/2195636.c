#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ll long long
#define M 1000000007

#define rep(i,l,r)for(ll i=(l);i<(r);i++)

ll pre,now,ans;
char s[99];
int main(){
	scanf("%*d%s",s);
	int n=strlen(s);
	ll pos;
	if(s[0]==s[1]){
		pre=1;
		ans=6;
		pos=2;
	}else{
		pre=0;
		ans=3;
		pos=1;
	}
	while(pos<n){
		if(s[pos]==s[pos+1]){
			if(pre==1)ans=ans*3%M;
			else ans=ans*2%M;
			pos+=2;
			pre=1;
		}else{
			if(pre==0)ans=ans*2%M;
			pos+=1;
			pre=0;
		}
	}
	printf("%lld\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%*d%s",s);
  ^