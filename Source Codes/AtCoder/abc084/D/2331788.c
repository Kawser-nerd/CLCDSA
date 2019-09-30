#include<stdio.h>

int main(){
  int flag[100001]={},c[100001]={};
  int i,j;
  int n,l,r,cnt=0;
  flag[0]=flag[1]=1;
  for(i=0;i<=100000;i++){
    if(flag[i]==0){
      for(j=2*i;j<=100000;j+=i) flag[j]=1;
    }
  }  
  for(i=3;i<=100000;i+=2) if(flag[i]==0&&flag[(i+1)/2]==0) c[i]++;
  for(i=3;i<=100000;i++) c[i]+=c[i-1];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d %d",&l,&r);
    printf("%d\n",c[r]-c[l-1]);
  }
} ./Main.c: In function ‘main’:
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:17:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&l,&r);
     ^