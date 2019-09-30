#include<stdio.h>
long long int n , a[1000010] ;
int main()
{
    int i ;
    scanf("%lld",&n) ;
    for( i = 1 ; i <= n ; i ++ )
    {
        scanf("%lld",&a[i]) ;
    }
    if( a[n] != 2 )
    {
        puts("-1") ;
        return 0 ;
    }
    long long int low = 2 , high = 3 ;
    for( i = n - 1 ; i >= 1 ; i -- )
    {
        long long int x;
        x = ( low / a[i] ) * a[i] ;
        if( low % a[i] )
            x += a[i] ;
        long long int x1;
        x1 = ( high / a[i] ) * a[i] ;

        if( x > high || x1 < low )
        {
            puts("-1") ;
            return 0 ;
        }
        low = x , high = x1 + a[i] - 1 ;
    }
    printf("%lld %lld\n",low,high) ;
    return 0 ;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld",&n) ;
     ^
./Main.c:9:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%lld",&a[i]) ;
         ^