#include<stdio.h>

int front,rear,queue[50];

int bfs(int *g[],int s,int t,int n){
  int i,j,flag;
  //printf("%d %d???\n",s,t);
  
  if(s==t){//printf("????\n");
    return 1;}
  for(i=2;i<=n;i++){
    if(g[s][i]){
      flag=1;
      for(j=0;j<rear;j++)
        if(queue[j]==i) flag=0;
      if(flag){//printf("%d???\n",i);
        queue[rear++]=i;
      }
    }
  }
  if(front<rear)
    bfs(g,queue[front++],t,n);
  else {//printf("????\n");
    return 0;
  }
}

int main(){
  int n,m,g[51][51]={},i,a[50],b[50],j,flag=1,cnt=0,*gg[51];
  scanf("%d %d",&n,&m);
  for(i=0;i<m;i++){
    scanf("%d %d",&a[i],&b[i]);
    g[a[i]][b[i]]=g[b[i]][a[i]]=1;
  }

  for(i=0;i<m;i++){
    flag=1;
    g[a[i]][b[i]]=g[b[i]][a[i]]=0;
    for(j=0;j<=n;j++)
      gg[j]=g[j];
    for(j=2;j<=n;j++){
      front=rear=0;
      flag*=bfs(gg,1,j,n);
    }
    if(!flag){
      //printf("%d %d\n",a[i],b[i]);
      cnt++;
    }
    g[a[i]][b[i]]=g[b[i]][a[i]]=1;
  }
  printf("%d\n",cnt);
} ./Main.c: In function ‘main’:
./Main.c:30:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&n,&m);
   ^
./Main.c:32:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&a[i],&b[i]);
     ^