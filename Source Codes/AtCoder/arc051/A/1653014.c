#include <stdio.h>

int main(){
	int x1, y1, r, x2, y2, x3, y3;
	scanf("%d%d%d", &x1, &y1, &r);
	scanf("%d%d%d%d", &x2, &y2, &x3, &y3);
	if(x1 - r < x2 || x3 < x1 + r || y1 - r < y2 || y3 < y1 + r){
		printf("YES\n");
	}
	else{
		printf("NO\n");
	}
	if((x2 - x1)* (x2 - x1) + (y2 - y1) * (y2 - y1) > r * r || (x3 - x1)* (x3 - x1) + (y2 - y1) * (y2 - y1) > r * r || (x2 - x1)* (x2 - x1) + (y3 - y1) * (y3 - y1) > r * r || (x3 - x1)* (x3 - x1) + (y3 - y1) * (y3 - y1) > r * r){
		printf("YES\n");
	}
	else{
		printf("NO\n");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d", &x1, &y1, &r);
  ^
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d%d", &x2, &y2, &x3, &y3);
  ^