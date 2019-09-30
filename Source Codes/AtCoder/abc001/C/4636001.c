#include <stdio.h>

int main(void){
  double deg,dis;
  scanf("%lf%lf",&deg,&dis);

  char direct[16][4] = {"N","NNE","NE","ENE","E","ESE","SE","SSE","S","SSW","SW","WSW","W","WNW","NW","NNW"};

  int direct_num = 0;
  int cnt = 0;
  for(double i = 112.5;i < 3600;i += 225,cnt++){
    if(deg <= i){
      direct_num = cnt;
      break;
    }
  }

  int wind_power;

  if(dis < 0.25*60){
    wind_power = 0;
  }else if(dis < 1.55*60){
    wind_power = 1;
  }else if(dis < 3.35*60){
    wind_power = 2;
  }else if(dis < 5.45*60){
    wind_power = 3;
  }else if(dis < 7.95*60){
    wind_power = 4;
  }else if(dis < 10.75*60){
    wind_power = 5;
  }else if(dis < 13.85*60){
    wind_power = 6;
  }else if(dis < 17.15*60){
    wind_power = 7;
  }else if(dis < 20.75*60){
    wind_power = 8;
  }else if(dis < 24.45*60){
    wind_power = 9;
  }else if(dis < 28.45*60){
    wind_power = 10;
  }else if(dis < 32.65*60){
    wind_power = 11;
  }else{
    wind_power = 12;
  }

  if(wind_power == 0){
    printf("C 0\n");
  }else{
    printf("%s %d\n",direct[direct_num],wind_power);
  }

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lf%lf",&deg,&dis);
   ^