#include <stdio.h>

int max(int a, int b){return a > b ? a : b;}

int main(void){
	int w, h, n, x, y, a;
	int sx = 0, ex, sy = 0, ey;
	scanf("%d %d %d", &w, &h, &n);
	ex = w; ey = h;
	for(int i = 0; i < n; i++){
		scanf("%d %d %d", &x, &y, &a);
		switch(a){
			case 1:
				if(sx < x)sx = x;
				break;
			case 2:
				if(x < ex)ex = x;
				break;
			case 3:
				if(sy < y)sy = y;
				break;
			case 4:
				if(y < ey)ey = y;
				break;
			default:
				break;
		}
	}
	printf("%d\n", max(ey - sy, 0) * max(ex - sx, 0));
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d", &w, &h, &n);
  ^
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d", &x, &y, &a);
   ^