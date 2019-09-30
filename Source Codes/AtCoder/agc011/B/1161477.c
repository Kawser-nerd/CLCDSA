#include <stdio.h>
#include <stdlib.h>

int descending( const void* a, const void* b)
{
     unsigned long int_a = * ( (unsigned long*) a );
     unsigned long int_b = * ( (unsigned long*) b );

     if ( int_a == int_b ) return 0;
     else if ( int_a < int_b ) return 1;
     else return -1;
}

unsigned long sum( unsigned long *ul, unsigned long size )
{
    unsigned long val = 0;
    for( unsigned long i = 0; i < size; i ++ )
    {
        val += ul[i];
    }
    return val;
}

int main()
{
    unsigned long n, i, color;
    unsigned long *c;
    scanf("%lu", &n);
    c = malloc( n * sizeof(unsigned long));
    for( i = 0; i < n; i++ )
    {
        scanf( "%lu", &c[i] );
    }

    qsort( c, n, sizeof(unsigned long), descending );
    
    i = 0;
    color = 0;
    while( i < n )
    {
        if( i == 0 
            || c[i]*2 >= c[i-1] )
        {
            color ++;
        }
        else
        {
            if( sum( &c[i], n-i )*2 >= c[i-1] ) 
            {
                color ++;
            }
            else
            {
                break;
            }
        }
        i++;
    }

    printf( "%lu ", color );
   
} ./Main.c: In function ‘main’:
./Main.c:28:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lu", &n);
     ^
./Main.c:32:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf( "%lu", &c[i] );
         ^