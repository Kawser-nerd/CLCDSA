#include<stdio.h>
#include<string.h>

int main(void){
	char s[131072],t[131072];
	int q,a,b,c,d,i,sl,tl;
	int w,x,y,z;
	int sa[131072]={0},sb[131072]={0};
	int ta[131072]={0},tb[131072]={0};
	scanf("%s%s",s,t);
	sl = strlen(s);tl = strlen(t);
	for(i = 0;i < sl;i++){
		if(s[i] == 'A'){sa[i+1] = sa[i]+1;sb[i+1] = sb[i];}
		else{sb[i+1] = sb[i]+1;sa[i+1] = sa[i];}
	}
	for(i = 0;i < tl;i++){
		if(t[i] == 'A'){ta[i+1] = ta[i]+1;tb[i+1] = tb[i];}
		else{tb[i+1] = tb[i]+1;ta[i+1] = ta[i];}
	}
	scanf("%d",&q);
	for(i = 1;i <= q;i++){
		scanf("%d%d%d%d",&a,&b,&c,&d);
		w = sa[b]-sa[a-1];
		x = sb[b]-sb[a-1];
		y = ta[d]-ta[c-1];
		z = tb[d]-tb[c-1];
		if((w*2+x)%3 == (y*2+z)%3){printf("YES\n");}else{printf("NO\n");}
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s%s",s,t);
  ^
./Main.c:20:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&q);
  ^
./Main.c:22:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d%d",&a,&b,&c,&d);
   ^