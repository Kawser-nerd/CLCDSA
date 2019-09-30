#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))

char s[99][99];
int main(){
	int h,w;
	scanf("%d%d",&h,&w);
	rep(i,0,h)scanf("%s",s[i+10]+10);
	rep(i,0+10,h+10){
		rep(j,0+10,w+10){
			if(s[i][j]=='#')putchar('#');
			else{
				ll cnt=0;
				rep(x,-1,2)rep(y,-1,2)if(x!=0||y!=0){
					if(s[i+x][j+y]=='#')cnt++;
				}
					printf("%lld",cnt);
			}
		}
		puts("");
	}
} ./Main.c: In function ‘main’:
./Main.c:12:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&h,&w);
  ^
./Main.c:13:12: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  rep(i,0,h)scanf("%s",s[i+10]+10);
            ^