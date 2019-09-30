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
    // Note: (a^2 - b^2) = (a+b)(a-b)
    // Also: a = b+1
    // Thus: ((b+1)^2 - b^2) = (b+1+b)(b+1-b) = 2b+1
    // Thus: paint used for black ring with inner diameter b is 2b+1

    // Next consider: inner black rings always incrememt by +2,
    //        thus the next ring is 2(r+2)+1, 
    //        the one after that 2(r+4)+1, etc.
    // is there an optimisation to be found with this knowledge.
    // (Note that I've now replace b with r, as per the problem text)

    // Let's just try to brute force with the knowledge I've now gained.

    // Brute force is too slow

    // The formula seems to be as count * first + 4 * (0 + 1 + 2 + ... + (count-1))
    // Where first is the amount of paint used for the first ring, i.e. 2r+1
    // The summation is a triangle number
    // The nth triangle number equals (n)(n+1)/2
    // Thus our summation is (count-1)(count)/2

    // Thus it is equivalent to finding the roots of the quadratic
    // 2c^2 + (f-2)c - t = 0

    // The quadratic formula is (-b+sqrt(b^2-4ac))/2a
    // (Note b, i.e. f-2, is always positive so we only want the larger of the two possible roots)

    // 

//    const uintmax_t MAX = UINTMAX_C( 2000000000000000000 ) ;
//    fprintf( stdout , "%ju" , number ) ;
    
    // process input 
    for ( uintmax_t ii = 1 , TT = read_uint( ) ; ii <= TT ; ++ii ) {
        uintmax_t rr = read_uint( ) ;
        uintmax_t tt = read_uint( ) ;
        uintmax_t first_ring_paint_used = 2 * rr + 1 ;
        long double a = 2.0L ;
        long double b = ((long double) (first_ring_paint_used - 2)) ;
        long double c = 0.0L - ((long double) tt) ;

//        fprintf( stdout , "%LE\n" , sqrtl((long double) (b*b-4*a*c)) ) ;
//        fprintf( stdout , "%LE\n" , ((long double) (0-b)) + sqrtl((long double) (b*b-4.0L*a*c)) ) ;
//        fprintf( stdout , "%LE\n" , ((long double) (0-b)) ) ;

        long double root = (
               ((long double) (0.0L-b)) 
               + sqrtl((long double) (b*b-4.0L*a*c))
              ) / ((long double) (2.0L*a)) ;
        uintmax_t count = ((uintmax_t) root) ; 

        // This is an approximate value, use integer arithmetic to confirm the correct value
        count += 2 ;
        while ( count * first_ring_paint_used + 2 * (count - 1) * (count) > tt ) {
            --count ;
        }
//        fprintf( stdout , "Case #%ju: %LE\n" , ii , root ) ;
        fprintf( stdout , "Case #%ju: %ju\n" , ii , count ) ;

 

//        uintmax_t count = 0 ;
//        uintmax_t paint_used = 0 ;
//        while ( paint_used <= tt ) {
//            paint_used += 2 * rr + 1 ;
//            rr += 2 ;
//            ++count ;
//        }
//        --count ;
//        fprintf( stdout , "Case #%ju: %ju\n" , ii , count ) ;
    }
    return EXIT_SUCCESS ;
}
