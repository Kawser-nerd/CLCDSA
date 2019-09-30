#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int t, tc = 1;
	int r, c;
	int i, j, k;
	char *grid[30];
	char visited[30];

	for(i = 0; i < 30; ++i) {
		grid[i] = (char*) malloc(30*sizeof(char));
	}

	scanf("%d", &t);
	while(t--) {
		scanf("%d %d", &r, &c);
		for(i = 0; i < r; ++i) {
			scanf("%s", grid[i]);
		}
		for(j = 0; j < c; ++j) {
			for(i = 0; i < r; ++i) {
				if(grid[i][j] != '?') {
					for(k = i+1; k < r; ++k) {
						if(grid[k][j] == '?') {
							grid[k][j] = grid[i][j];
						}
						else {
							break;
						}
					}
					for(k = i-1; k > -1; --k) {
						if(grid[k][j] == '?') {
							grid[k][j] = grid[i][j];
						}
						else {
							break;
						}
					}
				}
			}
		}
		for(i = 0; i < r; ++i) {
			for(j = 0; j < c; ++j) {
				if(grid[i][j] != '?') {
					for(k = j+1; k < c; ++k) {
						if(grid[i][k] == '?') {
							grid[i][k] = grid[i][j];
						}
						else {
							break;
						}
					}
					for(k = j-1; k > -1; --k) {
						if(grid[i][k] == '?') {
							grid[i][k] = grid[i][j];
						}
						else {
							break;
						}
					}
				}
			}
		}
		printf("Case #%d:\n", tc++);
		for(i = 0; i < r; ++i) {
			printf("%s\n", grid[i]);
		}
	}
	return 0;
}
