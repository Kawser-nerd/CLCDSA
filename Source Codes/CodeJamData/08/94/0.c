#include<stdio.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

char mp[100][100];

int main(){
  int i,j,k,l,m,n;
  int size,count=0;

  int x,y;
  int back_x[30][30], back_y[30][30];
  int dist[30][30], cost[30][30];
  int dame[30][30];

  int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};
  int sx,sy, nx,ny;
  int qx[10000], qy[10000], q_st, q_size;

  int res;
  int ex,ey,tmp;

  scanf("%d",&size);
  while(size--){
    fprintf(stderr,"rest input = %d\n",size);

    scanf("%d%d",&x,&y);
    rep(i,x) scanf("%s",mp[i]);

    n=0;
    rep(i,x) rep(j,y) if(mp[i][j]=='T') n++;

    rep(i,x) rep(j,y) dist[i][j]=-1;
    dist[0][0]=0;

    q_st=0; q_size=1; qx[0]=qy[0]=0;
    while(q_size){
      sx=qx[q_st]; sy=qy[q_st]; q_st++; q_size--;
      rep(k,4){
        nx = sx+dx[k]; ny=sy+dy[k];
        if(nx<0 || ny<0 || nx>=x || ny>=y) continue;
        if(dist[nx][ny]>=0) continue;
        if(mp[nx][ny]=='.') continue;

        dist[nx][ny]=dist[sx][sy]+1;
        back_x[nx][ny]=sx; back_y[nx][ny]=sy;
        qx[q_st+q_size]=nx; qy[q_st+q_size++]=ny;
      }
    }

    rep(i,x) rep(j,y) cost[i][j]=dist[i][j];

    if(n==2){
      rep(i,x) rep(j,y) if(x||y) if(mp[i][j]=='T') ex=sx=i, ey=sy=j;
      rep(i,x) rep(j,y) dame[i][j]=0;
      while(sx || sy){
        dame[sx][sy]=1;
        nx=back_x[sx][sy]; ny=back_y[sx][sy];
        sx=nx; sy=ny;
      }

      rep(i,x) rep(j,y) dist[i][j]=-1;
      dist[ex][ey]=0;

      q_st=0; q_size=1; qx[0]=ex; qy[0]=ey;
      while(q_size){
        sx=qx[q_st]; sy=qy[q_st]; q_st++; q_size--;
        rep(k,4){
          nx = sx+dx[k]; ny=sy+dy[k];
          if(nx<0 || ny<0 || nx>=x || ny>=y) continue;
          if(dist[nx][ny]>=0) continue;
          if(mp[nx][ny]=='.') continue;
          
          dist[nx][ny]=dist[sx][sy]+1;
          back_x[nx][ny]=sx; back_y[nx][ny]=sy;
          qx[q_st+q_size]=nx; qy[q_st+q_size++]=ny;
        }
      }

      rep(i,x) rep(j,y) if(dame[i][j]==0 && dist[i][j] < cost[i][j]) cost[i][j] = dist[i][j];
    }

    res=0;
    rep(i,x) rep(j,y) if(cost[i][j]>=0) res += cost[i][j];
    printf("Case #%d: %d\n",++count,res);
  }

  return 0;
}
