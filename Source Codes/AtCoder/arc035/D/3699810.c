#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double *logFact=NULL;
void init(void){
  const int up=2000000;
  logFact=(double *)calloc(up+1,sizeof(double));
  logFact[0]=0;
  int i;
  for(i=1;i<=up;i++) logFact[i]=logFact[i-1]+log(i);
}

typedef struct point2d{
  int x,y;
} point;

void add(double *bit,int n,int index,double v){
  for(int i=index;i<=n;i+=i&-i) bit[i]+=v;
}

double sum(double *bit,int n,int index){
  double res=0;
  for(int i=index;i>0;i-=i&-i) res+=bit[i];
  return res;
}

inline double way(point a,point b){
  int dx=b.x-a.x;
  int dy=b.y-a.y;
  return logFact[dx+dy]-logFact[dx]-logFact[dy];
}

void run(void){
  init();
  int n;
  scanf("%d",&n);
  point *p=(point *)calloc(n+2,sizeof(point));
  int i;
  for(i=1;i<=n;i++) scanf("%d%d",&p[i].x,&p[i].y);
  p[0]=(point){1,1};
  p[n+1]=(point){1000000,1000000};
  const int len=n+1;
  double *bit=(double *)calloc(1+len,sizeof(double));
  for(i=1;i<=n+1;i++) add(bit,len,i,way(p[i-1],p[i]));
  int q;
  scanf("%d",&q);
  while(q--){
    int type;
    scanf("%d",&type);
    if(type==1){
      int k,a,b;
      scanf("%d%d%d",&k,&a,&b);
      add(bit,len,k  ,-way(p[k-1],p[k]));
      add(bit,len,k+1,-way(p[k],p[k+1]));
      p[k]=(point){a,b};
      add(bit,len,k  ,way(p[k-1],p[k]));
      add(bit,len,k+1,way(p[k],p[k+1]));
    } else {
      int a,b,c,d;
      scanf("%d%d%d%d",&a,&b,&c,&d);
      double e=sum(bit,len,b)-sum(bit,len,a);
      double f=sum(bit,len,d)-sum(bit,len,c);
      printf("%s\n",e>f?"FIRST":"SECOND");
    }
  }
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:37:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:40:21: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=1;i<=n;i++) scanf("%d%d",&p[i].x,&p[i].y);
                     ^
./Main.c:47:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&q);
   ^
./Main.c:50:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&type);
     ^
./Main.c:53:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%d%d%d",&k,&a,&b);
       ^
./Main.c:61:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%d%d%d%d",&a,&b,&c,&d);
       ^