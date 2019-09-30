#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define bit(n,m)(((n)>>(m))&1)

ll h,w;
char ss[20][20];
ll a[20];

void g(int s,int flag){
	if(s+1==(1<<w)){
		puts("YES");
		exit(0);
	}
	int i=0;
	while(bit(s,i))i++;
	if(flag){
		int b=1;
		rep(k,0,h)if(ss[k][i]!=ss[a[k]][i]){
			b=0;
			break;
		}
		if(b)g(s^(1<<i),0);
	}
	rep(j,i+1,w)if(!bit(s,j)){
		int b=1;
		rep(k,0,h)if(ss[k][i]!=ss[a[k]][j]){
			b=0;
			break;
		}
		if(b)g(s^(1<<i)^(1<<j),flag);
	}	
}

void f(int s,int flag){
	if(s+1==(1<<h))g(0,w%2);
	int i=0;
	while(bit(s,i))i++;
	if(flag){
		a[i]=i;
		f(s^(1<<i),0);
	}
	rep(j,i+1,h)if(!bit(s,j)){
		a[i]=j;
		a[j]=i;
		f(s^(1<<i)^(1<<j),flag);
	}
}

int main(){
	scanf("%lld%lld",&h,&w);
	rep(i,0,h)scanf(" %s",ss[i]);
	f(0,h%2);
	puts("NO");
} ./Main.c: In function ‘main’:
./Main.c:52:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld",&h,&w);
  ^
./Main.c:53:12: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  rep(i,0,h)scanf(" %s",ss[i]);
            ^