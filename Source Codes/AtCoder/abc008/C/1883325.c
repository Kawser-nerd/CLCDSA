#include<stdio.h>


int main(void){
  int i,j,s=0,d;
  int a[1000];
  double n,m=0,c;

  scanf("%lf",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }

  for(i=0;i<n;i++){
    c=0.0;
    for(j=0;j<n;j++){
      if(i!=j){
        if(a[i]%a[j]==0) c++;
      }
    }
    d = c;
      if(d%2==1) m = m+0.5;
      else m = m+ (c+2.0)/(2.0*c+2.0);
  }


  printf("%lf\n",m);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lf",&n);
   ^
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a[i]);
     ^