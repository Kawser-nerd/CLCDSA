#include<stdio.h>
#include<stdlib.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))

int64 calc(const int *x,const int n,const int l){
  int64 *front=(int64 *)calloc(n+1,sizeof(int64));
  int64 *back=(int64 *)calloc(n+1,sizeof(int64));
  int i,j;
  for(i=1;i<n;i++) front[i]=front[i-1]+x[i-1]+x[i];
  for(i=n-1;i>=0;i--) back[i]=back[i+1]+2*(l-x[i]);
  int64 ans=0;
  for(i=0;i<n;i++){
    int64 local=x[i];
    j=(n-2-i)/2;
    if(i+j+1>=n-1-j) j--;
    local+=front[i+j+1]-front[i]+back[n-1-j];
    j++;
    /*
    for(j=0;i+j+1<n-1-j;j++){
      local+=x[i+j]+l-x[n-1-j];
      local+=l-x[n-1-j]+x[i+j+1];
    }
    */
    if(i+j<n-1-j) local+=x[i+j]+l-x[n-1-j];
    ans=MAX(ans,local);
  }
  free(front);
  free(back);
  return ans;
}

void run(void){
  int l,n;
  scanf("%d%d",&l,&n);
  int *x=(int *)calloc(n,sizeof(int));
  int i;
  for(i=0;i<n;i++) scanf("%d",x+i);
  int64 a=calc(x,n,l);
  for(i=0;i<n;i++) x[i]=l-x[i];
  for(i=0;i<n-1-i;i++){
    int t=x[i];
    x[i]=x[n-1-i];
    x[n-1-i]=t;
  }
  int64 b=calc(x,n,l);
  printf("%lld\n",MAX(a,b));
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:37:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&l,&n);
   ^
./Main.c:40:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%d",x+i);
                    ^