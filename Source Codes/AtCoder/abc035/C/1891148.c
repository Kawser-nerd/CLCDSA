#include<stdio.h>

int main(void){
  int a[1000000];
  int n,m,i,x,y;

  scanf("%d %d",&n,&m);
  for(i=0;i<200001;i++) a[i]=0;

  for(i=0;i<m;i++){
    scanf("%d %d",&x,&y);
    a[x]++; a[y+1]--;
  }

  for(i=2;i<=n;i++)
    a[i]+=a[i-1];

  for(i=1;i<=n;i++)
    printf("%d",a[i]%2 ? 1 :0);

  printf("\n");

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&n,&m);
   ^
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&x,&y);
     ^