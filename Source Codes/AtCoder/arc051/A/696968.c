#include <stdio.h>
#include <string.h>

int main() {
	int x1, x2, x3, y1, y2, y3, r;
	int d[4];
	char blue[4], red[4];
	scanf("%d%d%d", &x1, &y1, &r);
	scanf("%d%d%d%d", &x2, &y2, &x3, &y3);

	d[0] = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
	d[1] = (x1-x2)*(x1-x2) + (y1-y3)*(y1-y3);
	d[2] = (x1-x3)*(x1-x3) + (y1-y2)*(y1-y2);
	d[3] = (x1-x3)*(x1-x3) + (y1-y3)*(y1-y3);
	if (d[0]<=r*r && d[1]<=r*r && d[2]<=r*r && d[3]<=r*r) strcpy(blue, "NO");
	else strcpy(blue, "YES");

	if (x2<=x1-r && x1+r<=x3 && y2<=y1-r && y1+r<=y3) strcpy(red, "NO");
	else strcpy(red, "YES");

	printf("%s\n%s\n", red, blue);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d", &x1, &y1, &r);
  ^
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d%d", &x2, &y2, &x3, &y3);
  ^