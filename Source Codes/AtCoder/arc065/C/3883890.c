#include<stdio.h>
#include<stdlib.h>

#define ABS(a) ((a)>0?(a):-(a))

typedef long long int int64;

typedef struct inode{
  int x,y;
  int index;
} point;

int cmp(const void *a,const void *b){
  point *p=(point *)a;
  point *q=(point *)b;
  int c=p->x+p->y;
  int d=q->x+q->y;
  if(c!=d) return c<d?-1:1;
  return p->x-q->x;
}

int distance(point *a,point *b){
  return ABS(a->x-b->x)+ABS(a->y-b->y);
}

int root(int *u,int x){
  if(u[x]==x) return x;
  return u[x]=root(u,u[x]);
}

void unite(int *u,int x,int y){
  x=root(u,x);
  y=root(u,y);
  if(x==y) return;
  u[x]=y;
}

void calc(point *p,int n,int *u,int d){
  qsort(p,n,sizeof(point),cmp);
  int i,j;
  j=1;
  for(i=0;i<n;i++){
    if(distance(p+i,p+j-1)==d) unite(u,p[i].index,p[j-1].index);
    while(j<n && cmp(p+j,&((point){p[i].x+d,p[i].y,0}))<=0){
      if(distance(p+i,p+j)==d){
	unite(u,p[i].index,p[j].index);
      }
      j++;
    }
  }
}

int64 calc2(point *p,int n,int d){
  qsort(p,n,sizeof(point),cmp);
  int64 res=0;
  int l=0;
  int r=0;
  int i;
  for(i=0;i<n;i++){
    while(l<n && cmp(p+l,&((point){p[i].x,p[i].y+d,0}))<0) l++;
    while(r<n && cmp(p+r,&((point){p[i].x+d,p[i].y,0}))<0) r++;
    res+=r-l;
  }
  return res;
}

void run(void){
  int n,a,b;
  scanf("%d%d%d",&n,&a,&b);
  point *p=(point *)calloc(n,sizeof(point));
  int i;
  for(i=0;i<n;i++){
    int x,y;
    scanf("%d%d",&x,&y);
    p[i]=(point){x,y,i+1};
  }
  int d=distance(p+a-1,p+b-1);
  int *u=(int *)calloc(n+1,sizeof(int));
  for(i=0;i<=n;i++) u[i]=i;
  calc(p,n,u,d);
  for(i=0;i<n;i++) p[i]=(point){-p[i].y,p[i].x,p[i].index};
  calc(p,n,u,d);
  int len=0;
  for(i=0;i<n;i++){
    if(root(u,a)==root(u,p[i].index)){
      p[len++]=p[i];
    }
  }
  int64 ans=0;
  ans+=calc2(p,len,d);
  for(i=0;i<len;i++) p[i]=(point){-p[i].y,p[i].x,p[i].index};
  ans+=calc2(p,len,d);
  printf("%lld\n",ans);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:69:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&n,&a,&b);
   ^
./Main.c:74:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&x,&y);
     ^