#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

typedef struct range{
  int l,r;
} node;

int cmp(const void *a,const void *b){
  node *p=(node *)a;
  node *q=(node *)b;
  return (p->r-p->l)-(q->r-q->l);
}

void add(int *bit,int l,int r){
  int i;
  for(i=l;i<=bit[0];i+=i&-i) bit[i]++;
  for(i=r;i<=bit[0];i+=i&-i) bit[i]--;
  return;
}

int get(int *bit,int index){
  int res=0;
  int i;
  for(i=index;i>0;i-=i&-i) res+=bit[i];
  return res;
}

void run(void){
  int n,m;
  scanf("%d%d",&n,&m);
  node *array=(node *)malloc(sizeof(node)*n);
  int i;
  for(i=0;i<n;i++){
    int l,r;
    scanf("%d%d",&l,&r);
    array[i].l=l;
    array[i].r=r;
  }
  qsort(array,n,sizeof(node),cmp);
  int *bit=(int *)calloc(m+2,sizeof(int));
  bit[0]=m+1;
  int d;
  for(d=1,i=0;d<=m;d++){
    while(i<n && array[i].r-array[i].l+1<d){
      add(bit,array[i].l,array[i].r+1);
      i++;
    }
    int ans=n-i;
    int j;
    for(j=d;j<=m;j+=d){
      ans+=get(bit,j);
    }
    printf("%d\n",ans);
  }
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:37:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&m);
   ^
./Main.c:42:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&l,&r);
     ^