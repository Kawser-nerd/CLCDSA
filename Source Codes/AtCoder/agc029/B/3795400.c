#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

int cmp(const void *a,const void *b){
  return *(int *)a-*(int *)b;
}

void run(void){
  int n;
  scanf("%d",&n);
  int *a=(int *)calloc(n,sizeof(int));
  int i;
  for(i=0;i<n;i++) scanf("%d",a+i);
  int *tmp=(int *)calloc(n,sizeof(int));
  int ans=0;
  for(i=30;i>=1;i--){
    qsort(a,n,sizeof(int),cmp);
    int len=0;
    int p=0;
    int q=n-1;
    while(p<q){
      if(a[p]+a[q]==(1<<i)){
	ans++;
	p++;
	q--;
      } else if(a[p]+a[q]<(1<<i)){
	tmp[len++]=a[p++];
      } else {
	tmp[len++]=a[q--];
      }
    }
    if(p==q){
      tmp[len++]=a[p];
    }
    memcpy(a,tmp,sizeof(int)*len);
    n=len;
  }
  printf("%d\n",ans);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:17:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:20:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%d",a+i);
                    ^