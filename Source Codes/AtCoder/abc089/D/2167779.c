#include <stdio.h>
int abs(x){
	return (x>0)?x:(-x);
}
int main() {
	int h, w, d, q;
	int a;
	int x[100000] = {}, y[100000] = {};
	int dis[100000] = {};
	scanf("%d%d%d", &h, &w, &d);
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			scanf("%d", &a);
			x[a] = i;
			y[a] = j;
		}
	}
	scanf("%d", &q);
	for (int i = d + 1; i <= h*w; i++)
	{
		dis[i] = dis[i - d] + abs(x[i] - x[i - d]) + abs(y[i] - y[i - d]);
	}
	int l, r;
	for (int i = 0; i < q; i++)
	{
		scanf("%d%d",&l, &r);
		printf("%d\n", dis[r] - dis[l]);
	}
	return 0;
} ./Main.c: In function ‘abs’:
./Main.c:2:5: warning: type of ‘x’ defaults to ‘int’ [-Wimplicit-int]
 int abs(x){
     ^
./Main.c: In function ‘main’:
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d", &h, &w, &d);
  ^
./Main.c:15:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d", &a);
    ^
./Main.c:20:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &q);
  ^
./Main.c:28:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&l, &r);
   ^