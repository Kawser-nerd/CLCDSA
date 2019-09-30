

#include <stdio.h>

typedef unsigned long long i64;

main()
{

  int T,t;
  scanf("%d",&T);

  int N;
  i64 K;

  for(t=1; t <= T; t++) { 
    scanf("%d %lld", &N, &K);  
    
    i64 test = 1;
    test = (test << N) - 1;
    
    char * res = (((K & test) == test) ? "ON" : "OFF");


    printf("Case #%d: %s\n",t,res);
    fprintf(stderr,"Case #%d: %s\n",t,res);
  }
}

  
