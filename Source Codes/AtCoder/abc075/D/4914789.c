#include <stdio.h>
#include <stdlib.h>
#define ll long long int
int compare_longlong(const void *a, const void *b) {ll *A = (ll *)a;ll *B = (ll *)b;if (*A > *B) return 1;if (*A < *B) return -1;return 0;}

int main(void){
	int N,K,i;
	scanf("%d%d",&N,&K);
	ll x[N],y[N],xary[N],yary[N];
	for(i=0;i<N;i++){
		scanf("%lld%lld",&x[i],&y[i]);
		xary[i] = x[i];
		yary[i] = y[i];
	}
	qsort(xary, N, sizeof(ll), compare_longlong);
	qsort(yary, N, sizeof(ll), compare_longlong);
	ll ans = (xary[N-1]-xary[0])*(yary[N-1]-yary[0]);
	for(int xi=0;xi<N;xi++){
		for(int xj=xi+1;xj<N;xj++){
			for(int yi=0;yi<N;yi++){
				for(int yj=yi+1;yj<N;yj++){
					int num=0;
					ll lx=xary[xi], rx=xary[xj];
					ll by=yary[yi], uy=yary[yj];
					for(i=0;i<N;i++){
						if(lx<=x[i] && x[i]<=rx && by<=y[i] && y[i]<=uy)num++;
					}
					ll s=(rx-lx)*(uy-by);
					if(num>=K && s<ans)ans=s;
				}
			}
		}
	}
	printf("%lld",ans);
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&N,&K);
  ^
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld",&x[i],&y[i]);
   ^