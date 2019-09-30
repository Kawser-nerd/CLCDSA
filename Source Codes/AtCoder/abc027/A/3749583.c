#include<stdio.h>
int a, b, c, d;
int main(){
	scanf("%d%d%d", &a, &b, &c);
	if(a==b){
		d=c;
	}else{
		if(a==c){
			d=b;
		}else{
			d=a;
		}
	}
	printf("%d\n", d);
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d", &a, &b, &c);
  ^