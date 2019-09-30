#include <stdio.h>
#include <string.h>

int conv(char c)
{
	switch(c) {
		case 'X':
			return 0;
		break;

		case 'O':
			return 1;
		break;

		case 'T':
			return 2;
		break;

		case '.':
			return -1;
		break;
	}
	return -1;
}

int main()
{
	int cas_n, cas, row, col, index, i, tmp, flag;
	int sum[10][3];
	char board[5][5], c;

	scanf("%d", &cas_n);
	getc(stdin);
	for(cas=1; cas<=cas_n; cas++) {
		flag = 0;
		printf("Case #%d: ", cas);
		if( cas > 1 )
			getc(stdin);
		for(row=0; row<4; row++) {
			fgets(board[row], sizeof(board[0]), stdin);
			getc(stdin);
			//puts(board[row]);
		}

		memset(sum, 0, sizeof(sum));
		// check winner
		for(index=0; index<4; index++) {
			for(i=0; i<4; i++) {
				tmp = conv( board[index][i] );
				if( tmp >= 0 )
					sum[index][tmp]++;
				tmp = conv( board[i][index] );
				if( tmp >= 0 )
					sum[4 + index][tmp]++;
			}
			tmp = conv( board[index][index] );
			if( tmp >= 0 )
				sum[8][tmp]++;
			tmp = conv( board[index][3 - index] );
			if( tmp >= 0 )
				sum[9][tmp]++;
		}
		for(i=0; i<10; i++) {
			if( sum[i][0] + sum[i][2] == 4 ) {
				puts("X won");
				flag = 1;
				break;
			}
			else if(sum[i][1] + sum[i][2] == 4 ) {
				puts("O won");
				flag = 1;
				break;
			}
		}
		if( flag )
			continue;

		// check completed
		for(row=0; row<4 && flag==0; row++) {
			for(col=0; col<4; col++) {
				if( board[row][col] == '.' ) {
					puts("Game has not completed");
					flag = 1;
					break;
				}
			}
		}
		if( flag )
			continue;
		else
			puts("Draw");
	}
	return 0;
}
