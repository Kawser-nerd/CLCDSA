#include <stdio.h>
int main(){
  int n,s,e,flag=0,tl[289]={0};/*(i/12)*100+(i%12)*5->24h??*/
  scanf("%d",&n);
  for (int i=0;i<n;i++){
    scanf("%04d-%04d",&s,&e);
    tl[(s/100)*12+((s%100)/5)]++;
    tl[(e/100)*12+(((e%100)+4)/5)]--;
  }
  for (int i=0;i<289;i++){
    if (!flag && tl[i]>0) printf("%04d-",(i/12)*100+(i%12)*5);
    flag+=tl[i];
    if (!flag && tl[i]<0) printf("%04d\n",(i/12)*100+(i%12)*5);
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%04d-%04d",&s,&e);
     ^