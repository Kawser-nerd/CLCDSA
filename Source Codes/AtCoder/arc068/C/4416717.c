#include<stdio.h>
#include<stdlib.h>

typedef struct range{
  int l,r;
} range;

int cmp(const void *a,const void *b){
  range *p=(range *)a;
  range *q=(range *)b;
  return (p->r-p->l)-(q->r-q->l);
}

void add(int *bit,int x,int v){
  int n=bit[0];
  for(int i=x;i<=n;i+=i&-i) bit[i]+=v;
}

int sum(int *bit,int x){
  int res=0;
  for(int i=x;i>0;i-=i&-i) res+=bit[i];
  return res;
}

void run(void){
  int n,m;
  scanf("%d%d",&n,&m);
  range *p=(range *)calloc(n,sizeof(range));
  int i;
  for(i=0;i<n;i++) scanf("%d%d",&p[i].l,&p[i].r);
  qsort(p,n,sizeof(range),cmp);
  int *bit=(int *)calloc(m+2,sizeof(int));
  bit[0]=m+1;
  int j=0;
  for(i=1;i<=m;i++){
    while(j<n && p[j].r-p[j].l+1<i){
      add(bit,p[j].l,1);
      add(bit,p[j].r+1,-1);
      j++;
    }
    int cnt=n-j;
    for(int k=i;k<=m;k+=i){
      cnt+=sum(bit,k);
    }
    printf("%d\n",cnt);
  }
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:27:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&m);
   ^
./Main.c:30:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%d%d",&p[i].l,&p[i].r);
                    ^