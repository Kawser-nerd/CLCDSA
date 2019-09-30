#include<stdio.h>
#include<stdlib.h>

long long min(long long x,long long y){
	if(x<y)return x;
	return y;
}

int compare(const void *a, const void *b){
	long long int *A = (long long int *)a;
	long long int *B = (long long int *)b;
	if (*A < *B) return 1;
	if (*A > *B) return -1;
	return 0;
}

int main(){
	long long N,K,i,j,k,l,m;
	scanf("%lld%lld",&N,&K);
	long long x[N],y[N],xsort[N],ysort[N];
	for(i=0;i<N;i++){
		scanf("%lld%lld",&x[i],&y[i]);
		xsort[i]=x[i];
		ysort[i]=y[i];
	}
	qsort(xsort,N,sizeof(long long),compare);
	qsort(ysort,N,sizeof(long long),compare);
	
	long long ans=(xsort[0]-xsort[N-1])*(ysort[0]-ysort[N-1]);
	
	for(i=0;i+K-1<N;i++){
		for(j=i+K-1;j<N;j++){
			for(k=0;k+K-1<N;k++){
				for(l=k+K-1;l<N;l++){
					long long c=0;
					for(m=0;m<N;m++)if(x[m]<=xsort[i] && x[m]>=xsort[j] && y[m]<=ysort[k] && y[m]>=ysort[l])c++;
					if(c>=K){
						ans=min(ans,(xsort[i]-xsort[j])*(ysort[k]-ysort[l]));
						break;
					}
				}
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:19:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld",&N,&K);
  ^
./Main.c:22:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld",&x[i],&y[i]);
   ^