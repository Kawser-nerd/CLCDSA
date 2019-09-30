#include <stdio.h>
#include <stdlib.h>

long long int X[50], V[50], will_make_it[50];

int main() {

  long long int C, N, K, B, T, i ,j, swaps, count;

  scanf("%lld", &C);

  for(i=0; i<C; i++) {
    scanf("%lld %lld %lld %lld", &N, &K, &B, &T);
    
    for(j=0; j<N; j++)
      scanf("%lld", &X[j]);
    for(j=0; j<N; j++)
      scanf("%lld", &V[j]);
    swaps=0;
    count=0;
    for(j=0; j<N; j++) 
      if(B-X[j]-T*V[j]<=0)
	will_make_it[j]=1;
      else
	will_make_it[j]=0;
    for(j=N-1; j>=0; j--) {
      if(!K) break;
      if(will_make_it[j]==1) {
	K--;
	swaps+=count;
      }
      else
	count++;
    }
      
    if(!K) printf("Case #%lld: %lld\n", (i+1), swaps);
    else
      printf("Case #%lld: IMPOSSIBLE\n", (i+1));

  }

}
