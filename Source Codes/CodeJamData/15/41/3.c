#include<stdio.h>
#include<stdlib.h>
#include<string.h>


// for qsort
/*
int compare(int *t, int *s) {
    return *t - *s;
}
*/

int R, C;
int cell[100][100];
int result;
int dir_x[] = { 0, -1, 1, 0, 0 };
int dir_y[] = { 0, 0, 0, -1, 1 };


int search(int x, int y, int dir) {
    int i, j;
    i = x + dir_x[dir];
    j = y + dir_y[dir];
    if(i < 0 || i >= R || j < 0 || j >= C) {
        return 0;
    }
    if(cell[i][j]) return 1;

    return search(i, j, dir);
}



void solve(void) {
    int x, y;
    int dir;

    for(x = 0; x < R; ++x) {
        for(y = 0; y < C; ++y) {
            dir = cell[x][y];
            if(!dir) continue;
            if(search(x, y, dir)) {
                continue;
            }
            if(search(x, y, 1) || search(x, y, 2) || search(x, y, 3) || search(x, y, 4)) result++;
            else {
                result = -1;
                return;
            }
        }
    }
}

void solve_and_print(void) {
    int i, j;
    char buf[102];

    scanf("%d %d", &R, &C);
    gets(buf);
    for(i = 0; i < R; ++i) {
        gets(buf);
        for(j = 0; j < C; ++j) {
            switch(buf[j]) {
            case '.':
                cell[i][j] = 0;
                break;
            case '^':
                cell[i][j] = 1;
                break;
            case 'v':
                cell[i][j] = 2;
                break;
            case '<':
                cell[i][j] = 3;
                break;
            case '>':
                cell[i][j] = 4;
                break;
            default:
                fprintf(stderr, "input error\n");
            }
        }
    }
    result = 0;
    solve();
    // something to print answer
    if(result < 0) printf("IMPOSSIBLE\n");
    else printf("%d\n", result);
}


int main(void) {
    int dataset_num, case_num;

    scanf("%d", &dataset_num);
    for(case_num = 1; case_num <= dataset_num; ++case_num) {
        printf("Case #%d: ", case_num);

        solve_and_print();
    }

    return 0;
}
