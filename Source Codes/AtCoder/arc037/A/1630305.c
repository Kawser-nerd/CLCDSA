#include<stdio.h>
int main(){
	int n,a,s=0;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&a);
		if(80>a)s+=80-a;
	}
	printf("%d\n",s);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&a);
   ^