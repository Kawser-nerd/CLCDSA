#include <stdio.h>
int main(void){int i,j,n,model=0,x[10],y[10];scanf("%d",&n);for(i=1;i<10;i++)for(j=1;j<10;j++)model+=i*j;n=model-n;j=0;for(i=1;i<10;i++)if(n%i==0&&n/i<10){x[j]=i;y[j]=n/i;j++;}for(i=0;i<j;i++)printf("%d x %d\n",x[i],y[i]);return 0;} ./Main.c: In function ‘main’:
./Main.c:2:46: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 int main(void){int i,j,n,model=0,x[10],y[10];scanf("%d",&n);for(i=1;i<10;i++)for(j=1;j<10;j++)model+=i*j;n=model-n;j=0;for(i=1;i<10;i++)if(n%i==0&&n/i<10){x[j]=i;y[j]=n/i;j++;}for(i=0;i<j;i++)printf("%d x %d\n",x[i],y[i]);return 0;}
                                              ^