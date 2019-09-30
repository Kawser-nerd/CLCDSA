#include<stdio.h>
#include<stdlib.h>

int compare_int(const void *a,const void *b){
	return *(long*)a-*(long*)b;
}

int main(){
	int n,i,ans=0;
	long a[100000],c;
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%ld",&a[i]);
	qsort(a,n,sizeof(long),compare_int);
	c=a[0];ans=n;
	for(i=1;i<n;i++){
		if(c==a[i]){
			c=-1;
			ans-=2;
		}else c=a[i];
	}
	printf("%d\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:12:18: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i=0;i<n;i++)scanf("%ld",&a[i]);
                  ^