#include <stdio.h>
#include <stdlib.h>
int N;
int a[100000];
int b[100000];

int b_search(int x){
  int l,h,m;
  l=0;h=N;
  while(1){
    
    m=(l+h)/2;
    if(x==b[m])return m;
    else if(x<b[m])h=m;
    else l=m;
  }
}
int comp_int(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}
int main(){
  int i,j;
  scanf("%d",&N);
  int ans=0;
  for(i=0;i<N;i++){
    scanf("%d",&a[i]);
    b[i]=a[i];
  }
  qsort(b,N,sizeof(int),comp_int);
  for(i=0;i<N;i++){
    if(i%2!=b_search(a[i])%2)ans++;
  }
  printf("%d\n",ans/2);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:24:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^
./Main.c:27:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a[i]);
     ^