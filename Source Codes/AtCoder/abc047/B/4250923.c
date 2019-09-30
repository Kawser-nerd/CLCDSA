#include <stdio.h>
int main(void){
  int w,h,n,i;
  int x[100],y[100],a[100];
  scanf("%d%d%d",&w,&h,&n);
  int w1=0,w2=w,h1=0,h2=h;
  for(i=0;i<n;i++){
    scanf("%d %d %d",&x[i],&y[i],&a[i]);
  }
  for(i=0;i<n;i++){
    if(a[i]==1){
      if(w1<=x[i]) w1=x[i];
    }
    else if(a[i]==2){
      if(w2>=x[i]) w2=x[i];
    }
    else if(a[i]==3){
      if(h1<=y[i]) h1=y[i];
    }
    else if(a[i]==4){
      if(h2>=y[i]) h2=y[i];
    }
  }
  int sum=(h2-h1)*(w2-w1);
  if(w1>=w2||h1>=h2) sum=0;
  printf("%d",sum);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&w,&h,&n);
   ^
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d",&x[i],&y[i],&a[i]);
     ^