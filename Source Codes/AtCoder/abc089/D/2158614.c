#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

struct{
	int x;
	int y;
	int cost;
} mArray[300 * 300] = { 0 };

int main(void)
{
	int h, w, d;
	scanf("%d %d %d", &h, &w, &d);
	int i, j;
	int dx, dy;
	int q;

	for (i = 0; i < h; ++i){
		for (j = 0; j < w; ++j){
			int a;
			scanf("%d", &a);
			--a;
			mArray[a].x = i;
			mArray[a].y = j;
		}
	}

	for (i = 0; i + d < h*w; ++i){
		dx = mArray[i].x > mArray[i + d].x ? mArray[i].x - mArray[i + d].x : mArray[i + d].x - mArray[i].x;
		dy = mArray[i].y > mArray[i + d].y ? mArray[i].y - mArray[i + d].y : mArray[i + d].y - mArray[i].y;
		mArray[i + d].cost = mArray[i].cost + dx + dy;
	}

	scanf("%d", &q);
	for (i = 0; i < q; ++i){
		int l, r;
		scanf("%d%d", &l, &r);
		--l, --r;
		printf("%d\n", mArray[r].cost - mArray[l].cost);
	}

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:14:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d", &h, &w, &d);
  ^
./Main.c:22:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d", &a);
    ^
./Main.c:35:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &q);
  ^
./Main.c:38:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &l, &r);
   ^