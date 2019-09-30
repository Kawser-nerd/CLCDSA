#include<stdio.h>
#include<stdlib.h>

typedef long long int int64;

int cmp(const void *a,const void *b){
  return *(int *)a-*(int *)b;
}

//a+b>=v 
int64 calc(int *a,int *b,int n,int v){
  int i=0;
  int j=n-1;
  while(i<n && a[i]+b[j]<v) i++;
  int64 cnt=0;
  for(;i<n;i++){
    while(j>=0 && a[i]+b[j]>=v) j--;
    cnt+=n-1-j;
  }
  return cnt;
}

void run(void){
  int n;
  scanf("%d",&n);
  int *a=(int *)malloc(sizeof(int)*n);
  int *b=(int *)malloc(sizeof(int)*n);
  int i;
  for(i=0;i<n;i++) scanf("%d",a+i);
  for(i=0;i<n;i++) scanf("%d",b+i);
  int ans=0;
  int bit;
  for(bit=29;bit>=0;bit--){
    for(i=0;i<n;i++) a[i]=a[i]&((1<<(bit+1))-1);
    for(i=0;i<n;i++) b[i]=b[i]&((1<<(bit+1))-1);
    qsort(a,n,sizeof(int),cmp);
    qsort(b,n,sizeof(int),cmp);
    int64 cnt=(calc(a,b,n,1<<bit)-calc(a,b,n,2*(1<<bit))+calc(a,b,n,3*(1<<bit)));
    if(cnt%2) ans+=1<<bit;
  }
  printf("%d\n",ans);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:25:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:29:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%d",a+i);
                    ^
./Main.c:30:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%d",b+i);
                    ^