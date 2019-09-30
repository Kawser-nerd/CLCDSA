#include <stdio.h>
long long A[999999],W[999999];
long long M(int l,int r){
	if(l+1>=r)return 0;
	if(l+2==r){
		if(A[l]<=A[l+1])return 0;
		long long z=A[l];A[l]=A[l+1];A[l+1]=z;
		return 1;
	}
	int m = (l+r)/2,i=l, j=m, k=l;
	long long cl=M(l, m),cr=M(m,r),c=0;
	while(i<m&&j<r){
		if(A[i]<=A[j])W[k++]=A[i++];
		else{
			W[k++]=A[j++];
			c+=m-i;
		}
	}
	while(i<m)W[k++]=A[i++];
	while(j<r)W[k++]=A[j++];
	for(i=l;i<r;i++)A[i]=W[i];
	return cl+cr+c;
}
int main(){
	int T,i,N;
	scanf("%d%d",&N,&T);for(i=1;i<=N;i++)scanf("%d",&A[i]);for(i=1;i<=N;i++)A[i]+=A[i-1]-T;printf("%lld\n",(long long)N*-~N/2-M(0,N+1));
} ./Main.c: In function ‘main’:
./Main.c:26:45: warning: format ‘%d’ expects argument of type ‘int *’, but argument 2 has type ‘long long int *’ [-Wformat=]
  scanf("%d%d",&N,&T);for(i=1;i<=N;i++)scanf("%d",&A[i]);for(i=1;i<=N;i++)A[i]+=A[i-1]-T;printf("%lld\n",(long long)N*-~N/2-M(0,N+1));
                                             ^
./Main.c:26:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&N,&T);for(i=1;i<=N;i++)scanf("%d",&A[i]);for(i=1;i<=N;i++)A[i]+=A[i-1]-T;printf("%lld\n",(long long)N*-~N/2-M(0,N+1));
  ^
./Main.c:26:39: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&N,&T);for(i=1;i<=N;i++)scanf("%d",&A[i]);for(i=1;i<=N;i++)A[i]+=A[i-1]-T;printf("%lld\n",(long long)N*-~N/2-M(0,N+1));
                                       ^