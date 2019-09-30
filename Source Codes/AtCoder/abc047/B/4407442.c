#include<stdio.h>
int main(){
  int w,h,n,x,y,a,i,j,s[111]={},t[111]={};
  scanf("%d%d%d",&w,&h,&n);
  for(i=0;i<n;i++){
    scanf("%d%d%d",&x,&y,&a);
    switch (a) {
      case 1:
        for(j=1;j<=x;j++)s[j]=1;
        break;
      case 2: 
        for(j=x+1;j<=w;j++)s[j]=1;
        break;
      case 3:
        for(j=1;j<=y;j++)t[j]=1;
        break;
      case 4:
        for(j=y+1;j<=h;j++)t[j]=1;
        break;
    }
  }
  x=0;
  y=0;
  for(i=1;i<=w;i++){
    if(s[i]==0){
      x++;
    }
  }
  for(i=1;i<=h;i++){
    if(t[i]==0){
      y++;
    }
  }
  printf("%d",x*y);
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&w,&h,&n);
   ^
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&x,&y,&a);
     ^