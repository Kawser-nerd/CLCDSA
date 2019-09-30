#include "stdio.h"
 
int main()
{
	int i, n, a = 0, b = 0, c = 0, d = 0, e = 0, f = 0;
	float ina, inb;
 
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%f %f", &ina ,&inb);
        
		//a
		if (ina >= 35.0)a++;
		//b
		if (35.0>ina && ina >= 30.0)b++;
		//c
		if (30.0>ina && ina >= 25.0)c++;
		//d
		if (inb >= 25.0)d++;
		//e
		if (0 <= ina && inb < 0.0)e++;
		//f
		if (ina < 0.0)f++;
 
	}
	printf("%d %d %d %d %d %d\n", a,b,c,d,e,f);
 
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%f %f", &ina ,&inb);
   ^