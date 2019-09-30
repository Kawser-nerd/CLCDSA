#include <stdio.h>
#include <stdlib.h>

int compare_int(const void *b,const void *a){
  return *(long*)a-*(long*)b;
}

int max(int a,int b){
  if(a > b){
    return a;
  }
  return b;
}

int main(void){
  int N,H;
  scanf("%d%d",&N,&H);

  int a,b[N];
  int maximam = 0;
  for(int i = 0;i < N;i++){
    scanf("%d%d",&a,&b[i]);
    maximam = max(maximam,a);
  }
  qsort(b,N,sizeof(int),compare_int);

  int cnt;
  for(cnt = 0;H > 0 && cnt < N;cnt++){
    if(b[cnt] < maximam) break;
    H -= b[cnt];
  }
  if(H > 0) cnt += (H+maximam-1)/maximam;

  printf("%d\n",cnt);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:17:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&N,&H);
   ^
./Main.c:22:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&a,&b[i]);
     ^