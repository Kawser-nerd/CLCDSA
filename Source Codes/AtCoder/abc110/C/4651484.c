#include <stdio.h>
#include <stdlib.h>
#define ALP 26
int dcm(const void *a,const void *b){
  return *(int *)b-*(int *)a;
}
int main(){
  int i,ok=1,alp1[ALP],alp2[ALP];
  for(i=0;i<ALP;i++){
    alp1[i]=0;
    alp2[i]=0;
  }
  char s;
  while(scanf("%c",&s)!=EOF&&s!='\n')alp1[s-97]++;
  while(scanf("%c",&s)!=EOF&&s!='\n')alp2[s-97]++;
  qsort(alp1,ALP,sizeof(int),dcm);
  qsort(alp2,ALP,sizeof(int),dcm);
  for(i=0;i<ALP;i++){
    if(alp1[i]==alp2[i])ok*=1;
    else ok*=0;
  }
  if(ok==1)printf("Yes");
  else printf("No");
}