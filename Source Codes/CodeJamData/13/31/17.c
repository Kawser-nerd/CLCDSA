//
//  main.c
//  Codejam 2013, Round 1C, Problem A, Small
//

#include <iso646.h>
#include <stdio.h>
#include <stdlib.h>

#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <math.h>
#include <string.h>

uintmax_t read_uint_from_file( FILE * this_file )
{
    uintmax_t zz;
    fscanf( this_file , "%ju" , &zz ) ;
    return zz;
}

intmax_t read_int_from_file( FILE * this_file )
{
    intmax_t zz;
    fscanf( this_file , "%ju" , &zz ) ;
    return zz;
}

uintmax_t read_uint( )
{
    return read_uint_from_file( stdin ) ;
}

intmax_t read_int( )
{
    return read_uint_from_file( stdin ) ;
}

char read_char_from_file( FILE * this_file ) 
{
    char zz[2] ; 
    fscanf( this_file , "%1s" , zz ) ;
    return zz[0] ;
}

bool isVowel( char cc ) {
    if ( cc == 'a' or cc == 'e' or cc == 'i' or cc == 'o' or cc == 'u' ) {
        return true ;
    }
    return false ;
}

int main (int argc, const char * argv[])
{
//    const int MAX = 101 ;
    char str[1000001] ;
    for ( uintmax_t ii = 1 , TT = read_uint( ) ; ii <= TT ; ++ii ) {
        fscanf( stdin , "%s" , str ) ;
        int len = strlen( str ) ;
        intmax_t nn = read_int( ) ;
        uintmax_t tally = (len-nn+1) * (len-nn+1 + 1) / 2 ; // number of possibilities, 1+2+3+...+(len-nn+1)
        uintmax_t conseq = 0 ;
        uintmax_t count = 0 ;
        for ( int index = 0 ; index < len ; index++ ) {
            count += 1 ;
            if ( isVowel( str[index] ) ) {
                conseq = 0 ;
            } else {
                conseq += 1 ;
            }
            if ( conseq == nn ) {
                if (count > nn) {
                    tally -= (count-nn)*(count-nn + 1) / 2 ; // exclude this many possibilities, 1+2+3+...+(count-nn)
                }
                count = nn-1 ;
                conseq -= 1 ;
            }   
        } 
        if (count >= nn) {
            tally -= (count-nn+1)*(count-nn+1 + 1) / 2 ; // exclude this many possibilities, 1+2+3+...+(count-nn+1)
        }

        fprintf( stdout , "Case #%ju: %ju\n" , ii , tally ) ; fflush( stdout ) ;
    } 
    return EXIT_SUCCESS ;
} 
