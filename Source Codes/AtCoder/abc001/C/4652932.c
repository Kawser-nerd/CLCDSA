#include <stdio.h>
int main(){
  int deg,dis,i,j;
  char houi[49]="N  NNENE ENEE  ESESE SSES  SSWSW WSWW  WNWNW NNW";
  int soku[12]={2,15,33,54,79,107,138,171,207,244,284,326};
  scanf("%d%d",&deg,&dis);
  deg*=2;
  if (dis<15) printf("C");
  else{
    i=((deg+225)/450)%16;
    if (i%4==0) printf("%c",houi[3*i]);
    else if (i%2) printf("%c%c%c",houi[3*i],houi[3*i+1],houi[3*i+2]);
    else printf("%c%c",houi[3*i],houi[3*i+1]);
  }
  for (j=0;j<12;){
    if (dis<soku[j]*6+3) break;
    j++;
  }
  printf(" %d\n",j);
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&deg,&dis);
   ^