#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define repp(i,l,r,k)for(ll i=(l);i<(r);i+=(k))
#define INF ((1LL<<62)-(1LL<<31))
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))
#define bit(n,m)((n>>m)&1)
int upll(const void*a, const void*b){return*(ll*)a<*(ll*)b?-1:*(ll*)a>*(ll*)b?1:0;}
int downll(const void*a, const void*b){return*(ll*)a<*(ll*)b?1:*(ll*)a>*(ll*)b?-1:0;}
void sortup(ll*a,int n){qsort(a,n,sizeof(ll),upll);}
void sortdown(ll*a,int n){qsort(a,n,sizeof(ll),downll);}


ll n,ans;
char s[99];
char mae[1<<18][40],usiro[1<<18][40];
ll maenum[1<<18],usironum[1<<18];
int cc(const void*a,const void*b){return memcmp(a,b,40);}



int main(){
	scanf("%lld\n%s",&n,s);
	{
		//??????
		ll a[999]={};
		rep(i,0,2*n)a[s[i]]^=1;
		rep(i,0,256)if(a[i]){puts("0");return 0;}
	}
	rep(i,0,1<<n){
		ll akacnt=0,aocnt=0;
		rep(k,0,n){
			if(bit(i,k))mae[i][akacnt++]=s[k];
			else mae[i][20+aocnt++]=s[k];
		}
		
		akacnt=0,aocnt=0;
		for(ll k=2*n-1;k>=n;k--){
			if(bit(i,2*n-1-k))usiro[i][akacnt++]=s[k];
			else usiro[i][20+aocnt++]=s[k];
		}
	}

	qsort(mae,1<<n,40,cc);
	qsort(usiro,1<<n,40,cc);
//	rep(i,0,16){rep(j,0,40)putchar(mae[i][j]?:32);puts("");}puts("");
//	rep(i,0,16){rep(j,0,40)putchar(usiro[i][j]?:32);puts("");}
	
//	rep(i,0,1<<n)rep(j,0,1<<n)if(!memcmp(mae[i],usiro[j],40))ans++;

	
	ll maecnt=0;maenum[0]=1;
	rep(i,1,1<<n){
		if(memcmp(mae[maecnt],mae[i],40))memmove(mae[++maecnt],mae[i],40);
		maenum[maecnt]++;
	}
	ll usirocnt=0;usironum[0]=1;
	rep(i,1,1<<n){
		if(memcmp(usiro[usirocnt],usiro[i],40))memmove(usiro[++usirocnt],usiro[i],40);	
		usironum[usirocnt]++;
	}
	
	ll usirotemp=0;
	rep(i,0,maecnt+1){
		while(usirotemp<=usirocnt&&memcmp(usiro[usirotemp],mae[i],40)<0)usirotemp++;
		if(!memcmp(usiro[usirotemp],mae[i],40))ans+=usironum[usirotemp]*maenum[i];
	}
	
	printf("%lld",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:26:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld\n%s",&n,s);
  ^