#include<stdio.h>
#include<math.h>

int main()
{
    float a,b,avg;
    scanf("%f %f",&a,&b);
    avg=(a+b)/2;
    printf("%.0f",ceil(avg));

} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%f %f",&a,&b);
     ^