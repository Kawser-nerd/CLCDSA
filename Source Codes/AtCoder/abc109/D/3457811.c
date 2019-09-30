#include<stdio.h>
     
 int main(){
 int h,w;
 scanf("%d%d",&h,&w);
 int qes[h][w],j,i,ans[h*w][4],cnt=0; 
 for(i=0;i<h;i++){
  for(j=0;j<w;j++){
   scanf("%d",&qes[i][j]);
  }
 }
 for(i=h-1;i>0;i--){
  for(j=0;j<w;j++){
   if(qes[i][j]!=0){
    if(qes[i][j]%2==1){
     qes[i][j] -= 1;
     qes[i-1][j]+=1;
     ans[cnt] [0] =i+1;
     ans[cnt] [1] =j+1;
     ans[cnt] [2] =i;
     ans[cnt] [3] =j+1;
     cnt++;
    }
   }
  }
 }
 for(i=w-1;i>0;i--){
  if(qes[0][i]%2==1){
   qes[0][i]-= 1;
   qes[0][i-1]+=1;
   ans[cnt] [0] =1;
   ans[cnt] [1] =i+1;
   ans[cnt] [2] =1;
   ans[cnt] [3] =i;
   cnt++;
  }
 }
 printf("%d\n",cnt);
 for(i=0;i<cnt;i++){
  printf("%d %d %d %d\n",ans[i][0],ans[i][1],ans[i][2],ans[i][3]);
 } 
 return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&h,&w);
  ^
./Main.c:9:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d",&qes[i][j]);
    ^