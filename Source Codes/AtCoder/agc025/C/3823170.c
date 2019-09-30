#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define max(p,q)((p)>(q)?(p):(q))

typedef struct p{ll x,y,i;}P;
int xsort(const void*a,const void*b){
	//?????????????
	P*p=(P*)a,*q=(P*)b;
	if((*p).x>(*q).x)return -1;
	return  1;
}
int ysort(const void*a,const void*b){
	//?????????????
	P*p=(P*)a,*q=(P*)b;
	if((*p).y<(*q).y)return -1;
	return  1;
}
int isort(const void*a,const void*b){
	P*p=(P*)a,*q=(P*)b;
	if((*p).i<(*q).i)return -1;
	return  1;
}

P a[100010];
int xx[100010],yy[100010];
int n;
ll f(){
	int flag[100010]={};
	//???
	ll tans=0,cr=0,cl=0,cp=0;
	while(1){
		while(cr<n&&flag[xx[cr]])cr++;
		if(cr==n)break;
		if(a[xx[cr]].x<=cp)break;
		tans+=a[xx[cr]].x-cp;
		cp=a[xx[cr]].x;
		flag[xx[cr]]=1;
//		printf("%d %d\n",cp,tans);
		while(cl<n&&flag[yy[cl]])cl++;		
		if(cl==n)break;
		if(a[yy[cl]].y>=cp)break;
		tans+=cp-a[yy[cl]].y;
		cp=a[yy[cl]].y;
		flag[yy[cl]]=1;
//		printf("%d %d\n",cp,tans);
	}
	tans+=llabs(cp);
//	puts("");
	return tans;
}

int main(){
	scanf("%d",&n);
	rep(i,0,n){
		int l,r;
		scanf("%d%d",&l,&r);
		a[i].i=i;
		a[i].x=l;
		a[i].y=r;
	}
	qsort(a,n,sizeof(P),xsort);
	rep(i,0,n)xx[i]=a[i].i;
	qsort(a,n,sizeof(P),ysort);
	rep(i,0,n)yy[i]=a[i].i;
	qsort(a,n,sizeof(P),isort);

    //???
	ll ans1=f();
	
    //??
	rep(i,0,n){
		ll t=a[i].x;
		a[i].x=-a[i].y;
		a[i].y=-t;
	}
	qsort(a,n,sizeof(P),xsort);
	rep(i,0,n)xx[i]=a[i].i;
	qsort(a,n,sizeof(P),ysort);
	rep(i,0,n)yy[i]=a[i].i;
	qsort(a,n,sizeof(P),isort);
	
    //???????????
	ll ans2=f();
	printf("%lld",max(ans1,ans2));
} ./Main.c: In function ‘main’:
./Main.c:55:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:58:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&l,&r);
   ^