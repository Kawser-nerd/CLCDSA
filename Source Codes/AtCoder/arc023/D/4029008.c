#include<stdio.h>
#include<stdlib.h>

typedef long long int int64;

int gcd(int a,int b){
  int r=a%b;
  while(r>0){
    a=b;b=r;r=a%b;
  }
  return b;
}

typedef struct cntVal{
  int val;
  int64 cnt;
} node;

int cmp(const void *a,const void *b){
  return ((node *)a)->val-((node *)b)->val;
}

void run(void){
  int n,m;
  scanf("%d%d",&n,&m);
  node *array=(node *)calloc(32*n,sizeof(node));
  int alen=0;
  node s[32];
  int len=0;
  while(n--){
    int a;
    scanf("%d",&a);
    int i,j;
    for(i=0;i<len;i++) s[i].val=gcd(s[i].val,a);
    s[len++]=(node){a,1};
    i=j=0;
    while(i<len){
      s[j]=s[i++];
      while(i<len && cmp(s+j,s+i)==0) s[j].cnt+=s[i++].cnt;
      j++;
    }
    len=j;
    for(i=0;i<len;i++) array[alen++]=s[i];
  }
  qsort(array,alen,sizeof(node),cmp);
  len=0;
  int i=0;
  while(i<alen){
    array[len]=array[i++];
    while(i<alen && cmp(array+len,array+i)==0) array[len].cnt+=array[i++].cnt;
    len++;
  }
  while(m--){
    int x;
    scanf("%d",&x);
    if(x<array[0].val || array[len-1].val<x){
      puts("0");
      continue;
    }
    int l=0;
    int r=len;
    while(r-l>1){
      int m=(l+r)/2;
      if(array[m].val<=x){
	l=m;
      } else {
	r=m;
      }
    }
    printf("%lld\n",array[l].val==x?array[l].cnt:0);
  }
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:25:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&m);
   ^
./Main.c:32:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a);
     ^
./Main.c:55:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&x);
     ^