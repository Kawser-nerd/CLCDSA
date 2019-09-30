#include <stdio.h>
int main(void){
	int i,n,a,f=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a);
		if(a==2) f+=1;
		if(a==4) f+=1;
		if(a==5) f+=2;
		if(a==6) f+=3;
		if(a==8) f+=1;
	}
	printf("%d\n",f);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&a);
   ^