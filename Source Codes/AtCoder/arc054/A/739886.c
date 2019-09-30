#include<stdio.h>

double min(double x, double y){
  return x > y ? y : x;
}

int main(){
  double L,X,Y,S,D;
  double anser = 0;

  scanf("%lf %lf %lf %lf %lf",&L,&X,&Y,&S,&D);

  if(D >= S){
    if(Y > X){anser = min((D-S)/(Y+X),((L+S)-D)/(Y-X));}
    else {anser = (D-S)/(Y+X);}
  }
  else {
    if(Y > X) {anser = min(((L+D)-S)/(Y+X),(S-D)/(Y-X));}
    else {anser = ((L+D)-S)/(Y+X);}
  }
  
  printf("%f\n",anser);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lf %lf %lf %lf %lf",&L,&X,&Y,&S,&D);
   ^