#include<stdio.h>
int a, b, c, x, y, z, i, j;
int ans;
int main(){
	scanf("%d%d%d%d", &a, &b, &c, &x);
	x /= 50;
	y = x-c;
	for(i=0; i<=a; i++){
		for(j=0; j<=b; j++){
			z = i*10 + j*2;
			if(y<=z && z<=x){ans++;}
		}
	}
	printf("%d\n", ans);
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d%d", &a, &b, &c, &x);
  ^