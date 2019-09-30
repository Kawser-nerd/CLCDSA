#include<stdio.h>
#include<stdlib.h>

typedef struct water{
  double t;
  int v;
} node;

void run(void){
  int n,l;
  scanf("%d%d",&n,&l);
  node *q=(node *)calloc(n,sizeof(node));
  int front=0;
  int last=0;
  double t;
  int v;
  scanf("%lf%d",&t,&v);
  printf("%.7f\n",t);
  q[last++]=(node){t,v};
  double qtv=t*v;
  int i;
  for(i=1;i<n;i++){
    node in;
    scanf("%lf%d",&in.t,&in.v);
    int sum=0;
    node p=q[front];
    while(sum+p.v<=in.v){
      qtv-=p.v*p.t;
      sum+=p.v;
      front++;
      p=q[front];
    }
    if(sum<in.v){
      qtv-=q[front].t*(in.v-sum);
      q[front].v-=in.v-sum;
    }
    qtv+=in.t*in.v;
    while(front<last && q[last-1].t>in.t){
      last--;
      p=q[last];
      in=(node){(in.t*in.v+p.t*p.v)/(in.v+p.v),in.v+p.v};
    }
    q[last++]=in;
    printf("%.7f\n",qtv/l);
  }
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&l);
   ^
./Main.c:17:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lf%d",&t,&v);
   ^
./Main.c:24:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lf%d",&in.t,&in.v);
     ^