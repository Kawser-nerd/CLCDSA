#include<stdio.h>
#include<stdlib.h>

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

int cmp(const void *a,const void *b){
  return *(int *)a-*(int *)b;
}

void run(void){
  int all,n,m;
  scanf("%d%d%d",&all,&n,&m);
  int *l=(int *)calloc(n,sizeof(int));
  int i;
  for(i=0;i<n;i++) scanf("%d",l+i);
  int *d=(int *)calloc(n,sizeof(int));
  for(i=0;i<n-1;i++) d[i]=l[i+1]-l[i]-1;
  d[n-1]=0;
  qsort(d,n,sizeof(int),cmp);
  int *sum=(int *)calloc(n,sizeof(int));
  for(i=1;i<n;i++) sum[i]=sum[i-1]+d[i];
  while(m--){
    int x,y;
    scanf("%d%d",&x,&y);
    int ll=0;
    int rr=n;
    while(rr-ll>1){
      int m=(ll+rr)/2;
      if(d[m]<=x+y){
	ll=m;
      } else {
	rr=m;
      }
    }
    int ans=n+MIN(l[0]-1,x)+MIN(all-l[n-1],y)+sum[ll]+(x+y)*(n-rr);
    printf("%d\n",ans);
  }
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&all,&n,&m);
   ^
./Main.c:16:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%d",l+i);
                    ^
./Main.c:25:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&x,&y);
     ^