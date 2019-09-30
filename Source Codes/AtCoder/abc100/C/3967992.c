#include<stdio.h>

int main(){
	int n;scanf("%d",&n);
	int a,i,sum=0;
	
	for(i=0;i<n;i++){
		scanf("%d",&a);
		while(a%2==0){sum++;a/=2;}
	}
	
	printf("%d",sum);
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:8: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  int n;scanf("%d",&n);
        ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&a);
   ^