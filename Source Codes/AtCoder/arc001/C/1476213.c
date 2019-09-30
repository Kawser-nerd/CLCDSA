#include <stdio.h>
#include <stdlib.h>

int N = 8;
int no_answer = 0;
int success = 0;

void print_board(char **board){
	int i, j;
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			printf("%c", board[i][j]);
		}
		printf("\n");
	}
}

void draw_way(char **board, int x, int y, int dx, int dy){
	if(0 <= x && x < N && 0 <= y && y <= N){
		if(board[x][y] == 'Q'){
			no_answer = 1;
			return;
		}
		board[x][y] = 'T';
		draw_way(board, x + dx, y + dy, dx, dy);
	}
}

void draw_queen_ways(char **board, int x, int y){
	draw_way(board, x - 1, y - 1, -1, -1);
	draw_way(board, x - 1, y    , -1,  0);
	draw_way(board, x - 1, y + 1, -1,  1);
	draw_way(board, x    , y - 1,  0, -1);
	draw_way(board, x    , y + 1,  0,  1);
	draw_way(board, x + 1, y - 1,  1, -1);
	draw_way(board, x + 1, y    ,  1,  0);
	draw_way(board, x + 1, y + 1,  1,  1);
}

void copy_board(char **board1, char **board2){
	int i, j;
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			board2[i][j] = board1[i][j];
		}
	}
}

void DFS(char **board, int m){
	if(m == 0){
		success = 1;
		return;
	}
	int i, j;
	char **next_board = (char **)malloc(sizeof(char *) * N);
	for(i = 0; i < N; i++){
		next_board[i] = (char *)malloc(sizeof(char) * N);
	}
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			if(board[i][j] == '.'){
				copy_board(board, next_board);
				next_board[i][j] = 'Q';
				draw_queen_ways(next_board, i, j);
				DFS(next_board, m - 1);
				if(success == 1){
					copy_board(next_board, board);
					return;
				}
			}
		}
	}
}

int main(){
	int i, j;
	char c;
	char **board = (char **)malloc(sizeof(char *) * N);
	for(i = 0; i < N; i++){
		board[i] = (char *)malloc(sizeof(char) * N);
		for(j = 0; j < N; j++){
			scanf("%c", &board[i][j]);
		}
		scanf("%c", &c);
	}
//	print_board(board);
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			if(board[i][j] == 'Q'){
				draw_queen_ways(board, i, j);
			}
		}
	}
//	print_board(board);
	if(no_answer == 1){
		printf("No Answer\n");
		return 0;
	}
	DFS(board, 5);
	if(success == 1){
		for(i = 0; i < N; i++){
			for(j = 0; j < N; j++){
				if(board[i][j] == 'Q'){
					printf("Q");
				}
				else{
					printf(".");
				}
			}
			printf("\n");
		}
	}
	else{
		printf("No Answer\n");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:82:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%c", &board[i][j]);
    ^
./Main.c:84:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%c", &c);
   ^