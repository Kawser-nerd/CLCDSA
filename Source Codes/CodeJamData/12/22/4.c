#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
  int x,y;
  int time;
}node;

int compare(const void*s,const void*t){
  return ((node*)s)->time-((node*)t)->time;
}

int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};

int vis[200][200];

float solve(){
  memset(vis,0,sizeof(vis));
  int h,n,m;
  scanf("%d%d%d",&h,&n,&m);

  int c[n][m],f[n][m];
  for(int i=0;i<n;++i)
    for(int j=0;j<m;++j)
      scanf("%d",c[i]+j);
  for(int i=0;i<n;++i)  
    for(int j=0;j<m;++j)
      scanf("%d",f[i]+j);

  node arr[n*m+2000];
  int s=0;
  arr[s++]=(node){0,0,0};
  while(s){
    qsort(arr,s,sizeof(node),compare);
    node p=arr[0];
    arr[0]=arr[--s];
    if(vis[p.x][p.y])continue;
    vis[p.x][p.y]=1;
    if(p.x==n-1 && p.y==m-1)
      return p.time;
    
    for(int i=0;i<4;++i){
      int nx=p.x+dx[i],ny=p.y+dy[i];
      if(0>nx || 0>ny ||
         nx>=n || ny>=m)continue;
      if(c[nx][ny]-f[nx][ny]<50)continue;
      if(c[nx][ny]-f[p.x][p.y]<50)continue;
      if(c[p.x][p.y]-f[nx][ny]<50)continue;
      if(p.time==0 && c[nx][ny]-h>=50){
        arr[s++]=(node){nx,ny,p.time};
        continue;
      }
      double ct=(50-c[nx][ny]+h);
      if(ct<=p.time){
        if((h-p.time)-f[p.x][p.y]>=20)
          arr[s++]=(node){nx,ny,p.time+10};
        else
          arr[s++]=(node){nx,ny,p.time+100};
      }else{
        if((h-ct)-f[p.x][p.y]>=20)
          arr[s++]=(node){nx,ny,ct+10};
        else
          arr[s++]=(node){nx,ny,ct+100};
      }
    }
  }
}

int main(){
  int t;
  scanf("%d",&t);
  for(int i=0;i<t;++i)
    printf("Case #%d: %.15f\n",i+1,solve()/10.0);
}
