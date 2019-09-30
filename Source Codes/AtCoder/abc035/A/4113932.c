#include <stdio.h>

int gcd(int a, int b){
	int c;
	while(a != 0){
		c = a;
		a = b % a;
		b = c;
	}
	return c;
}

int main(void){
	int w, h;
	scanf("%d %d", &w, &h);
	if(w / gcd(w, h) == 4)
		printf("4:3\n");
	else
		printf("16:9\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:15:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d", &w, &h);
  ^