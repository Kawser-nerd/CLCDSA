#include <stdio.h>
int main()
{
    int n,m,sum = 0;
    scanf("%d\n",&n);
    for( int i = 0 ; i < n ; i++)
    {
        scanf("%d",&m);
      if( m < 80 )
      {
         sum += (80 - m);
         }
    }
    printf("%d\n",sum);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d\n",&n);
     ^
./Main.c:8:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&m);
         ^