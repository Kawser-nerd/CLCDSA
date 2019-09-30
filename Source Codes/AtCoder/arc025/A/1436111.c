#include<stdio.h>
int main(){
	int a[10],b,s=0,i;
	for(i=0;i<7;i++)scanf("%d",&a[i]);
	for(i=0;i<7;i++){
		scanf("%d",&b);
		s+=a[i]<b?b:a[i];
	}
	printf("%d\n",s);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:18: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i=0;i<7;i++)scanf("%d",&a[i]);
                  ^
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&b);
   ^