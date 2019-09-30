#include <stdio.h>
#include <stdlib.h>

int m[10000];

int main() {

  int T, i, j;
  scanf("%d", &T);
  
  for(i=1; i<=T; i++) {
    int N;
    scanf("%d", &N);
    
    for(j=0; j<N; j++)
      scanf("%d", &m[j]);

    int min1=0, min2=0;
    
    int max_rate = 0;

    for(j=1; j<N; j++) {
      if(m[j]<m[j-1])
	min1+=(m[j-1]-m[j]);
      
      if(m[j-1]-m[j]>max_rate)
	max_rate = m[j-1]-m[j];

    }
    
    for(j=0; j<N-1; j++) {
      if(m[j]<max_rate)
	min2+=m[j];
      else
	min2+=max_rate;
      
    }

    printf("Case #%d: %d %d\n", i, min1, min2);
    
  }

  return 0;

}
