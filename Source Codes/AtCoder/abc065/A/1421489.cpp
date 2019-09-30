#include <stdio.h>

int main ( ) {
    int x , a , b ;

    while ( ~scanf ( "%d%d%d" , &x , &a , &b ) ) {

        if ( a >= b ) {
            printf ( "delicious\n" ) ;
        }
        if ( b - a > x ) {
            printf ( "dangerous\n" ) ;
        }
        if ( b > a && b -a <= x ) {
            printf ( "safe\n") ;
        }
    }

    return 0 ;
}