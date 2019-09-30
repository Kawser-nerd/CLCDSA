#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)

typedef struct tyouten{ll id,x,y;}V;
int xsort(const void*a,const void*b){
	ll p=(*(V*)a).x,q=(*(V*)b).x;
	return p<q?-1:p>q?1:0;
}
int ysort(const void*a,const void*b){
	ll p=(*(V*)a).y,q=(*(V*)b).y;
	return p<q?-1:p>q?1:0;
}

//?????????????

typedef struct edge{ll s,g,c;}E;
typedef struct graph{
	ll vcnt,ecnt;
	E  e[200010];//?????
	ll id[100010];//?????
}G;
int csort(const void*a,const void*b){
	ll p=(*(E*)a).c,q=(*(E*)b).c;
	return p<q?-1:p>q?1:0;
}

V v[100010];
G g;
void readgraph(){
	ll n;
	scanf("%lld",&n);
	rep(i,0,n){
		ll x,y;
		scanf("%lld%lld",&x,&y);
		v[i].id=i;
		v[i].x=x;
		v[i].y=y;
	}
	qsort(v,n,sizeof(V),xsort);
	rep(i,0,n-1){
		g.e[i].s=v[i].id;
		g.e[i].g=v[i+1].id;
		g.e[i].c=v[i+1].x-v[i].x;
	}
 
	qsort(v,n,sizeof(V),ysort);
	rep(i,0,n-1){
		g.e[n-1+i].s=v[i].id;
		g.e[n-1+i].g=v[i+1].id;
		g.e[n-1+i].c=v[i+1].y-v[i].y;
	}
	
	g.vcnt=n;
	g.ecnt=(n-1)*2;
	qsort(g.e,g.ecnt,sizeof(E),csort);
}


//union-find
int uniroot[100010],unicnt[100010];
void ufinit(int n){for(int i=0;i<n;i++){uniroot[i]=i;unicnt[i]=1;}}
int root(int x){return uniroot[x]!=x?uniroot[x]=root(uniroot[x]):x;}
int same(int x,int y){return root(x)==root(y);}
void uni(int x,int y){if((x=root(x))==(y=root(y)))return;uniroot[x]=y;unicnt[y]+=unicnt[x];}

//??????
//???????????????
//union find???
//O(ElogE)
ll saishou[200010];
void kurasukaru(G g){
	ufinit(g.vcnt);
	rep(i,0,g.ecnt){
		if(!same(g.e[i].s,g.e[i].g)){
			uni(g.e[i].s,g.e[i].g);
			saishou[i]=1;
		}
	}
}

int main(){
	readgraph();
	kurasukaru(g);
	
	ll ans=0;
	rep(i,0,g.ecnt)if(saishou[i])ans+=g.e[i].c;
	printf("%lld\n",ans);
	return 0;
} ./Main.c: In function ‘readgraph’:
./Main.c:34:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&n);
  ^
./Main.c:37:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld",&x,&y);
   ^