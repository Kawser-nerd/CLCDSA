#include <stdio.h>
#include <stdlib.h>
int compare_int(const void *a, const void *b){
  return *(int*)a - *(int*)b;
}
int main(void){
  int c,i,j;
  scanf("%d",&c);
  int d[c];
  for(i=0;i<c;i++){
    scanf("%d",&d[i]);
  }
  for(i=0;i<c;i++){
    while(d[i]%2==0)d[i]=d[i]/2;
  }
  qsort(d,c,sizeof(int),compare_int);
  int ans=1,df=d[0];
  for(i=0;i<c;i++){
    if(df!=d[i]){
      ans++;
      df=d[i];
    }
  }
  printf("%d\n",ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&c);
   ^
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&d[i]);
     ^