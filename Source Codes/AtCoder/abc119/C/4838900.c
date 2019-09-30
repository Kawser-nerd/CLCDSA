#include <stdio.h>
#include <stdlib.h>

int min(int a,int b){
  if(a < b){
    return a;
  }
  return b;
}

int main(void){
  int N,A,B,C;
  scanf("%d%d%d%d",&N,&A,&B,&C);

  int l[N];
  for(int i = 0;i < N;i++){
    scanf("%d",&l[i]);
  }

  int l1,l2,l3;
  int cost,flag[3];
  int ans = 1e9;
  for(int i = 0;i < 1<<(N*3);i++){
    l1 = 0; l2 = 0; l3 = 0; cost = 0;
    flag[0] = 0; flag[1] = 0; flag[2] = 0;
    for(int j = 0;j < N;j++){
      switch((i >> 2*j)&3){
        case 0:
          l1 += l[j];
          flag[0] = 1;
          cost += 10;
          break;
        case 1:
          l2 += l[j];
          flag[1] = 1;
          cost += 10;
          break;
        case 2:
          l3 += l[j];
          flag[2] = 1;
          cost += 10;
          break;
      }
    }
    if(flag[0] && flag[1] && flag[2]){
      cost += abs(A-l1);
      cost += abs(B-l2);
      cost += abs(C-l3);
      cost -= 30;
      ans = min(ans,cost);
    }
  }

  printf("%d\n",ans);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d%d",&N,&A,&B,&C);
   ^
./Main.c:17:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&l[i]);
     ^