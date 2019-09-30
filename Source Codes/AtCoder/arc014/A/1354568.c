/*
  ?4????????????????????????
  C???
  ????? qA.c
  ??? 228 ???? 2017/06/15 09:00
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main( void )
{
    int ntako;

    scanf( "%d" , &ntako );

    if ( ( ntako % 2 ) == 0 )
    {
        printf("Blue");
    }
    else
    {
        printf("Red");
    }

    printf("\n");

    return ( 0 );

} ./Main.c: In function ‘main’:
./Main.c:16:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf( "%d" , &ntako );
     ^