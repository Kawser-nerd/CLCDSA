#include <stdio.h>
#include <stdlib.h>

int compare( const void* a, const void* b)
{
     unsigned long int_a = * ( (unsigned long*) a );
     unsigned long int_b = * ( (unsigned long*) b );

     if ( int_a == int_b ) return 0;
     else if ( int_a < int_b ) return -1;
     else return 1;
}


int main()
{
    unsigned long n, c, k, i, b, s, cs;
    unsigned long *t;
    scanf("%lu %lu %lu", &n, &c, &k);
    t = malloc( n * sizeof( long ) );
    for( i = 0; i < n; i ++)
    {
        scanf( "%lu", &t[i] );
    }
    qsort( t, n, sizeof(unsigned long), compare );
    
    i = 0;
    b = 0;
    while( i < n)
    {
        b++;
        s = t[i];
        cs = i;
        do
        {
            i++;
        }
        while( i < n 
               && i - cs < c 
               && t[i] - s <= k );
    }
    
    printf( "%lu", b);
    free( t );
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:19:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lu %lu %lu", &n, &c, &k);
     ^
./Main.c:23:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf( "%lu", &t[i] );
         ^