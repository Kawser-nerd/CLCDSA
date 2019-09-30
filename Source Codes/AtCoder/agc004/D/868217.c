#include<stdio.h>
#include<stdlib.h>

int tele[100001],dis[100001];
int *child_list[100001],child_num[100001];

struct dat{
  int dist,num;
};

int calc(int n);
int comp(const void *p1,const void *p2);
void recalc(int n,int dist);

int main(void){
  int N,K,i,j,m=0;
  struct dat data[100001];
  int write=0;
  
  scanf("%d%d",&N,&K);
  
  for(i=1;i<=N;i++){
    scanf("%d",&tele[i]);
    if(child_num[tele[i]]==0){
      child_list[tele[i]]=(int *)calloc(1,sizeof(int));
    }else{
      child_list[tele[i]]=(int *)realloc(child_list[tele[i]],sizeof(int)*(child_num[tele[i]]+1));
    }
    child_list[tele[i]][child_num[tele[i]]]=i;
    child_num[tele[i]]++;
  }
  
  if(tele[1]!=1) m++;

  data[1]=(struct dat){0,1};
  for(i=2;i<=N;i++){
    calc(i);
    data[i]=(struct dat){dis[i],i};
  }

  qsort(data+1,N,sizeof(data[1]),comp);

  for(i=1;i<=N;i++){
    if(data[i].dist!=dis[data[i].num]) data[i].dist=dis[data[i].num];
    if(data[i].dist<=K) continue;
    
    write=data[i].num;
    for(j=1;j<K;j++){
      write=tele[write];
    }
    //printf("write=%d\n",write);
    tele[write]=1;
    m++;
    recalc(write,1);
    /*printf("dist=");
    for(j=1;j<=N;j++) printf("%d%c",dis[j],j==N?'\n':' ');
    printf("parent=");
    for(j=1;j<=N;j++) printf("%d%c",tele[j],j==N?'\n':' ');*/
  }

  printf("%d\n",m);

  return 0;
}

int calc(int n){
  if(n!=1 && dis[n]==0) dis[n]=calc(tele[n])+1;
  return dis[n];
}

void recalc(int n,int dist){
  int i;
  if(dis[n]<dist) return;
  dis[n]=dist;
  for(i=0;i<child_num[n];i++) recalc(child_list[n][i],dist+1);
}

int comp(const void *p1,const void *p2){
  struct dat n1,n2;
  n1=*(struct dat *)p1;
  n2=*(struct dat *)p2;
  return n2.dist-n1.dist;
} ./Main.c: In function ‘main’:
./Main.c:20:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&N,&K);
   ^
./Main.c:23:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&tele[i]);
     ^