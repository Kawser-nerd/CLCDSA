#include<stdio.h>
#include<stdlib.h>

#define MIN(a,b) ((a)<(b)?(a):(b))

int cmp(const void *a,const void *b){
  return *(int *)a-*(int *)b;
}

int search(int *a,int n,int v){
  int l=0;
  int r=n;
  while(r-l>1){
    int m=(l+r)/2;
    if(a[m]<=v){
      l=m;
    } else {
      r=m;
    }
  }
  return l;
}

void run(void){
  int all,n,m;
  scanf("%d%d%d",&all,&n,&m);
  int *l=(int *)calloc(n,sizeof(int));
  int i;
  for(i=0;i<n;i++) scanf("%d",l+i);
  int *a=(int *)calloc(n,sizeof(int));
  for(i=0;i<n-1;i++) a[i]=l[i+1]-l[i]-1;
  a[n-1]=0;
  qsort(a,n,sizeof(int),cmp);
  int *sum=(int *)calloc(n,sizeof(int));
  for(i=1;i<n;i++) sum[i]=sum[i-1]+a[i];
  while(m--){
    int x,y;
    scanf("%d%d",&x,&y);
    int k=search(a,n,x+y);
    int ans=n+MIN(l[0]-1,x)+MIN(all-l[n-1],y)+sum[k]+(n-1-k)*(x+y);
    printf("%d\n",ans);
  }
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:26:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&all,&n,&m);
   ^
./Main.c:29:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%d",l+i);
                    ^
./Main.c:38:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&x,&y);
     ^