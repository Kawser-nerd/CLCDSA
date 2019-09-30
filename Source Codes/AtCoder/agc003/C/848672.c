#include<stdio.h>
#include<stdlib.h>
int N[100000];
int N2[100000];
int n;


int cmp(const void *x, const void *y){
  return *(int*)x - *(int*)y;
}

int main(){
  int ans = 0;
  int i,j;
  scanf("%d",&n);
  for(i = 0; i < n; i++){
    scanf("%d",&N[i]);
    N2[i] = N[i];
  }
  qsort(N2,n,sizeof(int),cmp);
  for(i = 0; i < n; i++){
    int l = 0,r = n-1,k;
    
    while(l <= r){
      k = (l+r)/2;
      if(N2[k] == N[i])break;
      else if(N2[k] > N[i])r = k-1;
      else l = k+1;
    }
   
    if(i % 2 != k % 2)ans++;
  }
      

  printf("%d\n",ans/2);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:17:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&N[i]);
     ^