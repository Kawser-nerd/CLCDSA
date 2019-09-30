#include <stdio.h>

int main(void)
{
  int a, b, c;

  scanf("%d/%d/%d",&a,&b,&c);

  if(a<2019){ printf("Heisei\n");
                return 0; }
  else if(a>2019) {printf("TBD\n");
        return 0; }
  if(b<04)  {printf("Heisei\n");
                return 0; }
  else if(b>04) {printf("TBD\n");
        return 0; }
  if(c<=30) {printf("Heisei\n");
                return 0;;}
  else if(c>30) {printf("TBD\n");
        return 0; }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d/%d/%d",&a,&b,&c);
   ^