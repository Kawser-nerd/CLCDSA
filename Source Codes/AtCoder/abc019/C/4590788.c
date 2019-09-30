#include<stdio.h>
#include<stdlib.h>

#define N 100000

int compare_int(const void *a,const void *b){
	long long A=*(long long*)a;
	long long B=*(long long*)b;
	if(A>B)return 1;
	if(A==B)return 0;
	if(A<B)return -1;
}
	

int main(){
	int n,i,ans=1,c;
	long long a[N];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%lld",&a[i]);
		while(a[i]%2==0)a[i]/=2;
	}
	qsort(a,n,sizeof(long long),compare_int);
	c=a[0];
	for(i=1;i<n;i++){
		if(c!=a[i]){
			ans++;
			c=a[i];
		}
	}
	printf("%d\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:18:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:20:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&a[i]);
   ^