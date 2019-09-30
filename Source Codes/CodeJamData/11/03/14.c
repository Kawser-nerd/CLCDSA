

#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long i64;

main()
{

  int T,t;
  scanf("%d",&T);
  fprintf(stderr,"==== %d \n",T);

  int N;

  for(t=1; t <= T; t++) { 
    scanf("%d", &N);  
    fprintf(stderr,"Case #%d: %d\n",t,N);
    
    int i;
    int sum = 0;
    int xor = 0;
    int min = 20000000;
    for(i=0; i < N; i++) { 
      int n;
      scanf("%d", &n);  
      // fprintf(stderr,">> %d\n",n);
      xor ^= n;
      sum += n;
      if (min>n) {
	min = n;
      }
    }
    if (xor) {
      printf("Case #%d: NO\n",t);
    } else {
      printf("Case #%d: %d\n",t,sum-min);
    }    
  }
}

  
