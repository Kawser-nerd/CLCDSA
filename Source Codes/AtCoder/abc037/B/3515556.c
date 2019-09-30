#include <stdio.h>
int main(void){
	int n,q,i;
	scanf("%d%d",&n,&q);
	int l[q],r[q];
	long long t[q],a[n];
	for(i=0;i<q;i++)scanf("%d %d %lld",&l[i],&r[i],&t[i]);
	for(i=0;i<n;i++)a[i]=0;
	for(i=0;i<q;i++){
		for(int j=l[i]-1;j<r[i];j++){
			a[j]=t[i];
		}
	}
	for(i=0;i<n;i++)printf("%lld\n",a[i]);
	
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&n,&q);
  ^
./Main.c:7:18: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i=0;i<q;i++)scanf("%d %d %lld",&l[i],&r[i],&t[i]);
                  ^