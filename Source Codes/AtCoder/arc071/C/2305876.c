#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)

char s[100010],t[100010];
int ss[100010],tt[100010];
int main(){
	scanf("%s%s",s,t);
	int sn=strlen(s),tn=strlen(t);
	//s[i]=[0,i)??(s?index?0-based)
	rep(i,0,sn)ss[i+1]=ss[i]+(s[i]=='A'?2:1);
	rep(i,0,tn)tt[i+1]=tt[i]+(t[i]=='A'?2:1);
	
	int q;
	scanf("%d",&q);
	while(q--){
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		a--;b--;c--;d--;
		if((ss[b+1]-ss[a])%3==(tt[d+1]-tt[c])%3)puts("YES");
		else puts("NO");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s%s",s,t);
  ^
./Main.c:17:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&q);
  ^
./Main.c:20:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d%d",&a,&b,&c,&d);
   ^