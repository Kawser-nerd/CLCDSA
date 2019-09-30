#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
  int tot,D,N;
  int H[1000];
  double S[1000],max,time;
  scanf("%d",&tot);
  for(int i = 1;i<=tot;i++){
    max = 0;
    scanf("%d%d",&D,&N);
    for(int j = 0;j<N;j++)
      scanf("%d%lf",&H[j],&S[j]);
    for(int j = 0;j<N;j++){
      time = (D-H[j])/S[j];
      if(time>max)
        max = time;
    }
    printf("Case #%d: %lf\n",i,D/max);
  }
  return 0;
}
