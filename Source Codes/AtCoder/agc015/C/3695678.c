#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define INF ((1LL<<62)-(1LL<<31))
#define min(p,q)((p)<(q)?(p):(q))

#define f(a,x1,y1,x2,y2)(a[x2][y2]-a[x1][y2]-a[x2][y1]+a[x1][y1])

int cumv[2010][2010];
int cume[4010][4010];
char s[2010][2010];
int main(){
	int n,m,q;
	scanf("%d%d%d\n",&n,&m,&q);
	rep(i,0,n)scanf("%s\n",s[i]);
	
	rep(i,0,n)rep(j,0,m)cumv[i+1][j+1]=(s[i][j]=='1');
	rep(i,0,n)rep(j,0,m-1)cume[2*i+2][2*j+3]+=(s[i][j]=='1'&&s[i][j+1]=='1');
	rep(i,0,n-1)rep(j,0,m)cume[2*i+3][2*j+2]+=(s[i][j]=='1'&&s[i+1][j]=='1');
	
	rep(i,0,n+1)rep(j,0,m+1)cumv[i][j+1]+=cumv[i][j];
	rep(i,0,n+1)rep(j,0,m+1)cumv[i+1][j]+=cumv[i][j];

	rep(i,0,2*n+5)rep(j,0,2*m+5)cume[i][j+1]+=cume[i][j];
	rep(i,0,2*n+5)rep(j,0,2*m+5)cume[i+1][j]+=cume[i][j];
	
	while(q--){
		int x1,y1,x2,y2;
		scanf("%d%d%d%d\n",&x1,&y1,&x2,&y2);
		--x1,--y1,--x2,--y2;
		printf("%d\n",f(cumv,x1,y1,x2+1,y2+1)-f(cume,2*x1+1,2*y1+1,2*x2+2,2*y2+2));
	}
} ./Main.c: In function ‘main’:
./Main.c:15:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d\n",&n,&m,&q);
  ^
./Main.c:16:12: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  rep(i,0,n)scanf("%s\n",s[i]);
            ^
./Main.c:30:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d%d\n",&x1,&y1,&x2,&y2);
   ^