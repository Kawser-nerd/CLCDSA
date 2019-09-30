#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int H, W;
char S[100][100];
int ans[100][100];

int check(int y, int x) {
	if(y < 0 || y >= H || x < 0 || x >= W || S[y][x] == '#') return 1;
	else return 0;
}

int reverse_check() {
	int i, j, y, x, yy, xx;
	int dx[] = {-1, 0, 1};
	int dy[] = {-1, 0, 1};
	char map[100][100];
	
	for(i=0;i<H;i++) {
		for(j=0;j<W;j++) {
			map[i][j] = '.';
		}
	}
	
	for(i=0;i<H;i++) {
		for(j=0;j<W;j++) {
			if(ans[i][j]) {
				for(y=0;y<3;y++) {
					for(x=0;x<3;x++) {
						xx = j+dx[x];
						yy = i+dy[y];
						if(!(yy < 0 || yy >= H || xx < 0 || xx >= W)) {
							map[yy][xx] = '#';
						}
					}
				}
			}
		}
	}
	
	for(i=0;i<H;i++) {
		for(j=0;j<W;j++) {
			if(S[i][j] != map[i][j]) return 0;
		}
	}
	return 1;
}

int main() {
	int i, j, x, y;
	int dx[] = {-1, 0, 1};
	int dy[] = {-1, 0, 1};
	
	scanf("%d %d", &H, &W);
	for(i=0;i<H;i++) scanf("%s", S[i]);
	
	for(i=0;i<H;i++) {
		for(j=0;j<W;j++) {
			ans[i][j] = 1;
			for(y=0;y<3;y++) {
				for(x=0;x<3;x++) {
					ans[i][j] &= check(i+dy[y], j+dx[x]);
				}
			}
		}
	}
	
	if(reverse_check() == 0) {
		printf("impossible\n");
		return 0;
	}
	
	printf("possible\n");
	for(i=0;i<H;i++) {
		for(j=0;j<W;j++) {
			if(ans[i][j]) printf("#");
			else printf(".");
		}
		printf("\n");
	}
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:56:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d", &H, &W);
  ^
./Main.c:57:19: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i=0;i<H;i++) scanf("%s", S[i]);
                   ^