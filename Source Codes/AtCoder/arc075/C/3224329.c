#include<stdio.h>
#include<stdlib.h>

typedef long long int int64;

int cmp(const void *a,const void *b){
  int64 p=*(int64 *)a;
  int64 q=*(int64 *)b;
  return p==q?0:p<q?-1:1;
}

int64 *za=NULL;
int len=0;
void zaatsu(int64 *b,int n){
  za=(int64 *)malloc(sizeof(int64)*n);
  int i;
  for(i=0;i<n;i++) za[i]=b[i];
  qsort(za,n,sizeof(int64),cmp);
  len=0;
  i=0;
  while(i<n){
    za[len++]=za[i++];
    while(i<n && za[len-1]==za[i]) i++;
  }
  return;
}

int toIndex(int64 v){
  int l=0;
  int r=len;
  while(r-l>1){
    int m=(l+r)/2;
    if(za[m]<=v){
      l=m;
    } else {
      r=m;
    }
  }
  return l;
}

void inc(int *bit,int n,int index){
  int i;
  for(i=index;i<=n;i+=i&-i) bit[i]++;
  return;
}

int sum(int *bit,int n,int index){
  int res=0;
  int i;
  for(i=index;i>0;i-=i&-i) res+=bit[i];
  return res;
}

void run(void){
  int n,k;
  scanf("%d%d",&n,&k);
  int *a=(int *)malloc(sizeof(int)*n);
  int i;
  for(i=0;i<n;i++){
    scanf("%d",a+i);
    a[i]-=k;
  }
  int64 *b=(int64 *)malloc(sizeof(int64)*(n+1));
  b[0]=0;
  for(i=1;i<=n;i++) b[i]=b[i-1]+a[i-1];
  zaatsu(b,n+1);
  int *bit=(int *)calloc(len+1,sizeof(int));
  int64 ans=0;
  for(i=0;i<=n;i++){
    int index=toIndex(b[i])+1;
    ans+=sum(bit,len,index);
    inc(bit,len,index);
  }
  printf("%lld\n",ans);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:57:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&k);
   ^
./Main.c:61:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",a+i);
     ^