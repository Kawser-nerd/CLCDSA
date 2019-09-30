#include<stdio.h>
#include<math.h>
int main() {
	int sta[2],fin[2];
	int time, speed;
	int num,i;
	int girl[1000][2];

	scanf("%d%d%d%d", &sta[0], &sta[1], &fin[0], &fin[1]);
	scanf("%d%d%d", &time, &speed, &num);
	for (i = 0; i < num; i++) {
		scanf("%d%d", &girl[i][0], &girl[i][1]);
	}
	int move = time * speed;

	for (i = 0; i < num; i++) {
		int xdis = sta[0] - girl[i][0],ydis=sta[1]-girl[i][1];
		double len1 = sqrt((xdis*xdis) + (ydis*ydis));
		xdis = girl[i][0] - fin[0];
		ydis = girl[i][1] - fin[1];
		double len2 = sqrt((xdis*xdis) + (ydis*ydis));
		if (move >= (len1 + len2)) {
			puts("YES");
			return 0;
		}
	}
	puts("NO");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d%d", &sta[0], &sta[1], &fin[0], &fin[1]);
  ^
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d", &time, &speed, &num);
  ^
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &girl[i][0], &girl[i][1]);
   ^