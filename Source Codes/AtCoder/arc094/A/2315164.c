#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void change(int *x, int *y);

int a,b,c;
int ans=0;

int main(void){
	scanf("%d %d %d", &a, &b, &c);

	//??????????
	if(a<b)	change(&a, &b);
	if(b<c)	change(&b, &c);
	if(a<b)	change(&a, &b);
	if(b<c)	change(&b, &c);
	if(a<b)	change(&a, &b);
	if(b<c)	change(&b, &c);

	ans += a-b;
	c += a-b;
	b += a-b;
	if( (a-c) % 2 == 0)	ans += (a-c)/2;
	else	ans += ((a+1-c)/2 + 1); 
 		
	printf("%d", ans);

	return 0;
}

void change(int *x, int *y){
	int z;
	z = *x;
	*x = *y;
	*y = z;
} ./Main.c: In function ‘main’:
./Main.c:11:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d", &a, &b, &c);
  ^