#include<stdio.h>

long ryuka(int i){
  if(i == 0)
    return 2;
  else if(i == 1)
    return 1;
  else
    return ryuka(i-1)+ryuka(i-2);
}

int main(){
  long ans=0;
  int i,j,k;
  scanf("%d",&k);
  long L[k+1];
  for(i=0;i<=k;i++){
    if(i==0){
      L[0] = 2;}
    else if(i==1){
      L[1] = 1;}
    else
      L[i] = L[i-1]+L[i-2];
    ans=L[i];
  }
  
  printf("%ld\n",ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&k);
   ^