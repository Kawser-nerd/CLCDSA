#include<stdio.h>
int main(){
  int n,i,a,c[100]={};
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a);
    if(a<400)c[0]=1;
    else if(a<800)c[1]=1;
    else if(a<1200)c[2]=1;
    else if(a<1600)c[3]=1;
    else if(a<2000)c[4]=1;
    else if(a<2400)c[5]=1;
    else if(a<2800)c[6]=1;
    else if(a<3200)c[7]=1;
    else c[8]++;
  }
  int ans=0;
  for(i=0;i<8;i++){
    ans+=c[i];
  }
  int min=ans==0?1:ans;
  ans+=c[8];
  printf("%d %d\n",min,ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a);
     ^