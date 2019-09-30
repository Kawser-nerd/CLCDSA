#include <stdio.h>
#include <stdlib.h>

int M[1000];

long long int get_count(long long int time, int B) {

  int i;
  long long int count = 0;
  for(i=0; i<B; i++) {
    count += time/M[i] + (time%M[i]!=0);
  }
  
  return count;

}

int main() {

  int T,i,j,k;
  scanf("%d", &T);
  
  for(i=1; i<=T; i++) {
    //printf("Doing Case %d/%d\n", i,T);
    int B, N;
    scanf("%d %d", &B, &N);
    for(j=0; j<B; j++)
      scanf("%d", &M[j]);

    long long int lower = 0, upper = 1;
    for(j=0; j<15; j++)
      upper*=10;
    
    while(lower<upper-1) {
      //printf("(%lld,%lld)\n", lower, upper);
      long long int mid = (lower+upper)/2;
      
      long long int count = get_count(mid, B);
      
      if(count>=N) {
	//seen too many people
	upper = mid;
      }
      else {
	lower = mid;
      }
      
    }

    //printf("%lld\n", lower);
    
    long long int num_left = N-get_count(lower, B);
    
    long long int time = lower;
    
    int c = 0;

    for(j=0; j<B; j++) {
      if(lower%M[j]==0) {
	c++;
	if(c==num_left) {
	  printf("Case #%d: %d\n", i, j+1);
	  break;
	}
      }
    }
  }

  return 0;

}
