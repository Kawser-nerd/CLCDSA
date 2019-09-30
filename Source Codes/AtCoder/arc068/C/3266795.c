#include<stdio.h>
#include<stdlib.h>

typedef struct node{
  int l,r;
} range;

int cmp(const void *a,const void *b){
  range *p=(range *)a;
  range *q=(range *)b;
  return (p->r-p->l)-(q->r-q->l);
}

void add(int *bit,int l,int r){
  int n=bit[0];
  int i;
  for(i=l;i<=n;i+=i&-i) bit[i]++;
  for(i=r;i<=n;i+=i&-i) bit[i]--;
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
  range *a=(range *)malloc(sizeof(range)*n);
  int i;
  for(i=0;i<n;i++){
    int l,r;
    scanf("%d%d",&l,&r);
    a[i].l=l;
    a[i].r=r;
  }
  qsort(a,n,sizeof(range),cmp);
  int *bit=(int *)calloc(m+2,sizeof(int));
  bit[0]=m+1;
  int d;
  for(d=1,i=0;d<=m;d++){
    while(i<n && a[i].r-a[i].l+1<d){
      add(bit,a[i].l,a[i].r+1);
      i++;
    }
    int ans=n-i;
    int j;
    for(j=d;j<=m;j+=d) ans+=get(bit,j);
    printf("%d\n",ans);
  }
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:31:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&m);
   ^
./Main.c:36:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&l,&r);
     ^