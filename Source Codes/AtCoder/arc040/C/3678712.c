#include<stdio.h>
#include<stdlib.h>

#define POS(i,j) ((i)*n+(j))

void run(void){
  int n;
  scanf("%d",&n);
  char *s=(char *)calloc(n*n+1,sizeof(char));
  int i,j;
  for(i=0;i<n;i++) scanf("%s",s+POS(i,0));
  int ans=0;
  for(i=0;i<n;i++){
    for(j=n-1;j>=0;j--){
      if(s[POS(i,j)]=='o') continue;
      ans++;
      int k;
      if(i+1<n) for(k=j;k<n;k++) s[POS(i+1,k)]='o';
      break;
    }
  }
  printf("%d\n",ans);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:11:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%s",s+POS(i,0));
                    ^