#include<stdio.h>
	#include<string.h>
	int main(){
	char a[100000]={0};
	int num=0,i,n;
  scanf("%s",a);
	for(i=0;i<strlen(a)-1;i++){
		if(a[i]!=a[i+1])
			num++;
	}
	printf("%d",num);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",a);
   ^