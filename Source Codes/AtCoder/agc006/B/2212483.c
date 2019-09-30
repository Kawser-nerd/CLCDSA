#include<stdio.h>
#include<stdlib.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define swap(a,b,t)(t=a,a=b,b=t)

ll a[200010];
ll num[200010];

int main(){
	int n,x;
	scanf("%d%d",&n,&x);
	
	if(x==1||x==2*n-1){
		puts("No");
		return 0;
	}
	if(n==2){
		puts("Yes\n1\n2\n3");
		return 0;
	}
	
	puts("Yes");
	if(x==2){
		a[n-2]=4;
		a[n-1]=1;
		a[n  ]=2;
		a[n+1]=3;
		num[4]=num[1]=num[2]=num[3]=1;
	}else{
		a[n-2]=x-2;
		a[n-1]=x+1;
		a[n  ]=x;
		a[n+1]=x-1;
		num[x-2]=num[x+1]=num[x]=num[x-1]=1;
	}
	ll t=1;
	rep(i,1,2*n)if(!a[i]){
		while(num[t])t++;
		a[i]=t;
		num[t]=1;
	}
	rep(i,1,2*n)printf("%lld\n",a[i]);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&n,&x);
  ^