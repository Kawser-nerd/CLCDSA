#include<stdio.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int mp[600][600];
int dx[4]={-1,0,1,0}, dy[4]={0,1,0,-1};

int st_x[1000000],st_y[1000000],st_size;

void nul(int a,int b){
  int i,j,k;
  int ni,nj;

  st_size=1; st_x[0]=a; st_y[0]=b; mp[a][b]=2;
  while(st_size){
    i=st_x[st_size-1]; j=st_y[st_size-1]; st_size--;
    rep(k,4){
      ni=i+dx[k]; nj=j+dy[k];
      if(ni<0||nj<0||ni>=600||nj>=600) continue;
      if(mp[ni][nj]) continue;
      mp[ni][nj]=2;
      st_x[st_size]=ni; st_y[st_size]=nj; st_size++;
    }
  }
}

int chk(int a,int b){
  int i,j;

  i=j=b;
  while(i>=0){
    if(mp[a][i]==1) break;
    i--;
  }
  while(j<600){
    if(mp[a][j]==1) break;
    j++;
  }
  if(i>=0 && j<600) return 1;
  
  i=j=a;
  while(i>=0){
    if(mp[i][b]==1) break;
    i--;
  }
  while(j<600){
    if(mp[j][b]==1) break;
    j++;
  }
  if(i>=0 && j<600) return 1;
  
  return 0;
}

int main(){
  int i,j,k,l,m,n,q,s,len,res;
  int size,count=0;

  char in[10000];

  int nx,ny,nd;

  scanf("%d",&size);
  while(size--){
    rep(i,600) rep(j,600) mp[i][j]=0;
    nx=ny=300; nd=0; res=0;

    scanf("%d",&q);
    while(q--){
      scanf("%s%d",in,&s);
      for(i=0;;i++) if(in[i]<' ') break; len=i;
      while(s--){
        rep(i,len){
          if(in[i]=='R') nd=(nd+1)%4;
          if(in[i]=='L') nd=(nd+3)%4;
          if(in[i]=='F'){
            nx += dx[nd]; ny += dy[nd]; mp[nx][ny]=1;
            nx += dx[nd]; ny += dy[nd]; mp[nx][ny]=1;
          }
        }
      }
    }
    nul(0,0);
//    rep(i,20) { rep(j,20) printf("%d",mp[290+i][295+j]); puts("");}
    for(i=1;i<600;i+=2) for(j=1;j<600;j+=2) if(mp[i][j]==2) {
      res += chk(i,j);
    }

    printf("Case #%d: %d\n",++count,res);
  }

  return 0;
}
