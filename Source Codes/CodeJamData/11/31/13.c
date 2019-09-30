#include <stdio.h>

int r, c;
char map[51][51];

int redtile(){
	int i, j;
	for(i = 0; i < r ; ++i)
		for(j = 0; j < c; ++j)
			if(map[i][j] == '#')
				goto REPLACE;
	return 1;
REPLACE:
	if (map[i + 1][j] == '#' && map[i][j + 1] == '#' && map[i + 1][j + 1] == '#'){
		map[i][j] = '/';
		map[i][j + 1] = '\\';
		map[i + 1][j] = '\\';
		map[i + 1][j + 1] = '/';
		return redtile();
	}
	return 0;
}

int main(){
	int t;
	scanf("%d", &t);
	int k;
	int i, j;
	for(k = 1; k <= t; ++k){
		scanf("%d %d", &r, &c);
		for(i = 0; i < r; ++i){
			for(j = 0; j < c; ++j)
				scanf(" %c", &map[i][j]);
			map[i][c] = '.';
		}
		for(j = 0; j <= c; ++j)
			map[r][j] = '.';
		printf("Case #%d:\n", k);
		if(redtile()){
			for(i = 0; i < r; ++i){
				for(j = 0; j < c; ++j)
					printf("%c", map[i][j]);
				printf("\n");
			}
		}else printf("Impossible\n");
	}
	return 0;
}
