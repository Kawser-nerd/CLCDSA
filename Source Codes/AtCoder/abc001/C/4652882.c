#include <stdio.h>
int main(){
  int deg,dis;
  scanf("%d%d",&deg,&dis);
  deg*=2;
  if (dis<15) printf("C ");
  else if (deg>=225 && deg<675) printf("NNE ");
  else if (deg>=675 && deg<1125) printf("NE ");
  else if (deg>=1125 && deg<1575) printf("ENE ");
  else if (deg>=1575 && deg<2025) printf("E ");
  else if (deg>=2025 && deg<2475) printf("ESE ");
  else if (deg>=2475 && deg<2925) printf("SE ");
  else if (deg>=2925 && deg<3375) printf("SSE ");
  else if (deg>=3375 && deg<3825) printf("S ");
  else if (deg>=3825 && deg<4275) printf("SSW ");
  else if (deg>=4275 && deg<4725) printf("SW ");
  else if (deg>=4725 && deg<5175) printf("WSW ");
  else if (deg>=5175 && deg<5625) printf("W ");
  else if (deg>=5625 && deg<6075) printf("WNW ");
  else if (deg>=6075 && deg<6525) printf("NW ");
  else if (deg>=6525 && deg<6975) printf("NNW ");
  else printf("N ");
  if (dis<2*6+3) printf("0\n");
  else if (dis<15*6+3) printf("1\n");
  else if (dis<33*6+3) printf("2\n");
  else if (dis<54*6+3) printf("3\n");
  else if (dis<79*6+3) printf("4\n");
  else if (dis<107*6+3) printf("5\n");
  else if (dis<138*6+3) printf("6\n");
  else if (dis<171*6+3) printf("7\n");
  else if (dis<207*6+3) printf("8\n");
  else if (dis<244*6+3) printf("9\n");
  else if (dis<284*6+3) printf("10\n");
  else if (dis<326*6+3) printf("11\n");
  else printf("12\n");
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&deg,&dis);
   ^