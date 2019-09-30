#include <stdio.h>
#include<stdlib.h>
#define MAX 1000000

int main(){
	int *p;
	p = (int *)malloc(sizeof(int)*1);
	scanf("%d",p);
	*p = *p - 1;
	int a[MAX];
	for(int i = 0;i < MAX;i++){
		a[i]=0;
	}
	a[2]=1;
	for(int i = 3;i <=*p;i++){
		a[i] = (a[i-1]+a[i-2]+a[i-3])%10007 ;		
	}	
	printf("%d\n",a[*p]%10007);
	return 0;
	
	} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",p);
  ^