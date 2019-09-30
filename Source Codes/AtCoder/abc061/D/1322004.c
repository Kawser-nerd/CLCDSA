#include<stdio.h>
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define lln long long int
#define INF 1LL << 50


int main(){

	lln a[2000],b[2000],c[2000],n,m;
	lln dist[1000],nega[1000],ans;

	scanf("%lld %lld",&n,&m);

	FOR(i,0,m){
		scanf("%lld %lld %lld",&a[i],&b[i],&c[i]);
		c[i] = - c[i];
	}

	FOR(i,0,n){
		dist[i] = INF;
	}

	FOR(i,0,n){
		nega[i] = 0;
	}



	dist[0] = 0;

	FOR(loop,0,n-1){
		FOR(i,0,m){
			if(dist[a[i]-1] == INF) continue;

			if(dist[b[i]-1] > dist[a[i]-1] + c[i]){
				dist[b[i]-1] = dist[a[i]-1] + c[i];
			}
		}
	}

	ans = dist[n-1];

	FOR(loop,0,n){
		FOR(i,0,m){
			if(dist[a[i] - 1] == INF) continue;

			if(dist[b[i] - 1] > dist[a[i]-1] + c[i]){
				dist[b[i] - 1] = dist[a[i]-1] + c[i];
				nega[b[i] - 1] = 1;
			}

			if(nega[a[i] - 1] == 1){
				nega[b[i] - 1] = 1;
			}
		}
	}

	if(nega[n - 1] == 1)	printf("inf\n");
	else 					printf("%lld\n",-ans);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld %lld",&n,&m);
  ^
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld %lld %lld",&a[i],&b[i],&c[i]);
   ^