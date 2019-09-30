#include<stdio.h>
int main(void){
	int N;
	scanf("%d",&N);
	int a,b;
	int c=0;
	int d=0;
	for(a=1;a<=N;a++){
		if((a%2)==1){
			for(b=1;b<=a;b++){
				if((a%b)==0){
					c++;
				}
			}
		}
		if(c==8){
			d++;
		}
		c=0;
	}
	printf("%d",d);
return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&N);
  ^