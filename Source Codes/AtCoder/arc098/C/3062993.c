#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

int cmp(const void *a,const void *b){
  return *(int *)a-*(int *)b;
}

void run(void){
  int n,k,q;
  scanf("%d%d%d",&n,&k,&q);
  int *a=(int *)malloc(sizeof(int)*n);
  int i;
  for(i=0;i<n;i++) scanf("%d",a+i);
  int min=1000000000;
  for(i=0;i<n;i++){
    int local=a[i];
    int b[2000];
    int c[2000];
    int clen=0;
    int j;
    for(j=0;j<n;j++){
      if(a[j]<local) continue;
      int blen=0;
      while(j+blen<n && a[j+blen]>=local){
	b[blen]=a[j+blen];
	blen++;
      }
      if(blen>=k){
	qsort(b,blen,sizeof(int),cmp);
	int l;
	for(l=0;l<blen-k+1;l++) c[clen++]=b[l];
      }
      j+=blen;
    }
    if(clen>=q){
      qsort(c,clen,sizeof(int),cmp);
      min=MIN(min,c[q-1]-local);
    }
  }
  printf("%d\n",min);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:17:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&n,&k,&q);
   ^
./Main.c:20:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%d",a+i);
                    ^