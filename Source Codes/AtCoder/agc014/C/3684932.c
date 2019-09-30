#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define INF ((1LL<<62)-(1LL<<31))
#define min(p,q)((p)<(q)?(p):(q))

ll dp[810][810];
char s[810][810];
int que[640010],quecnt;

int dir[5]={0,-1,0,1,0};

int main(){
	int h,w,xx;
	scanf("%d%d%d\n",&h,&w,&xx);
	rep(i,0,h)scanf("%s",s[i]);

	int si,sj;
	rep(i,0,h)rep(j,0,w)if(s[i][j]=='S'){
		si=i;
		sj=j;
	}
	
	dp[si][sj]=1;
	que[0]=si*1000+sj;
	quecnt=1;
	//bfs
	for(int qp=0;qp<quecnt;qp++){
		int ci=que[qp]/1000;
		int cj=que[qp]%1000;
		rep(k,0,4){
			int di=ci+dir[k];
			int dj=cj+dir[k+1];
			if(0<=di&&di<h&&0<=dj&&dj<w&&s[di][dj]=='.'&&!dp[di][dj]){
				dp[di][dj]=dp[ci][cj]+1;
				if(dp[di][dj]<=xx)que[quecnt++]=di*1000+dj;
			}
		}
	}

	ll ans=INF;
	rep(i,0,h)rep(j,0,w)if(dp[i][j]){
		//???????
		int d=min(min(llabs(i),llabs(h-1-i)),min(llabs(j),llabs(w-1-j)));
		ans=min(ans,1+(d+xx-1)/xx);
	}
	printf("%lld",ans);
} ./Main.c: In function ‘main’:
./Main.c:16:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d\n",&h,&w,&xx);
  ^
./Main.c:17:12: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  rep(i,0,h)scanf("%s",s[i]);
            ^