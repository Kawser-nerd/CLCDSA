#include<stdio.h>
#include<stdlib.h>

typedef long long int int64;

typedef struct factor{
  int p;
  int a;
} factor;

void factorize(int n,factor *f,int *resLen){
  int len=0;
  int i;
  for(i=2;i*i<=n;i++){
    if(n%i!=0) continue;
    f[len].p=i;
    f[len].a=0;
    while(n%i==0){
      n/=i;
      f[len].a++;
    }
    len++;
  }
  if(n>1){
    f[len++]=(factor){n,1};
  }
  *resLen=len;
}

int cmp(const void *a,const void *b){
  return ((factor *)a)->p-((factor *)b)->p;
}

void run(void){
  int a,b;
  scanf("%d%d",&a,&b);
  factor *f=(factor *)calloc(32*100,sizeof(factor));
  int len=0;
  int i;
  for(i=b+1;i<=a;i++){
    int k;
    factorize(i,f+len,&k);
    len+=k;
  }
  qsort(f,len,sizeof(factor),cmp);
  const int mod=1000000007;
  int ans=1;
  i=0;
  while(i<len){
    int a=0;
    int j=i;
    while(j<len && f[j].p==f[i].p) a+=f[j++].a;
    ans=(int64)ans*(a+1)%mod;
    i=j;
  }
  printf("%d\n",ans);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:36:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&a,&b);
   ^