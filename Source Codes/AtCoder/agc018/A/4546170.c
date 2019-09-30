#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a,const void *b){
  return *(int *)a-*(int *)b;
}

int gcd(int a,int b){
  if(b==0) return a;
  int r=a%b;
  while(r>0){
    a=b;b=r;r=a%b;
  }
  return b;
}

void run(void){
  int n,k;
  scanf("%d%d",&n,&k);
  int *a=(int *)calloc(n,sizeof(int));
  int i;
  for(i=0;i<n;i++) scanf("%d",a+i);
  qsort(a,n,sizeof(int),cmp);
  int g=a[0];
  for(i=1;i<n;i++) g=gcd(g,a[i]-a[i-1]);
  if(k<=a[n-1] && k%g==0){
    puts("POSSIBLE");
  } else {
    puts("IMPOSSIBLE");
  }
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:19:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&k);
   ^
./Main.c:22:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%d",a+i);
                    ^