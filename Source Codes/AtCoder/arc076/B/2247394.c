#include<stdio.h>
#include<stdlib.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define T !0

typedef struct edge{ll s,g,c;}E;
typedef struct vertex{ll i,x,y;}V;
int xsort(const void*a,const void*b){
	ll p=(*(V*)a).x,q=(*(V*)b).x;
	return p<q?-1:p>q?1:0;
}
int ysort(const void*a,const void*b){
	ll p=(*(V*)a).y,q=(*(V*)b).y;
	return p<q?-1:p>q?1:0;
}

//union-find
int uniroot[100010],unicnt[100010];
void ufinit(int n){for(int i=0;i<n;i++){uniroot[i]=i;unicnt[i]=1;}}
int root(int x){return uniroot[x]!=x?uniroot[x]=root(uniroot[x]):x;}
int same(int x,int y){return root(x)==root(y);}
void uni(int x,int y){if((x=root(x))==(y=root(y)))return;uniroot[x]=y;unicnt[y]+=unicnt[x];}

//??????
int csort(const void*a,const void*b){
	ll p=(*(E*)a).c,q=(*(E*)b).c;
	return p<q?-1:p>q?1:0;
}
ll d[200010];
void kurasukaru(int n,E*e,int ecnt){
	qsort(e,ecnt,sizeof(E),csort);
	ufinit(n);
	rep(i,0,ecnt){
		if(!same(e[i].s,e[i].g)){
			uni(e[i].s,e[i].g);
			d[i]=T;
		}
	}
}

V v[100010];
E e[200010];
int main(){
	int n;
	scanf("%d",&n);
	rep(i,0,n){
		int x,y;
		scanf("%d%d",&x,&y);
		v[i].i=i;
		v[i].x=x;
		v[i].y=y;
	}
	qsort(v,n,sizeof(V),xsort);
	rep(i,0,n-1){
		e[i].s=v[i].i;
		e[i].g=v[i+1].i;
		e[i].c=v[i+1].x-v[i].x;
	}

	qsort(v,n,sizeof(V),ysort);
	rep(i,0,n-1){
		e[n-1+i].s=v[i].i;
		e[n-1+i].g=v[i+1].i;
		e[n-1+i].c=v[i+1].y-v[i].y;
	}
	kurasukaru(n,e,2*n-2);
	
	ll ans=0;
	rep(i,0,2*n-2)ans+=d[i]*e[i].c;
	printf("%lld\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:46:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:49:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&x,&y);
   ^