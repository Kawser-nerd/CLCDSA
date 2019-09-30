#include <stdio.h>
#include <limits.h>

typedef long long ll;

int a[2005];
int b[2005];
ll c[2005];
ll dist[1005];
int negative[1005];

int main(){

	int N,M;

	scanf("%d %d",&N,&M);

	int i,j;

	for(i=0;i<M;i++){
		scanf("%d %d %lld",&a[i],&b[i],&c[i]);
		a[i]--;
		b[i]--;
		c[i]=-c[i];
	}

	for(i=0;i<N;i++){
		dist[i]=LLONG_MAX;
	}
	dist[0]=0ll;

	for(i=0;i<N-1;i++){
		for(j=0;j<M;j++){
			if(dist[a[j]]==LLONG_MAX){continue;}
			if(dist[b[j]]>dist[a[j]]+c[j]){
				dist[b[j]]=dist[a[j]]+c[j];
			}
		}
	}

	ll ans=dist[N-1];

	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			if(dist[a[j]]==LLONG_MAX){continue;}
			if(dist[b[j]]>dist[a[j]]+c[j]){
				dist[b[j]]=dist[a[j]]+c[j];
				negative[b[j]]=1;
			}
			if(negative[a[j]]==1){
				negative[b[j]]=1;
			}
		}
	}

	if(negative[N-1]==1){
	printf("inf\n");
	}
	else{
	printf("%lld\n",-ans);
	}

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:16:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&N,&M);
  ^
./Main.c:21:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %lld",&a[i],&b[i],&c[i]);
   ^