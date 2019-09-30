#include <stdio.h>

int main(void)
{
	int a, b, c, x, y, z;
	int n = 0;
	scanf("%d %d %d", &a, &b, &c);
	
	while(1){
		if(a%2==1 || b%2==1 || c%2==1){
			printf("%d\n", n);
			break;
		}
		n++;
		x = b/2 + c/2;
		y = a/2 + c/2;
		z = a/2 + b/2;
		a = x;
		b = y;
		c = z;
		if(a == b && b == c){
			printf("-1\n");
			break;
		}
	}
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d", &a, &b, &c);
  ^