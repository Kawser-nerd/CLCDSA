#include<stdio.h>
#include<string.h>

int main(){
  int tot,j;
  long long int N,K,cnt[61] = {1};
  long long int A;
  for(int i = 1;i<61;i++)
    cnt[i] = cnt[i-1]*2;
  scanf("%d",&tot);
  for(int i = 1;i<=tot;i++){
    scanf("%llu",&N);
    scanf("%llu",&K);
    for(j = 0;cnt[j]<=K;j++){}
    A = N-K-cnt[j-1];
    if(A<0){
      printf("Case #%d: 0 0\n",i);
      continue;
    }
    printf("Case #%d: %lld %lld\n",i,A/cnt[j]+1,A%cnt[j]/cnt[j-1]+A/cnt[j]);
  }
  return 0;
}
