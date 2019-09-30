#include <stdio.h>

int main(){
	int a[5];
	int i,tmp,count=0;
	
	for(i=0;i<3;i++){
		scanf("%d ",&a[i]);
	}
	
	while(count<10){
	for(i=0;i<2;i++){
		if(a[i]<a[i+1]){
			tmp = a[i];
			a[i] = a[i+1];
			a[i+1] = tmp;
		}
	}
	count++;
	}
	
	printf("%d\n",a[1]);
	
	return 0;
	
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d ",&a[i]);
   ^