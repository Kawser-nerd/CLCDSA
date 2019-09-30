#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
  double deg,dis,diss;
  scanf("%lf %lf",&deg,&dis);
  diss=round(dis/6.0)/10;
  if(diss<=0.2){
  	printf("C 0\n");
  }else{
    if(112.5<=deg && deg<337.5)printf("NNE ");
    else if(337.5<=deg && deg<562.5)printf("NE ");
    else if(562.5<=deg && deg<787.5)printf("ENE ");
    else if(787.5<=deg && deg<1012.5)printf("E ");
    else if(1012.5<=deg && deg<1237.5)printf("ESE ");
    else if(1237.5<=deg && deg<1462.5)printf("SE ");
    else if(1462.5<=deg && deg<1687.5)printf("SSE ");
    else if(1687.5<=deg && deg<1912.5)printf("S ");
    else if(1912.5<=deg && deg<2137.5)printf("SSW ");
    else if(2137.5<=deg && deg<2362.5)printf("SW ");
    else if(2362.5<=deg && deg<2587.5)printf("WSW ");
    else if(2587.5<=deg && deg<2812.5)printf("W ");
    else if(2812.5<=deg && deg<3037.5)printf("WNW ");
    else if(3037.5<=deg && deg<3262.5)printf("NW ");
    else if(3262.5<=deg && deg<3487.5)printf("NNW ");
    else printf("N ");
    if(diss<=0.2)printf("0\n");
    else if(diss<=1.5)printf("1\n");
    else if(diss<=3.3)printf("2\n");
    else if(diss<=5.4)printf("3\n");
    else if(diss<=7.9)printf("4\n");
    else if(diss<=10.7)printf("5\n");
    else if(diss<=13.8)printf("6\n");
    else if(diss<=17.1)printf("7\n");
    else if(diss<=20.7)printf("8\n");
    else if(diss<=24.4)printf("9\n");
    else if(diss<=28.4)printf("10\n");
    else if(diss<=32.6)printf("11\n");
    else if(diss>=32.7)printf("12\n");
  }
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lf %lf",&deg,&dis);
   ^