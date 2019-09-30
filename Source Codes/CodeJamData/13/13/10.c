//
//  main.c
//  Codejam 2013 Round 1A Problem A
//

#include <iso646.h>
#include <stdio.h>
#include <stdlib.h>

#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <math.h>

uintmax_t read_uint_from_file( FILE * this_file )
{
    uintmax_t zz;
    fscanf( this_file , "%ju" , &zz ) ;
    return zz;
}

uintmax_t read_uint( )
{
    return read_uint_from_file( stdin ) ;
}

int main (int argc, const char * argv[])
{
    // process input 
    uintmax_t TT = read_uint( ) ;
    fprintf( stdout , "Case #%ju:\n" , TT ) ;

    uintmax_t RR = read_uint( ) ;
    uintmax_t NN = read_uint( ) ;
    uintmax_t MM = read_uint( ) ;
    uintmax_t KK = read_uint( ) ;

    for ( uintmax_t ii = 1 ; ii <= RR ; ++ii ) {
        uintmax_t max = 0 ;
        for ( uintmax_t jj = 1 ; jj <= KK ; ++jj ) {
            uintmax_t new = read_uint( ) ;
            if (new > max) max = new ;
        }
        switch (max) {
        case 125:
            fprintf( stdout , "555\n" ) ;
            break ;
        case 100:
            fprintf( stdout , "554\n" ) ;
            break ;

        case 75:
            fprintf( stdout , "553\n" ) ;
            break ;

        case 50:
            fprintf( stdout , "552\n" ) ;
            break ;

        case 80:
            fprintf( stdout , "544\n" ) ;
            break ;

        case 60:
            fprintf( stdout , "543\n" ) ;
            break ;

        case 40:
            fprintf( stdout , "542\n" ) ;
            break ;

        case 45:
            fprintf( stdout , "533\n" ) ;
            break ;

        case 30:
            fprintf( stdout , "532\n" ) ;
            break ;

        case 20:
            fprintf( stdout , "522\n" ) ;
            break ;

        case 64:
            fprintf( stdout , "444\n" ) ;
            break ;

        case 48:
            fprintf( stdout , "443\n" ) ;
            break ;

        case 32:
            fprintf( stdout , "442\n" ) ;
            break ;

        case 36:
            fprintf( stdout , "433\n" ) ;
            break ;

        case 24:
            fprintf( stdout , "432\n" ) ;
            break ;

        case 16:
            fprintf( stdout , "422\n" ) ;
            break ;

        case 27:
            fprintf( stdout , "333\n" ) ;
            break ;

        case 18:
            fprintf( stdout , "332\n" ) ;
            break ;

        case 12:
            fprintf( stdout , "322\n" ) ;
            break ;

        default:
            fprintf( stdout, "222\n" ) ;



         }
    }
}
