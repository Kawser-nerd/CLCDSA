#include <stdio.h>
#include <string.h>
int main(){
  int W;
  double Deg, Dis, D, M;
  char Dir[4];
  scanf("%lf %lf", &Deg, &Dis);
  
  D=Deg/10.0;
  if (D<11.25) strcpy(Dir, "N");
  else if (D<33.75) strcpy(Dir,"NNE");
  else if (D<56.25) strcpy(Dir,"NE");
  else if (D<78.75) strcpy(Dir,"ENE");
  else if (D<101.25) strcpy(Dir,"E");
  else if (D<123.75) strcpy(Dir,"ESE");
  else if (D<146.25) strcpy(Dir,"SE");
  else if (D<168.75) strcpy(Dir,"SSE");
  else if (D<191.25) strcpy(Dir,"S");
  else if (D<213.75) strcpy(Dir,"SSW");
  else if (D<236.25) strcpy(Dir,"SW");
  else if (D<258.75) strcpy(Dir,"WSW");
  else if (D<281.25) strcpy(Dir,"W");
  else if (D<303.75) strcpy(Dir,"WNW");
  else if (D<326.25) strcpy(Dir,"NW");
  else if (D<348.75) strcpy(Dir,"NNW");
  else strcpy(Dir, "N");

  M = (double)((int)(Dis/6+0.5))/10;
  if (M<=0.2) W=0;
  else if (M<=1.5) W=1;
  else if (M<=3.3) W=2;
  else if (M<=5.4) W=3;
  else if (M<=7.9) W=4;
  else if (M<=10.7) W=5;
  else if (M<=13.8) W=6;
  else if (M<=17.1) W=7;
  else if (M<=20.7) W=8;
  else if (M<=24.4) W=9;
  else if (M<=28.4) W=10;
  else if (M<=32.6) W=11;
  else W=12;

  if (W==0) strcpy(Dir, "C");

  printf("%s %d\n", Dir, W);
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lf %lf", &Deg, &Dis);
   ^