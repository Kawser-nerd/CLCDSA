#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define bit(n,m)(((n)>>(m))&1)

int a[200010];
int flag[200010];
int ans[200010];
ll temp[200010];
typedef struct edge{ll s,g;}E;
E e[200010];
int id[200010];

int esort(const void*a,const void*b){
	E*p=(E*)a,*q=(E*)b;
	if((*p).s<(*q).s)return -1;
	if((*p).s>(*q).s)return  1;
	if((*p).g<(*q).g)return -1;
	return 1;
}

int mex(ll s){
	int ans=0;
	while(bit(s,ans))ans++;
	return ans;
}

int f(int k){
	ll s=0;
	rep(i,id[k],id[k+1])s|=1LL<<f(e[i].g);
	return ans[k]=mex(s);
}

void check(int t){
	int s=t;
	while(a[s]!=t){
		ans[a[s]]=mex(temp[a[s]]|(1LL<<ans[s]));
		s=a[s];
	}
	if(ans[t]==mex(temp[t]|(1LL<<ans[s]))){
		puts("POSSIBLE");
//		rep(i,0,6)printf("%d",ans[i]);
		exit(0);
	}
}

int main(){
	int n;
	scanf("%d",&n);
	rep(i,0,n){
		ll t;
		scanf("%lld",&t);
		t--;
		a[i]=t;
		e[i].s=t;
		e[i].g=i;
	}
		
	qsort(e,n,sizeof(E),esort);
	{
		int p=0;
		rep(i,0,n){
			while(p<n&&e[p].s<i)p++;
			id[i]=p;
		}
		id[n]=n;//????
	}
	
	//?????????????2??????0
	for(int i=0;flag[i]!=2;i=a[i])flag[i]++;
	rep(i,0,n)flag[i]&=2;
	
	//???????????
	rep(i,0,n)if(!flag[i]&&flag[a[i]]==2)temp[a[i]]|=1LL<<f(i);
	
	//?????????
	int t=0;
	while(!flag[t])t++;
	//t?mex???
	ans[t]=mex(temp[t]);
	check(t);
	ans[t]=mex(temp[t]|(1LL<<ans[t]));
	check(t);
	
	puts("IMPOSSIBLE");
} ./Main.c: In function ‘main’:
./Main.c:50:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:53:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&t);
   ^