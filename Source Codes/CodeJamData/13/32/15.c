//
//  main.c
//  Codejam 2013, Round 1C, Problem B, Small
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

int main (int argc, const char * argv[])
{
    for ( uintmax_t ii = 1 , TT = read_uint( ) ; ii <= TT ; ++ii ) {
        fprintf( stdout , "Case #%ju: " , ii ) ;
        intmax_t XX = read_int( ) ;
        bool flag = false ;
        if (XX > 0) {
            fprintf( stdout , "E" ) ;
            XX -= 1 ;
            flag = true ;
        }
        if (XX < 0) {
            fprintf( stdout , "W" ) ;
            XX += 1 ;
            flag = true ;
        }
        while (XX != 0) {
            if (XX > 0) {
                fprintf( stdout , "WE" ) ;
                XX -= 1 ;
            }  
            if (XX < 0) {
                fprintf( stdout, "EW" ) ;
                XX += 1 ;
            } 
        } 
        intmax_t YY = read_int( ) ;
        if ( flag == false ) {
            if (YY > 0) {
                fprintf( stdout , "N" ) ;
                YY -= 1 ;
            }
            if (YY < 0) {
                fprintf( stdout , "S" ) ;
                YY += 1 ;
            }
        }
        while (YY != 0) {
            if (YY > 0) {
                fprintf( stdout , "SN" ) ;
                YY -= 1 ;
            }  
            if (YY < 0) {
                fprintf( stdout, "NS" ) ;
                YY += 1 ;
            } 
        } 
        fprintf( stdout , "\n" ) ;
    }
} 
