#include<stdio.h>
#define abs(x) (((x)<0)?-(x):(x))
long d[500000],q[500000],a[500001],b[500001];

int main(int argc, char const *argv[]){
	long n,D,Q,i;
	scanf("%ld %ld",&n,&D);
	a[0]=D;
	for(i=0;i<n;i++){
		scanf("%ld",&d[i]);
		if(abs(a[i]-d[i])<a[i]) a[i+1]=abs(a[i]-d[i]);
		else a[i+1]=a[i];
	}
	b[n]=1;
	for(i=n-1;i>=0;i--){
		if(b[i+1]<=d[i]/2) b[i]=b[i+1];
		else{
			b[i]=b[i+1]+d[i];
		}
	}
	scanf("%ld",&Q);
	for(i=0;i<Q;i++){
		scanf("%ld",&q[i]);
	}
	for(i=0;i<Q;i++){
		if(a[q[i]-1]>=b[q[i]]) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%ld %ld",&n,&D);
  ^
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld",&d[i]);
   ^
./Main.c:21:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%ld",&Q);
  ^
./Main.c:23:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld",&q[i]);
   ^