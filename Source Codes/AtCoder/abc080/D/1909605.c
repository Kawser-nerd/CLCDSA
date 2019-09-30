#include<stdio.h>
  int n,m,a,b,i,j,s=0,max=0,d[50][100010]={};
int main(){
  scanf("%d %d",&n,&m);
  while(n--){
    scanf("%d %d %d",&a,&i,&j);
    d[j-1][a-1]++;
    d[j-1][i]--;
  }
  for(i=0;i<100005;i++){
    for(j=s=0;j<m;j++){
      d[j][i+1]+=d[j][i];
      s+=d[j][i]?1:0;
    }
    if(max<s)max=s;
  }
  printf("%d\n",max);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&n,&m);
   ^
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d",&a,&i,&j);
     ^