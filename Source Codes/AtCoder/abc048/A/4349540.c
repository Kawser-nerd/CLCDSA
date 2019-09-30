#include <stdio.h>
int main(void)
{
    char s1[101], s2[101], s3[101], a[4];

    scanf("%s%s%s", s1, s2, s3);

    a[0]=s1[0];
    a[1]=s2[0];
    a[2]=s3[0];
    a[3]='\0';

    printf("%s\n", a);
   
  
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s%s%s", s1, s2, s3);
     ^