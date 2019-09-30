#include <stdio.h>
#include <stdlib.h>
#define MAXn 1000

int cmp1(const void *i, const void *j){
  return *(int *)i - *(int *)j;
}

int cmp2(const void *i, const void *j){
  return *(int *)j - *(int *)i;
}

int main(){
  int nt,nt0;
  int i,n;
  long long int sum;
  int v1[MAXn],v2[MAXn];

  scanf(" %d", &nt0);
  for(nt=1 ; nt<=nt0 ; nt++){
    scanf(" %d", &n);

    for(i=0 ; i<n ; i++) scanf(" %d", &v1[i]);
    for(i=0 ; i<n ; i++) scanf(" %d", &v2[i]);

    qsort(v1,n,sizeof(int),cmp1);
    qsort(v2,n,sizeof(int),cmp2);

    sum=0;
    for(i=0 ; i<n ; i++) sum+= v1[i]*v2[i];

    printf("Case #%d: %lld\n", nt, sum);
  }

  return 0;
}
