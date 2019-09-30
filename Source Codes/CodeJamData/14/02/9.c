#include<stdio.h>

int main(void){
  int t,i,p;
  double c,x,f,time,tmp,sum;

  scanf("%d",&t);
  for(i=1;i<=t;i++){
    scanf("%lf%lf%lf",&c,&f,&x);
    tmp=x/2;
    p=sum=0;
    do{
      time=tmp;
      p++;
      sum+=c/(2+(p-1)*f);
      tmp=sum+x/(2+p*f);
    }while(tmp<time);

    printf("Case #%d: %f\n",i,time);
  }
  return 0;
}
