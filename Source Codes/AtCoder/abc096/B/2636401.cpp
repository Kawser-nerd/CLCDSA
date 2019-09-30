#include <iostream>

int main(){

  int i,a,b,c,k,x[3];
  scanf("%d %d %d %d",&a,&b,&c,&k);
  if(a>b&&a>c){
    x[0]=a; x[1]=b; x[2]=c;
  }
  else if(b>c){
    x[0]=b; x[1]=a; x[2]=c;
  }
  else{
    x[0]=c; x[1]=a; x[2]=b;
  }
  for(i=0;i<k;i++)x[0]*=2;
  printf("%d",x[0]+x[1]+x[2]);
}