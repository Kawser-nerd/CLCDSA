#include <stdio.h>
#include <stdlib.h>
#define LIM 100000
#define INF 1e18;

int binary_seaach(long long *array,long key,int min,int max){
	if(min<max){
		int mid = min + (max-min)/2;
		if(key<array[mid])return binary_seaach(array,key,min,mid);
		else if(array[mid]<key)return binary_seaach(array,key,mid+1,max);
	}
	if(key>array[min])return min+1;
	return min;
}


int main(void){
	int A,B,Q,i;
	scanf("%d%d%d",&A,&B,&Q);
	long long s[LIM+2],t[LIM+2],ans,x,r;
	for(i=1;i<=A;i++)scanf("%lld",&s[i]);
	for(i=1;i<=B;i++)scanf("%lld",&t[i]);
	s[0] = t[0] = -INF;
	s[A+1] = t[B+1] = INF;
	for(i=0;i<Q;i++){
		scanf("%lld",&x);
		ans=INF;
		
		int b,d,j,k;
		b = binary_seaach(s,x,0,A+1);
		d = binary_seaach(t,x,0,B+1);
		
		for(j=b-1;j<=b;j++){
			for(k=d-1;k<=d;k++){
				r = llabs(s[j]-x)+llabs(t[k]-s[j]);
				ans = r<ans?r:ans;
				r = llabs(t[k]-x)+llabs(s[j]-t[k]);
				ans = r<ans?r:ans;
			}
		}
		
		
		printf("%lld\n",ans);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:19:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d",&A,&B,&Q);
  ^
./Main.c:21:19: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i=1;i<=A;i++)scanf("%lld",&s[i]);
                   ^
./Main.c:22:19: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i=1;i<=B;i++)scanf("%lld",&t[i]);
                   ^
./Main.c:26:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&x);
   ^