#include<stdio.h>

int
main()
{
  float T,X;
  scanf("%d %d",&T,&X);
  float time_A = T/X;
  printf("%f\n",time_A);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:9: warning: format ‘%d’ expects argument of type ‘int *’, but argument 2 has type ‘float *’ [-Wformat=]
   scanf("%d %d",&T,&X);
         ^
./Main.c:7:9: warning: format ‘%d’ expects argument of type ‘int *’, but argument 3 has type ‘float *’ [-Wformat=]
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&T,&X);
   ^