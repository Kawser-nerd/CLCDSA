#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int equals(int a, int b) {
    if(a == '.' || b == '.') return 0;
    if(a == 'T' || b == 'T') return 1;
    else return a==b;
}


int check(int board[4][4]) {
    int i,j;
    for(i = 0; i < 4; i ++ ) {
        if(equals(board[i][0], board[i][1]) && equals(board[i][1], board[i][2]) && equals(board[i][2], board[i][3]))
            if(board[i][0] != 'T') return board[i][0]; else return board[i][i];
    }
    for(i = 0; i< 4; i ++ ) {
        if(equals(board[0][i], board[1][i]) && equals(board[1][i], board[2][i]) && equals(board[2][i], board[3][i]))
            if(board[0][i] != 'T') return board[0][i]; else return board[1][i];
    }

    if(equals(board[0][0], board[1][1]) && equals(board[1][1], board[2][2]) && equals(board[2][2], board[3][3]))
        if(board[0][0] != 'T') return board[0][0]; else return board[1][1];


    if(equals(board[0][3], board[1][2]) && equals(board[1][2], board[2][1]) && equals(board[2][1], board[3][0]))
        if(board[0][3] != 'T') return board[0][3]; else return board[1][2];


    return 0;
}


int check_draw(int board[4][4]) {
    int i, j;
    for(i = 0 ; i< 4; i ++ ) {
        for(j = 0 ; j < 4; j ++ ) {
            if(board[i][j] == '.')
                return 0;
        }
    }
    return 1;
}

int main() {
    char* filename = "test.in";
    int numCase =0;
    
    FILE* fin = fopen(filename, "r");
    fscanf(fin, "%d\n", &numCase);

    int i,j,k;
    int board[4][4] = {0};
    for(i = 0; i < numCase; i ++ ) {

        for(j = 0 ; j < 4; j ++ ) {
            for(k = 0; k < 4; k ++ ) {
                fscanf(fin, "%c", &board[j][k]);
            }
            fscanf(fin, "\n");
        }
        fscanf(fin, "\n");
        
       /* 
        for(j = 0 ; j < 4; j ++ ) {
            for(k = 0; k < 4; k ++ ) {
                printf("%c", board[j][k]);
            }
            printf("\n");
        }*/
        

        int result = check(board);
            
        if(result == 0) {
            result = check_draw(board); 
            if(result == 1) {
                printf("Case #%d: Draw\n", i + 1);
            }
            else {
                printf("Case #%d: Game has not completed\n", i + 1);
            }
        }
        else {
            printf("Case #%d: %c won\n",  i + 1, result);
        }
        
    }

}
