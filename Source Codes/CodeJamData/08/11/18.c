#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int comp1(const long long int *a, const long long int *b){
  return *a - *b;
}
int comp2(const long long int *a, const long long int *b){
  return *b - *a;
}

int main(){
  int i, j, k, test;
  int n;
  long long int ans;
  long long int x[1000], y[1000];

  scanf("%d",&test);
  for(k=1;k<=test;k++){
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%lld",&x[i]);
    for(i=0;i<n;i++)scanf("%lld",&y[i]);
    qsort(x,n,sizeof(long long int),(int (*)(const void*, const void*))comp1);
    qsort(y,n,sizeof(long long int),(int (*)(const void*, const void*))comp2);
    ans=0;
    for(i=0;i<n;i++)ans+=x[i]*y[i];
    printf("Case #%d: ",k);
    printf("%lld\n",ans);
  }
}
