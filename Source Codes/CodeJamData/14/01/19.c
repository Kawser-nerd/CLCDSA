#include <stdio.h>
#include <math.h>

void readBoard(int board[4][4]) {
	int i,j;
	for(i=0; i<4; i++) {
		scanf("%u %u %u %u\n", &board[i][0], &board[i][1], &board[i][2], &board[i][3]);
	}
}
		
int main() {
	int t;
	int row1, row2;
	scanf("%u\n", &t);
	int board1[4][4];
	int board2[4][4];
	int answer;

	int i,j,k;
	
	for(i=1; i<=t; i++) {
		scanf("%u\n",&row1);
		readBoard(board1);
		scanf("%u\n",&row2);
		readBoard(board2);
		answer = -1;
		row1--; row2--; //get them to be zero-based indexes

		for(j=0; j<4; j++) {
			for(k=0; k<4; k++) {
				if(board1[row1][j]==board2[row2][k]) {
					if(answer == -1) {
						answer = board1[row1][j];
					} else {
						answer = -2; break;
					}
				}
			}
		}

		if(answer == -1) { //cheat
			printf("Case #%u: Volunteer cheated!\n",i);
		} else if (answer == -2) { //bad
			printf("Case #%u: Bad magician!\n",i);
		} else {
			printf("Case #%u: %u\n",i,answer);
		}
	}
	return 0;
}
