#include <stdio.h>
#include <stdlib.h>

long sequence(long n, long* a)
{
  long i,sum,count1,count2;
  sum = 0;
  count1 = 0;
  for(i = 0; i < n; i++){
    sum += a[i];
    if(i % 2 == 1 && sum <= 0){
      count1 += (1-sum);
      sum = 1;
    }
    if(i % 2 == 0 && sum >= 0){
      count1 += sum+1;
      sum = -1;
    }
  }
  sum = 0;
  count2 = 0;
  for(i = 0; i < n; i++){
    sum += a[i];
    if(i % 2 == 1 && sum >= 0){
      count2 += sum+1;
      sum = -1;
    }
    if(i % 2 == 0 && sum <= 0){
      count2 += 1-sum;
      sum = 1;
    }
  }
  if(count1 < count2){
    return count1;
  }else{
    return count2;
  }
}

int main()
{
  long n,i,result;
  if(scanf("%ld", &n) < 1){
      exit(1);
  }
  long a[n];
  for(i = 0; i < n; i++){
    if(scanf("%ld", &a[i]) < 1){
      exit(1);
    }
  }
  result = sequence(n, a);
  printf("%ld\n",result);
  return 0;
}