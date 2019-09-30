#include <stdio.h>
char lake[10][10];
char original[10][10];
int dx[4] = {1,0,-1,0},dy[4] = {0,1,0,-1};
int count =0;
void dfs(int x,int y){
	int i = 0;
	lake[x][y]='x';
	for(i = 0;i < 4;i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(0<=nx&&nx<10&&0<=ny&&ny<10&&lake[nx][ny]=='o'){
			dfs(nx,ny);
		}
	}
}
void copy(void){
	int i;
	int j;
	for(i = 0;i < 10;i++){
		for(j = 0;j < 10;j++){
			lake[i][j] = original[i][j];
		}
	}
}
int check(void){
	int i = 0;
	int j = 0;
	for(i = 0;i < 10;i++){
		for(j = 0;j < 10;j++){
			if(lake[i][j] == 'o'){
				return 0;
			}
		}
	}
	return 1;
}
int main(void){
	int i = 0;
	int j = 0;
	for(i = 0;i < 10;i++){
		scanf("%s",lake[i]);
	}
	for(i = 0;i < 10;i++){
		for(j = 0;j < 10;j++){
			original[i][j] = lake[i][j];
		}
	}
	for(i = 0;i < 10;i++){
		for(j = 0;j <10 ;j++){
			copy();
			dfs(i,j);
			if(check() == 1){
				printf("YES\n");
				return 0;
			}
		}
	}
	printf("NO\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:42:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",lake[i]);
   ^