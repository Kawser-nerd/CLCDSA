#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>

#define MAX(A,B) A>B? A:B
#define MIN(A,B) A<B? A:B


char grid[100][100];

void fill(int r, int c){
    int i,j;
    //Lines
    for ( i = 0 ; i<r; i++){
        char x = -1;
        for ( j = 0 ; j < c; j++){
            if ( grid[i][j] != '?')
                x = grid[i][j];
            if (x != -1)
                grid[i][j] = x;
        }
        x = -1;
        for ( j = c-1 ; j >= 0; j--){
            if ( grid[i][j] != '?')
                x = grid[i][j];
            if (x != -1)
                grid[i][j] = x;
        }
    }
    
    //Colums
    for ( j = 0 ; j<c; j++){
        char x = -1;
        for ( i = 0; i< r; i++){
            if ( grid[i][j] != '?')
                x = grid[i][j];
            if (x != -1)
                grid[i][j] = x;
        }
        x = -1;
        
        for ( i = r - 1; i>= 0 ; i--){
            if ( grid[i][j] != '?')
                x = grid[i][j];
            if (x != -1)
                grid[i][j] = x;
        }
    }
    
}


int main () {
    int t,k;
    
    scanf("%d", &t);
    
    for (k = 0 ; k < t; k ++) {
        int r,c;
        int i,j;
        scanf("%d %d", &r,&c);
        
        for(i = 0; i< r; i++)
            scanf("%s", &grid[i][0]);
        
        fill(r,c);
        
        printf("Case #%d:\n", k+1);
        for(i = 0; i< r; i++){
            for(j = 0; j<c; j++)
                printf("%c", grid[i][j]);
            printf("\n");
        }
    }
    
    
}

