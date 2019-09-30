#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

void swap(int *a,int *b){
  int t=*a;
  *a=*b;
  *b=t;
  return;
}

void push(int val,int *h){
  int n=h[0]+1;
  h[n]=val;
  while(n>1 && h[n]>h[n/2]){
    swap(h+n,h+n/2);
    n/=2;
  }
  h[0]++;
  return;
}

int pop(int *h){
  int res=h[1];
  swap(h+1,h+h[0]);
  h[0]--;
  int k=1;
  while(2*k+1<=h[0] && h[k]<MAX(h[2*k],h[2*k+1])){
    int next=(h[2*k]>h[2*k+1]?2*k:2*k+1);
    swap(h+k,h+next);
    k=next;
  }
  if(2*k<=h[0] && h[k]<h[2*k]) swap(h+k,h+2*k);
  return res;
}

void run(void){
  int n;
  scanf("%d",&n);
  int *a=(int *)malloc(sizeof(int)*3*n);
  int i;
  for(i=0;i<3*n;i++) scanf("%d",a+i);
  int *h=(int *)malloc(sizeof(int)*3*n);
  h[0]=0;
  int64 sum=0;
  for(i=0;i<n;i++){
    sum+=a[i];
    push(-a[i],h);
  }
  int64 *front=(int64 *)malloc(sizeof(int64)*(n+1));
  front[0]=sum;
  for(i=n;i<2*n;i++){
    if(-h[1]<a[i]){
      sum+=pop(h);
      push(-a[i],h);
      sum+=a[i];
    }
    front[i-n+1]=sum;
  }
  h[0]=0;
  sum=0;
  for(i=3*n-1;i>=2*n;i--){
    sum+=a[i];
    push(a[i],h);
  }
  int64 *back=(int64 *)malloc(sizeof(int64)*(n+1));
  back[n]=sum;
  for(i=2*n-1;i>=n;i--){
    if(h[1]>a[i]){
      sum-=pop(h);
      push(a[i],h);
      sum+=a[i];
    }
    back[i-n]=sum;
  }
  int64 max=front[0]-back[0];
  for(i=1;i<=n;i++){
    max=MAX(max,front[i]-back[i]);
  }
  printf("%lld\n",max);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:45:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:48:22: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<3*n;i++) scanf("%d",a+i);
                      ^