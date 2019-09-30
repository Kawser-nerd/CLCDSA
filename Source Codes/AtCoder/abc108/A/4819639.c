#include<stdio.h>
int main(void){
	int K;
	scanf("%d",&K);
	int a;
	int e=0;
	int o=0;
	for(a=1;a<K+1;a++){
		if((a%2)==0){
			e++;
		}else{
			o++;
		}
	}
	printf("%d",(e*o));
return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&K);
  ^