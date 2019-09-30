#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int cmp(const void *a,const void *b){
  return *(int *)a-*(int *)b;
}

//a+b>=v 
int calc(int *a,int *b,int n,int v){
  int cnt=0;
  int j=n-1;
  int i;
  for(i=0;i<n;i++){
    while(j>=0 && a[i]+b[j]>=v) j--;
    cnt^=n-1-j;
  }
  return cnt&0x01;
}

void clearAndSort(int *a,int n,int bit,int *c){
  int m=0;
  while(m<n && a[m]<(1<<bit)) m++;
  for(int i=m;i<n;i++) a[i]^=1<<bit;
  int i=0;
  int j=m;
  int k=0;
  while(i<m && j<n){
    if(a[i]<=a[j]){
      c[k++]=a[i++];
    } else {
      c[k++]=a[j++];
    }
  }
  memcpy(c+k,a+i,sizeof(int)*(m-i));
  memcpy(a,c,sizeof(int)*(k+m-i));
}

void run(void){
  int n;
  scanf("%d",&n);
  int *a=(int *)malloc(sizeof(int)*n);
  int *b=(int *)malloc(sizeof(int)*n);
  int i;
  for(i=0;i<n;i++) scanf("%d",a+i);
  for(i=0;i<n;i++) scanf("%d",b+i);
  qsort(a,n,sizeof(int),cmp);
  qsort(b,n,sizeof(int),cmp);
  int *c=(int *)malloc(sizeof(int)*n);
  int ans=0;
  for(int bit=29;bit>=0;bit--){
    clearAndSort(a,n,bit+1,c);
    clearAndSort(b,n,bit+1,c);
    int cnt=calc(a,b,n,1<<bit)^calc(a,b,n,2*(1<<bit))^calc(a,b,n,3*(1<<bit));
    if(cnt) ans+=1<<bit;
  }
  printf("%d\n",ans);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:41:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:45:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%d",a+i);
                    ^
./Main.c:46:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%d",b+i);
                    ^