#include <stdio.h>

int h,w,x,y,z;
char masu[100][100];

int main(){



    scanf ( " %d %d " , &h , &w );

    for ( x = 1 ; x < h ; x++ ) scanf ( " %s " , &masu[x] );


    for ( x = 1 ; x <= h ; x++ ) {
        for ( y = 1 ; y <= w ; y++ ) {
            if ( masu[x][y] != '#' ) masu[x][y] = 0;
        }
    }


    for ( x = 1 ; x <= h ; x++ ) {
        for ( y = 1 ; y <= w ; y++ ) {
            if ( masu[x][y] == '#' ){
                if( masu[x-1][y] == 0 && masu[x][y-1] == 0 && masu[x+1][y] == 0 && masu[x][y+1] == 0 ) {
                    printf("No\n");
                    return 0;
                }
            }
        }
    }


    printf("Yes\n");



    return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:41: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[100]’ [-Wformat=]
     for ( x = 1 ; x < h ; x++ ) scanf ( " %s " , &masu[x] );
                                         ^
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf ( " %d %d " , &h , &w );
     ^
./Main.c:12:33: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     for ( x = 1 ; x < h ; x++ ) scanf ( " %s " , &masu[x] );
                                 ^