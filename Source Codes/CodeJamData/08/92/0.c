#include<stdio.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int main(){
  int i,j,k,l,m,n;
  int size,count=0;

  int x,y;
  int mp[100][100];
  int dx[2], dy[2];
  int sx[10000], sy[10000], st_size;
  int res;
  int s,t,tmp;
  int nx,ny;
  
  scanf("%d",&size);
  while(size--){
//    fprintf(stderr,"rest input = %d\n",size);

    scanf("%d%d",&x,&y);
    scanf("%d%d%d%d",dx,dy,dx+1,dy+1);
    res=0;

    scanf("%d%d",&s,&t);
    
    rep(i,x) rep(j,y) mp[i][j]=0;
    mp[s][t]=1;
    sx[0]=s; sy[0]=t; st_size=1; tmp=1;
    while(st_size){
      i=sx[--st_size]; j=sy[st_size];
      rep(k,2){
        nx=i+dx[k]; ny=j+dy[k];
        if(nx<0 || ny<0 || nx>=x || ny>=y) continue;
        if(mp[nx][ny]) continue;
        tmp++;
        mp[nx][ny]=1; sx[st_size]=nx; sy[st_size++]=ny;
      }
    }
    if( tmp > res ) res = tmp;

    printf("Case #%d: %d\n",++count,res);
  }

  return 0;
}
