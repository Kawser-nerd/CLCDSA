#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define max(p,q)((p)>(q)?(p):(q))

typedef struct edge{ll s,g;}E;
int edgehikaku(const void*a,const void*b){
	E*p=(E*)a,*q=(E*)b;
	if((*p).s<(*q).s)return -1;
	if((*p).s>(*q).s)return  1;
	if((*p).g<(*q).g)return -1;
	return 1;
}

E e[200010];
int id[100010];
int check[100010];
ll a[100010];

ll f(int n){
	//n???????????
	check[n]=1;
	
	//??sum?max??????
	ll s=0,M=0,flag=0;
	rep(i,id[n],id[n+1])if(!check[e[i].g]){
		ll temp=f(e[i].g);
		s+=temp;
		M=max(M,temp);
		flag=1;
	}
	
	//???a[n]?????
	if(!flag)return a[n];
	
	//??????????sum-(sum-a[n])*2??a[n]*2-sum???
	//???0??????
	if(a[n]*2-s<0){
		puts("NO");
		exit(0);
	}
	
	//??????????????
	if(a[n]>s){
		puts("NO");
		exit(0);
	}
	
	//M-(a[n]*2-sum)?sum-(a[n]*2-sum)?1/2??????????
	if((M-(a[n]*2-s))*2>s-(a[n]*2-s)){
		puts("NO");
		exit(0);
	}
	
	return a[n]*2-s;
}

int main(){
	int n;
	scanf("%d",&n);
	rep(i,0,n)scanf("%lld",a+i);
	rep(i,0,n-1){
		ll x,y;
		scanf("%lld %lld",&x,&y);
		x--,y--;
		e[2*i].s=x;
		e[2*i].g=y;
		e[2*i+1].s=y;
		e[2*i+1].g=x;
	}
	qsort(e,2*n-2,sizeof(E),edgehikaku);
	
	int p=0;
	rep(i,1,n){
		while(e[p].s!=i)p++;
		id[i]=p;
	}
	id[n]=2*n-2;
	
	//???????
	if(n==2){
		puts(a[0]==a[1]?"YES":"NO");
		return 0;
	}
	
	//???????????
	p=0;
	while(id[p+1]-id[p]==1)p++;
	puts(f(p)?"NO":"YES");
} ./Main.c: In function ‘main’:
./Main.c:61:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:62:12: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  rep(i,0,n)scanf("%lld",a+i);
            ^
./Main.c:65:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld %lld",&x,&y);
   ^