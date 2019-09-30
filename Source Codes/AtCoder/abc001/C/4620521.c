#include<stdio.h>

int main(void)
{
  int deg;
  double dis;

  scanf("%d%lf",&deg,&dis);
  if(0<=dis/60&&dis/60<0.25){
    printf("C ");
  }else if(112.5<=deg&&deg<337.5){
    printf("NNE ");
  }else if(337.5<=deg&&deg<562.5){
    printf("NE ");
  }else if(562.5<=deg&&deg<787.5){
    printf("ENE ");
  }else if(787.5<=deg&&deg<1012.5){
    printf("E ");
  }else if(1012.5<=deg&&deg<1237.5){
    printf("ESE ");
  }else if(1237.5<=deg&&deg<1462.5){
    printf("SE ");
  }else if(1462.5<=deg&&deg<1687.5){
    printf("SSE ");
  }else if(1687.5<=deg&&deg<1912.5){
    printf("S ");
  }else if(1912.5<=deg&&deg<2137.5){
    printf("SSW ");
  }else if(2137.5<=deg&&deg<2362.5){
    printf("SW ");
  }else if(2362.5<=deg&&deg<2587.5){
    printf("WSW ");
  }else if(2587.5<=deg&&deg<2812.5){
    printf("W ");
  }else if(2812.5<=deg&&deg<3037.5){
    printf("WNW ");
  }else if(3037.5<=deg&&deg<3262.5){
    printf("NW ");
  }else if(3262.5<=deg&&deg<3487.5){
    printf("NNW ");
  }else{
    printf("N ");
  }

  if(0<=dis/60&&dis/60<0.25){
    printf("0\n");
  }else if(0.25<=dis/60&&dis/60<1.55){
    printf("1\n");
  }else if(1.55<=dis/60&&dis/60<3.35){
    printf("2\n");
  }else if(3.35<=dis/60&&dis/60<5.45){
    printf("3\n");
  }else if(5.45<=dis/60&&dis/60<7.95){
    printf("4\n");
  }else if(7.95<=dis/60&&dis/60<10.75){
    printf("5\n");
  }else if(10.75<=dis/60&&dis/60<13.85){
    printf("6\n");
  }else if(13.85<=dis/60&&dis/60<17.15){
    printf("7\n");
  }else if(17.15<=dis/60&&dis/60<20.75){
    printf("8\n");
  }else if(20.75<=dis/60&&dis/60<24.45){
    printf("9\n");
  }else if(24.45<=dis/60&&dis/60<28.45){
    printf("10\n");
  }else if(28.45<=dis/60&&dis/60<32.65){
    printf("11\n");
  }else{
    printf("12\n");
  }

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%lf",&deg,&dis);
   ^