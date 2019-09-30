#include<stdio.h>
#include<stdlib.h>

#define N 100000

int compare_int(const void *a,const void *b){
	return *(long long*)b-*(long long*)a;
}

int main(){
	int n,i,j;
	long long h,a[N],b[N];
	scanf("%d%lld",&n,&h);
	for(i=0;i<n;i++)scanf("%lld%lld",&a[i],&b[i]);
	qsort(a,n,sizeof(long long),compare_int);
	qsort(b,n,sizeof(long long),compare_int);
	int tmp,ans=0;
	for(i=0;i<n;i++){
		if(h<=0)break;
		if(a[0]>b[i])break;
		h-=b[i];
		ans++;
	}
	if(h>0){
		ans+=h/a[0];
		h%=a[0];
		if(h>0)ans++;
	}
	printf("%d\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%lld",&n,&h);
  ^
./Main.c:14:18: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i=0;i<n;i++)scanf("%lld%lld",&a[i],&b[i]);
                  ^