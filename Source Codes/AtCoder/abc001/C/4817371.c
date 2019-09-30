#include <stdio.h>

int main(){
  int deg,dis;
  scanf("%d %d",&deg,&dis);
  char dir[4];
  dir[3] = '\0';
  int theta = 1125;
  int num,mod;
  deg *= 10;
  num = deg / theta;
  if(num < 5 || num >= 27) dir[0] = 'N';
  else if(num >= 5 && num < 11) dir[0] = 'E';
  else if(num >= 11 && num < 21) dir[0] = 'S';
  else if(num >= 21 && num < 27) dir[0] = 'W';
  mod = num % 8;
  if(mod == 0 || mod == 7) dir[1] = '\0';
  mod = num % 24;
  if(mod == 1 || mod == 2 || mod == 5 || mod == 6) dir[1] = 'N';
  mod = num % 4;
  if((mod == 1 || mod == 2) && 8 < num && num < 23) dir[1] = 'S';
  if(num == 3 || num == 4 || num == 11 || num == 12) dir[1] = 'E';
  if(num == 19 || num == 20 || num == 27 || num == 28) dir[1] = 'W';
  num = (num + 1) / 2;
  if(num % 4 == 2) dir[2] = '\0';
  if(num % 2 == 1 && num < 8) dir[2] = 'E';
  if(num % 2 == 1 && num > 8) dir[2] = 'W';
  int w;
  dis = (int)((float)dis * 10.0 / 60.0 + 0.5);
  if(dis <= 2){
    dir[0] = 'C';
    dir[1] = '\0';
    w = 0;
  }else if(dis <= 15) w = 1;
  else if(dis <= 33) w = 2;
  else if(dis <= 54) w = 3;
  else if(dis <= 79) w = 4;
  else if(dis <= 107) w = 5;
  else if(dis <= 138) w = 6;
  else if(dis <= 171) w = 7;
  else if(dis <= 207) w = 8;
  else if(dis <= 244) w = 9;
  else if(dis <= 284) w = 10;
  else if(dis <= 326) w = 11;
  else w = 12;
  
  printf("%s %d\n",dir,w);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&deg,&dis);
   ^