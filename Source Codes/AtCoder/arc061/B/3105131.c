#include<stdio.h>
#include<stdlib.h>

typedef long long int int64;

typedef struct point2d{
  int a,b;
} point;

int cmp(const void *a,const void *b){
  point *p=(point *)a;
  point *q=(point *)b;
  if(p->a!=q->a) return p->a-q->a;
  return p->b-q->b;
}

void run(void){
  int h,w,n;
  scanf("%d%d%d",&h,&w,&n);
  point *p=(point *)malloc(sizeof(point)*n*9);
  int len=0;
  int i;
  for(i=0;i<n;i++){
    int a,b;
    scanf("%d%d",&a,&b);
    int j,k;
    for(j=-1;j<=1;j++){
      for(k=-1;k<=1;k++){
	if(1<a+j && a+j<h && 1<b+k && b+k<w){
	  p[len].a=a+j;
	  p[len].b=b+k;
	  len++;
	}
      }
    }
  }
  qsort(p,len,sizeof(point),cmp);
  int64 cnt[10]={};
  i=0;
  while(i<len){
    int j=i;
    while(j<len && cmp(p+i,p+j)==0) j++;
    cnt[j-i]++;
    i=j;
  }
  cnt[0]=(int64)(h-2)*(w-2);
  for(i=1;i<=9;i++) cnt[0]-=cnt[i];
  for(i=0;i<=9;i++){
    printf("%lld\n",cnt[i]);
  }
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:19:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&h,&w,&n);
   ^
./Main.c:25:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&a,&b);
     ^