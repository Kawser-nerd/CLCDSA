#include<stdio.h>
int main() {
	int a, b, c, d;
	char e, f, g, h;
	scanf("%c%c%c%c", &e, &f, &g, &h);
	a = (int)(e-'0');
	b = (int)(f-'0');
	c = (int)(g-'0');
	d = (int)(h-'0');
	if(a+b+c+d==7) {
		printf("%d+%d+%d+%d=7",a,b,c,d);
	} else if(a+b+c-d==7) {
			printf("%d+%d+%d-%d=7",a,b,c,d);
	} else if(a+b-c+d==7) {
			printf("%d+%d-%d+%d=7",a,b,c,d);
	} else if(a+b-c-d==7) {
			printf("%d+%d-%d-%d=7",a,b,c,d);
	} else if(a-b+c+d==7) {
			printf("%d-%d+%d+%d=7",a,b,c,d);
	} else if(a-b+c-d==7) {
			printf("%d-%d+%d-%d=7",a,b,c,d);
	} else if(a-b-c+d==7) {
			printf("%d-%d-%d+%d=7",a,b,c,d);
	} else  {
			printf("%d-%d-%d-%d=7",a,b,c,d);
	} 
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%c%c%c%c", &e, &f, &g, &h);
  ^