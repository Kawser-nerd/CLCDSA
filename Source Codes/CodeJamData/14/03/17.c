#include<stdio.h>
#include<stdlib.h>
#include<string.h>


// for qsort
/*
int compare(int *t, int *s) {
    return *t - *s;
}
*/

int mat[50][50];
char output[3] = {'*' , 'c', '.' };
int col, row, mine, emp;

void make_matrix(void) {
    int c, r; // c,rは必ず空白を取れる矩形
    int i, j;
    c = r = 3;
    while(r < row) {
        if(c * ++r > emp) { --r; break; }
    }
    while(c < col) {
        if(++c * r > emp) { --c; break; }
    }
    for(i = 0; i < c; ++i) {
        for(j = 0; j < r; ++j) {
            mat[i][j] = 2;
        }
    }

    j = emp - c * r; // まだ足りない空白

    if(j == 0) return;
    if(j == 1) { // 1だけ足りない場合、そこが開かない可能性があるので一つ矩形から調達
        if(r >= row) {
            mat[c][0] = mat[c][1] = 2;
            mat[c-1][r-1] = 0;
        }
        else {
            mat[0][r] = mat[1][r] = 2;
            mat[c-1][r-1] = 0;
        }
        return;
    }
    if(r == row) {
        for(i = 0; i < j; ++i) {
            mat[c][i] = 2;
        }
    }
    else {
        for(i = 0; i < j; ++i) {
            mat[i][r] = 2;
        }
    }
}

void print_matrix(void) {
    int i, j;
    for(i = 0; i < col; ++i) {
        for(j = 0; j < row; ++j) {
            putchar(output[mat[i][j]]);
        }
        putchar('\n');
    }
}


int main(void) {
    int num, try_num;
    int N;
    int i;

    scanf("%d", &num);
    for(try_num = 1; try_num <= num; ++try_num) {
        scanf("%d %d %d", &col, &row, &mine);
        emp = col * row - mine;
        memset(mat, 0, sizeof(mat));

        printf("Case #%d:\n", try_num); // 例外が多いな・・・
        if(col == 1) {
            putchar('c');
            for(i = 0; i < emp - 1; ++i) {
                putchar('.');
            }
            for(i = 0; i < mine; ++i) {
                putchar('*');
            }
            putchar('\n');
        }
        else if(row == 1) {
            puts("c");
            for(i = 0; i < emp - 1; ++i) {
                puts(".");
            }
            for(i = 0; i < mine; ++i) {
                puts("*");
            }
        }
        else if(emp == 2 || emp == 3 || emp == 5 || emp == 7) {
            printf("Impossible\n");
        }
        else if(emp == 1) {
            mat[0][0] = 1;
            print_matrix();
        }
        else if(col == 2) {
            if(emp % 2 == 0) {
                emp /= 2;
                putchar('c');
                for(i = 1; i < emp; ++i) {
                    putchar('.');
                }
                for(i = 0; i < row-emp; ++i) {
                    putchar('*');
                }
                putchar('\n');
                for(i = 0; i < emp; ++i) {
                    putchar('.');
                }
                for(i = 0; i < row-emp; ++i) {
                    putchar('*');
                }
                putchar('\n');
            }
            else {
                printf("Impossible\n");
            }
        }
        else if(row == 2) {
            if(emp % 2 == 0) {
                emp /= 2;
                puts("c.");
                for(i = 1; i < emp; ++i) {
                    puts("..");
                }
                for(i = 0; i < col-emp; ++i) {
                    puts("**");
                }
            }
            else {
                printf("Impossible\n");
            }
        }
        else if(emp == 4) {
            mat[0][0] = 1;
            mat[0][1] = mat[1][0] = mat[1][1] = 2;
            print_matrix();
        }
        else if(emp == 6) {
            mat[0][0] = 1;
            mat[0][1] = mat[1][0] = mat[1][1] = mat[2][0] = mat[2][1] = 2;
            print_matrix();
        }
        else if(emp == 8) {
            mat[0][0] = 1;
            mat[0][1] = mat[0][2] = mat[1][0] = mat[1][1] = mat[1][2] = mat[2][0] = mat[2][1] = 2;
            print_matrix();
        }
        else {
            make_matrix();
            mat[0][0] = 1;
            print_matrix();
        }
    }

    return 0;
}
