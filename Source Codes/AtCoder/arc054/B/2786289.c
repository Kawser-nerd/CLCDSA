#include<stdio.h>
#include<math.h>

double p;

double calct(double py){
  return py+(p/pow(2.0f,py/1.5f));
}

int main(void){
  int i;
  double st,fi,te1,te2;
  scanf("%lf",&p);
  st=0;fi=p;
  for(i=0;i<1234;i++){
    if(st>fi){break;}
    te1=(st*2.0f+fi*1.0f)/3.0f;
    te2=(st*1.0f+fi*2.0f)/3.0f;
    if(calct(te1)>calct(te2)){
      st=te1;
    }
    else{
      fi=te2;
    }
  }
  printf("%.12f",calct((st+fi)/2.0f));
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lf",&p);
   ^