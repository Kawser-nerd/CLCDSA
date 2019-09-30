#include <stdio.h>
int main(){
	int a, b, c, d;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	if(a>=c){
		if(a>=d)printf("0\n");
		else{
			if(b<=d)printf("%d\n",b-a);
			else printf("%d\n", d-a);
		}
	}
	else{
		if(b<=c)printf("0\n");
		else{
			if(b<=d)printf("%d\n",b-c);
			else printf("%d\n", d-c);
		}
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d%d", &a, &b, &c, &d);
  ^