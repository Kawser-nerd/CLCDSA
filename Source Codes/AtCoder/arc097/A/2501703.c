#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
int ups(const void*a, const void*b){return strcmp((char*)a,(char*)b);}

char s[5010];
char ss[30000][8];
int main(){
	int k;
	scanf("%s%d",s,&k);
	int n=strlen(s);
	int cnt=0;
	rep(i,0,n)rep(j,0,5){
		rep(kk,0,j+1)ss[cnt][kk]=s[i+kk];
		cnt++;
	}
	qsort(ss,cnt,8,ups);
		
	if(k==1){
		puts(ss[0]);
		return 0;
	}
	int num=1,pre=0;
	rep(i,1,cnt){
		if(strcmp(ss[pre],ss[i])){
			num++;
			pre=i;
			if(num==k){
				puts(ss[i]);
				return 0;
			}
		}
	}
} ./Main.c: In function ‘main’:
./Main.c:12:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s%d",s,&k);
  ^