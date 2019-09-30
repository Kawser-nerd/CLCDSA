#include<stdio.h>
#include<stdlib.h>

typedef struct range{
  int l,r;
} node;

int cmp(const void *a,const void *b){
  node *p=(node *)a;
  node *q=(node *)b;
  return (p->r-p->l)-(q->r-q->l);
}

void add(int *bit,int n,int index,int v){
  for(int i=index;i<=n;i+=i&-i) bit[i]+=v;
}

int sum(int *bit,int index){
  int res=0;
  for(int i=index;i>0;i-=i&-i) res+=bit[i];
  return res;
}

void run(void){
  int n,m;
  scanf("%d%d",&n,&m);
  node *a=(node *)calloc(n,sizeof(node));
  int i;
  for(i=0;i<n;i++){
    int l,r;
    scanf("%d%d",&l,&r);
    a[i]=(node){l,r+1};
  }
  qsort(a,n,sizeof(node),cmp);
  int *bit=(int *)calloc(m+2,sizeof(int));
  int k=0;
  for(i=1;i<=m;i++){
    int ans=n-k;
    int j;
    for(j=i;j<=m;j+=i) ans+=sum(bit,j);
    printf("%d\n",ans);
    while(k<n && a[k].r-a[k].l<=i){
      add(bit,m+1,a[k].l,1);
      add(bit,m+1,a[k].r,-1);
      k++;
    }
  }
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:26:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&m);
   ^
./Main.c:31:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&l,&r);
     ^