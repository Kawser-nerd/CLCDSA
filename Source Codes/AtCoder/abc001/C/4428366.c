#include<stdio.h>
#include<math.h>
#include<string.h>

int main()
{
  int dis;
  double deg;
  scanf("%lf", &deg);
  scanf("%d", &dis);
  
  deg = deg / 10;
  
  char dir[4];
  double i;
  int j;
  j = 0;
  char simbols[][4] = {
    "NNE", "NE", "ENE", "E", "ESE", "SE", "SSE", "S", "SSW", "SW", "WSW", "W", "WNW", "NW", "NNW", "N", "C",
  };
  for(i = 11.25; i < 348.75; i += 22.5)
  {
    if(i <= deg & deg < i + 22.5)
      break;
    j++;
  }
  
  double s = (double)dis / 60;
  s = round(10 * s) / 10;
  int w;
  if(0.0 <= s & s <= 0.2)
    w = 0;
  else if(0.2 <= s & s <= 1.5)
    w = 1;
  else if(1.6 <= s & s <= 3.3)
    w = 2;
  else if(3.4 <= s & s <= 5.4)
    w = 3;
  else if(5.5 <= s & s <= 7.9)
    w = 4;
  else if(8.0 <= s & s <= 10.7)
    w = 5;
  else if(10.8 <= s & s <= 13.8)
    w = 6;
  else if(13.9 <= s & s <= 17.1)
    w = 7;
  else if(17.2 <= s & s <= 20.7)
    w = 8;
  else if(20.8 <= s & s <= 24.4)
    w = 9;
  else if(24.5 <= s & s <= 28.4)
    w = 10;
  else if(28.5 <= s & s <= 32.6)
    w = 11;
  else
    w = 12;
  
  if(w == 0)
    j = 16;
  
  printf("%s %d\n", simbols[j], w);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lf", &deg);
   ^
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &dis);
   ^