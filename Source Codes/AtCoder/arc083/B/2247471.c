#include<stdio.h>
#include<stdlib.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define INF ((1LL<<62)-(1LL<<31))
#define min(p,q)((p)<(q)?(p):(q))

typedef struct edge{ll s,g,c;}E;
int csort(const void*a,const void*b){
	ll p=(*(E*)a).c,q=(*(E*)b).c;
	return p<q?-1:p>q?1:0;
}

E e[90010];
ll a[310][310];
ll d[310][310];
int main(){
	int n,ecnt=0;
	scanf("%d",&n);
	rep(i,0,n)rep(j,0,n){
		int t;
		scanf("%d",&t);
		if(i<j){
			e[ecnt].s=i;
			e[ecnt].g=j;
			e[ecnt].c=t;
			ecnt++;
		}
		a[i][j]=t;
		if(i!=j)d[i][j]=INF;
	}
	qsort(e,ecnt,sizeof(E),csort);
	
	ll ans=0;
	rep(i,0,ecnt){
//		printf("%d %d %d\n",e[i].s,e[i].g,e[i].c);
		if(e[i].c<d[e[i].s][e[i].g]){
			ans+=e[i].c;
			d[e[i].s][e[i].g]=e[i].c;
			rep(p,0,n)rep(q,p+1,n){
				d[p][q]=min(d[p][q],d[p][e[i].s]+e[i].c+d[e[i].g][q]);
				d[p][q]=min(d[p][q],d[p][e[i].g]+e[i].c+d[e[i].s][q]);
				d[q][p]=d[p][q];
			}
/*
			rep(p,0,n){
				rep(q,0,n)printf("%2d ",min(d[p][q],99));
				puts("");
			}
			puts("");
*/
		}
	}

	rep(i,0,n)rep(j,i+1,n)if(d[i][j]!=a[i][j]){
		puts("-1");
		return 0;
	}
	printf("%lld\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:19:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:22:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&t);
   ^