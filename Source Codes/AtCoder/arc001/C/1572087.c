#include <stdio.h>
#include <stdlib.h>

#define QUEEN_NUM 8
#define COLUMN_NUM 8

char queen_p[QUEEN_NUM + 1][QUEEN_NUM + 1] = {
	"........",
	"........",
	"........",
	"........",
	"........",
	"........",
	"........",
	"........",
	"........"
};

int x[QUEEN_NUM] = {8, 8, 8, 8, 8, 8, 8, 8};
int y[QUEEN_NUM] = {8, 8, 8, 8, 8, 8, 8, 8};

void update_queens(void)
{
	int i;

	for(i = 0; i < QUEEN_NUM; i++)
		queen_p[y[i]][x[i]] = 'Q';
}

void disp_queens(void)
{
	int i, j;

	for(i = 0; i < QUEEN_NUM; i++) {
		for(j = 0; j < QUEEN_NUM; j++) {
			printf("%c", queen_p[i][j]);
		}
		puts("");
	}

}

int is_exists_in_cross(int queen_num)
{
	int i;

	for(i = 0; i < queen_num; i++)
		if(abs(x[queen_num] - x[i]) == abs(y[queen_num] - y[i]))
			return 1;
	return 0;
}

int is_exists_in_column(int queen_num)
{
	int i;

	for(i = 0; i < queen_num; i++)
		if(x[queen_num] == x[i])
			return 1;
	return 0;
}

void queen(int queen_num)
{
	int i;

	if(queen_num == QUEEN_NUM - 1) {
		for(i = 0; i < COLUMN_NUM; i++) {
			x[queen_num] = i;
			if(is_exists_in_column(queen_num))
				continue;
			if(is_exists_in_cross(queen_num))
				continue;
			update_queens();
			disp_queens();
			exit(0);
		}
	} else {
		for(i = 0; i < COLUMN_NUM; i++) {
			x[queen_num] = i;
			if(is_exists_in_column(queen_num))
				continue;
			if(is_exists_in_cross(queen_num))
				continue;
			queen(queen_num + 1);
		}
	}
}

int main(void)
{
	int i, j, queen_i, queen_fix;

	// read data
	{
		for(i = queen_i = 0; i < QUEEN_NUM; i++) {
			char ch;
			int Q_ctr = 0;

			for(j = 0; (ch = fgetc(stdin)) != '\n'; j++) {
				if(ch == 'Q') {
					if(++Q_ctr >= 2) 
						goto noanswer;

					x[queen_i] = j;
					y[queen_i] = i;
					if(is_exists_in_cross(queen_i))
						goto noanswer;
					if(is_exists_in_column(queen_i))
						goto noanswer;
					queen_i++;
				}
			}
		}
	}
	queen_fix = queen_i;

	// load y
	for(i = 0; i < QUEEN_NUM; i++){
		if(i == y[0] || i == y[1] || i == y[2])
			continue;
		y[queen_i++] = i;
	}

	// queen
	queen(queen_fix);

noanswer:
	puts("No Answer");
	return 0;
}