#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>

double findStrategy(double c, double f, double x)
{
  double timeForFarm=0.0;
  double timeAfterFarm;
  double timeWithFarm=0.0;
  double timeWithoutFarm=1.0;
  double timeRes=0.;
  double currentRate=2.-f;
  while (timeWithoutFarm > timeWithFarm) {
    timeRes+=timeForFarm;
    currentRate+=f;
    timeForFarm=(c/currentRate);
    timeAfterFarm=(x/(currentRate+f));
    timeWithFarm=timeForFarm+timeAfterFarm;
    timeWithoutFarm=(x/currentRate);
    /* fprintf(stderr,"Rate: %lf tWith: %lf=%lf+%lf tWithout: %lf\n",currentRate,timeWithFarm,timeForFarm,timeAfterFarm,timeWithoutFarm); */
    }
  timeRes+=timeWithoutFarm;
  /* fprintf(stderr,"Returning: %lf\n",timeRes); */
  return timeRes;
}
/*  */
void printRes(int c, double t){
  printf("Case #%d: %.7lf\n", c+1,t);
}

int main()
{
  int i;
  int T;
  scanf("%d",&T);
  double c,f,x,t;
  for (i = 0; i < T; i++) {
    scanf("%lf %lf %lf",&c,&f,&x);
    t=findStrategy(c,f,x);
    printRes(i,t);
  }
  return 0;
}
