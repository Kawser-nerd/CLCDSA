#include<stdio.h>
#include<stdlib.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

int n;
int *l=NULL;
int *r=NULL;

int cmpL(const void *a,const void *b){
  int p=*(int *)a;
  int q=*(int *)b;
  return -(l[p]-l[q]);
}

int cmpR(const void *a,const void *b){
  int p=*(int *)a;
  int q=*(int *)b;
  return r[p]-r[q];
}

int64 calc(int *a,int *b){
  int *used=(int *)calloc(n,sizeof(int));
  int now=0;
  int64 sum=0;
  int i=0,j=0;
  while(i<n || j<n){
    while(i<n && (used[a[i]] || (l[a[i]]<=now && now<=r[a[i]]))) i++;
    if(i<n){
      int x=ABS(l[a[i]]-now);
      int y=ABS(r[a[i]]-now);
      sum+=MIN(x,y);
      now=x>=y?r[a[i]]:l[a[i]];
      used[a[i]]=1;
    }
    while(j<n && (used[b[j]] || (l[b[j]]<=now && now<=r[b[j]]))) j++;
    if(j<n){
      int x=ABS(l[b[j]]-now);
      int y=ABS(r[b[j]]-now);
      sum+=MIN(x,y);
      now=x>=y?r[b[j]]:l[b[j]];
      used[b[j]]=1;
    }
  }
  free(used);
  return sum+ABS(now);
}

void run(void){
  scanf("%d",&n);
  l=(int *)malloc(sizeof(int)*n);
  r=(int *)malloc(sizeof(int)*n);
  int i;
  for(i=0;i<n;i++) scanf("%d%d",l+i,r+i);
  int *lIndex=(int *)malloc(sizeof(int)*n);
  int *rIndex=(int *)malloc(sizeof(int)*n);
  for(i=0;i<n;i++) lIndex[i]=rIndex[i]=i;
  qsort(lIndex,n,sizeof(int),cmpL);
  qsort(rIndex,n,sizeof(int),cmpR);
  int64 x=calc(lIndex,rIndex);
  int64 y=calc(rIndex,lIndex);
  printf("%lld\n",MAX(x,y));
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:54:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:58:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%d%d",l+i,r+i);
                    ^