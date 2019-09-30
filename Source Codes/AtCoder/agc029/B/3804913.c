#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a,const void *b){
  return *(int *)a-*(int *)b;
}

void run(void){
  int n;
  scanf("%d",&n);
  int *a=(int *)calloc(n,sizeof(int));
  int i;
  for(i=0;i<n;i++) scanf("%d",a+i);
  qsort(a,n,sizeof(int),cmp);
  int ans=0;
  for(i=30;i>=1;i--){
    int p=0;
    int q=n-1;
    while(p<q){
      if(a[p]+a[q]==(1<<i)){
	ans++;
	a[p++]=0;
	a[q--]=0;
      } else if(a[p]+a[q]<(1<<i)){
	p++;
      } else {
	q--;
      }
    }
    int len=0;
    for(p=0;p<n;p++){
      if(a[p]){
	a[len++]=a[p];
      }
    }
    n=len;
  }
  printf("%d\n",ans);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:13:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%d",a+i);
                    ^