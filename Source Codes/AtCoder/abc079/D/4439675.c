#include<stdio.h>
#include<stdlib.h>

#define MIN(a,b) ((a)<(b)?(a):(b))

void run(void){
  int h,w;
  scanf("%d%d",&h,&w);
  int c[100];
  const int f=10;
  int i,j,k;
  for(i=0;i<f*f;i++) scanf("%d",c+i);
  for(k=0;k<f;k++){
    for(i=0;i<f;i++){
      for(j=0;j<f;j++){
	c[i*f+j]=MIN(c[i*f+j],c[i*f+k]+c[k*f+j]);
      }
    }
  }
  int ans=0;
  for(i=0;i<h*w;i++){
    int a;
    scanf("%d",&a);
    if(a<0) continue;
    ans+=c[a*f+1];
  }
  printf("%d\n",ans);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&h,&w);
   ^
./Main.c:12:22: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<f*f;i++) scanf("%d",c+i);
                      ^
./Main.c:23:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a);
     ^