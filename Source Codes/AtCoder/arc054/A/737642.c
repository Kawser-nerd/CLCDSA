#include<stdio.h>

int main(){
  double L,X,Y,S,D;
  long double rel1,rel2;

  scanf("%lf %lf %lf %lf %lf",&L,&X,&Y,&S,&D);

  if(S>D){
  rel1=(L-S+D)/(X+Y);
  if(X!=Y)rel2=(S-D)/(Y-X);
  else rel2=-1;
  }else if(S<D){
    rel1=(D-S)/(X+Y);
    if(X!=Y)rel2=(L-D+S)/(Y-X);
    else rel2=-1;
  }else{
    printf("0.0\n");
  }

  if(rel1>=rel2&&rel2>0){
    printf("%10.10Lf\n",rel2);
  }else if(rel2>rel1&&rel1>0){
    printf("%10.10Lf\n",rel1);
  }else if(rel2<0){
    printf("%10.10Lf\n",rel1);
  }else if(rel1<0){
    printf("%10.10Lf\n",rel2);
  }

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lf %lf %lf %lf %lf",&L,&X,&Y,&S,&D);
   ^