#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a,const void *b){
  return *(int *)a-*(int *)b;
}

int* enumerate(int *a,int n){
  int *f=(int *)calloc(1<<n,sizeof(int));
  int i,j;
  for(i=0;i<n;i++){
    for(j=0;j<(1<<i);j++){
      f[j+(1<<i)]=f[j]+a[i];
    }
  }
  qsort(f,1<<n,sizeof(int),cmp);
  return f;
}

void run(void){
  int n,x;
  scanf("%d%d",&n,&x);
  int *w=(int *)calloc(n,sizeof(int));
  int i,j;
  for(i=0;i<n;i++) scanf("%d",w+i);
  int m=n/2;
  int *a=enumerate(w,m);
  int *b=enumerate(w+m,n-m);
  int ans=0;
  i=0;
  j=(1<<(n-m))-1;
  while(i<(1<<m) && j>=0){
    if(a[i]+b[j]==x){
      int p=0;
      while(i+p<(1<<m) && a[i+p]==a[i]) p++;
      int q=0;
      while(j-q>=0 && b[j-q]==b[j]) q++;
      ans+=p*q;
      i+=p;
      j-=q;
    } else if(a[i]+b[j]<x){
      i++;
    } else {
      j--;
    }
  }
  printf("%d\n",ans);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:22:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&x);
   ^
./Main.c:25:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%d",w+i);
                    ^