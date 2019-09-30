#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

void unionInit(int d[],int s){int i;rep(i,s)d[i]=i;}
int unionGet(int d[],int n){int t=n,k;while(d[t]!=t)t=d[t];while(d[n]!=n)k=d[n],d[n]=t,n=k;return n;}
int unionConnect(int d[],int a,int b){a=unionGet(d,a);b=unionGet(d,b);if(a==b)return 0;d[a]=b;return 1;}

int ind[36100000];
char mp[36100000];

int S;
int s, n;
int x[20000], y[20000];

int EDGE[6], CORNER[6], NODE;

int dx[6] = {1, 0, -1, -1,  0, 1};
int dy[6] = {1, 1,  0, -1, -1, 0};

int is_in(int xx, int yy){
  if(xx < 1 || xx >= 2*s) return 0;
  if(yy < 1 || yy >= 2*s) return 0;
  if(xx - yy >= s || yy - xx >= s) return 0;
  return 1;
}

void unionIII(int fg){
  int i, j, k;

  if(fg){
  rep(k,s-2){
    i = 2+k; j=1;
    unionConnect(ind, i*S+j, EDGE[0]);
    i = 1; j=2+k;
    unionConnect(ind, i*S+j, EDGE[1]);
    i = s+1+k; j=2+k;
    unionConnect(ind, i*S+j, EDGE[2]);
    i = 2+k; j=s+1+k;
    unionConnect(ind, i*S+j, EDGE[3]);
    i = 2*s-1; j=s+1+k;
    unionConnect(ind, i*S+j, EDGE[4]);
    i = s+1+k; j=2*s-1;
    unionConnect(ind, i*S+j, EDGE[5]);
  }}

  i = 1; j = 1;
  unionConnect(ind, i*S+j, CORNER[0]);
  i = s; j = 1;
  unionConnect(ind, i*S+j, CORNER[1]);
  i = 1; j = s;
  unionConnect(ind, i*S+j, CORNER[2]);
  i = 2*s-1; j = s;
  unionConnect(ind, i*S+j, CORNER[3]);
  i = s; j = 2*s-1;
  unionConnect(ind, i*S+j, CORNER[4]);
  i = 2*s-1; j = 2*s-1;
  unionConnect(ind, i*S+j, CORNER[5]);
}


int new_ring[12000], new_ring_size;
int last_ring_i, last_ring_j;

int search_ring(void){
  int i, j, k;
  int a, b[6], c[6];
  
  if(last_ring_i >= 2*s) return 0;
  
  rep(k,6) b[k] = unionGet(ind, EDGE[k]);
  rep(k,6) c[k] = unionGet(ind, CORNER[k]);

  i = last_ring_i;
  REP(j,last_ring_j,2*s) if(is_in(i,j)) if(mp[i*S+j]==0){
    a = unionGet(ind,i*S+j);
    if(a != b[0] && a != b[1] && a != b[2] && a != b[3] && a != b[4] && a != b[5] && a != c[0] && a != c[1] && a != c[2] && a != c[3] && a != c[4] && a != c[5]){
      last_ring_i = i; last_ring_j = j;
      return 1;
    }
  }
  
  REP(i,last_ring_i+1,2*s) rep(j,2*s) if(is_in(i,j)) if(mp[i*S+j]==0){
    a = unionGet(ind,i*S+j);
    if(a != b[0] && a != b[1] && a != b[2] && a != b[3] && a != b[4] && a != b[5] && a != c[0] && a != c[1] && a != c[2] && a != c[3] && a != c[4] && a != c[5]){
      last_ring_i = i; last_ring_j = j;
      return 1;
    }
  }

  last_ring_i = 2*s;
  return 0;
}

int is_ring(int i, int j){
  int a, b[6], c[6], k;
  if(is_in(i,j)==0) return 0;
  a = unionGet(ind,i*S+j);
  rep(k,6) b[k] = unionGet(ind,EDGE[k]);
  rep(k,6) c[k] = unionGet(ind,CORNER[k]);
  if(a != b[0] && a != b[1] && a != b[2] && a != b[3] && a != b[4] && a != b[5] && a != c[0] && a != c[1] && a != c[2] && a != c[3] && a != c[4] && a != c[5]) return 1;
  return 0;
}


int eddd[6][100000], eddd_sz[6];
int eded[36100000];
void intSort(int d[],int s){int i=-1,j=s,k,t;if(s<=1)return;k=(d[0]+d[s-1])/2;for(;;){while(d[++i]<k);while(d[--j]>k);if(i>=j)break;t=d[i];d[i]=d[j];d[j]=t;}intSort(d,i);intSort(d+j+1,s-j-1);}

int ok[1111];

int main(){
  int i,j,k,l,m;
  int ni, nj;
  int a, b, c, d;
  int size, count = 0;
  int ring, bridge, fork;

  rep(i,1111){
    ok[i] = 0;
    k = 0;
    rep(j,6) if(i&1<<j) k++;
    if(k >= 3) ok[i] = 1;
  }

  scanf("%d",&size);
  while(size--){
    fprintf(stderr, "\nsize %d\n", size);
    
    ring = bridge = fork = 100000;
    scanf("%d%d",&s,&n); S = 2*s;
    rep(i,n) scanf("%d%d",x+i,y+i);

    NODE = S*S;
    rep(i,6) EDGE[i] = NODE++;
    rep(i,6) CORNER[i] = NODE++;
    unionInit(ind, NODE);
    unionIII(0);
    
    rep(i,S*S) mp[i] = 0;
    rep(k,n){
      i = x[k]; j = y[k];
      mp[i*S + j] = 1;
      rep(d,6){
        ni = i + dx[d];
        nj = j + dy[d];
        if(is_in(ni,nj)==0) continue;
        if(mp[ni*S+nj]==0) continue;
        unionConnect(ind, i*S+j, ni*S+nj);
      }

      if(bridge == 100000){
        m = 0;
        rep(d,6) if(unionGet(ind,i*S+j)==unionGet(ind,CORNER[d])) m++;
        if(m >= 2) bridge = k;
      }
      
      if(fork == 100000){
        rep(i,6) eddd_sz[i] = 0;
        rep(m,s-2){
          i = 2+m; j=1;
          if(mp[i*S+j]) eddd[0][eddd_sz[0]++] = unionGet(ind, i*S+j);
          i = 1; j=2+m;
          if(mp[i*S+j]) eddd[1][eddd_sz[1]++] = unionGet(ind, i*S+j);
          i = s+1+m; j=2+m;
          if(mp[i*S+j]) eddd[2][eddd_sz[2]++] = unionGet(ind, i*S+j);
          i = 2+m; j=s+1+m;
          if(mp[i*S+j]) eddd[3][eddd_sz[3]++] = unionGet(ind, i*S+j);
          i = 2*s-1; j=s+1+m;
          if(mp[i*S+j]) eddd[4][eddd_sz[4]++] = unionGet(ind, i*S+j);
          i = s+1+m; j=2*s-1;
          if(mp[i*S+j]) eddd[5][eddd_sz[5]++] = unionGet(ind, i*S+j);
        }
        rep(i,6) rep(j,eddd_sz[i]) eded[eddd[i][j]] = 0;
        rep(i,6) rep(j,eddd_sz[i]){
          eded[eddd[i][j]] |= (1<<i);
          if(ok[ eded[eddd[i][j]] ]) fork = k;
        }

/*        rep(i,eddd_sz) printf("%d ",eddd[i]); puts("");*/
/*        REP(m,2,eddd_sz) if(eddd[m]==eddd[m-2]) fork = k;*/
      }
    }
    
    unionInit(ind, NODE);
    unionIII(1);
    rep(i,S*S) mp[i] = 0;
    rep(i,n) mp[x[i]*S + y[i]] = 1;
    rep(i,S) rep(j,S) if(is_in(i,j)) rep(k,6){
      ni = i + dx[k];
      nj = j + dy[k];
      if(!is_in(ni,nj)) continue;
      if(mp[i*S+j]==0 && mp[ni*S+nj]==0) unionConnect(ind, i*S+j, ni*S+nj);
    }

    last_ring_i = last_ring_j = 0;
    new_ring_size = 0;
    a = search_ring();
    if(a) ring = n-1;
    for(k=n-1;k>=0;k--){
      i = x[k]; j = y[k];
      mp[i*S+j] = 0;
      rep(d,6){
        ni = i + dx[d];
        nj = j + dy[d];
        if(is_in(ni,nj)==0) continue;
        if(mp[ni*S+nj]==1) continue;
        unionConnect(ind, i*S+j, ni*S+nj);
      }

      c = 0;
      rep(a,new_ring_size){
        if(is_ring(new_ring[a]/S, new_ring[a]%S)){
          new_ring[c++] = new_ring[a];
        }
      }
      new_ring_size = c;
      
      if(is_ring(i,j)){
        new_ring[new_ring_size++] = i*S+j;
      }

      if(new_ring_size){ ring = k-1; continue; }

      a = search_ring();
      if(a) ring = k-1;
    }

    k = ring;
    if(k > bridge) k = bridge;
    if(k > fork) k = fork;

/*    printf("ring %d / bridge %d / fork %d\n",ring,bridge,fork);*/

    printf("Case #%d: ",++count);
    if(k==100000){ puts("none"); continue; }
    if(bridge==k && fork==k && ring==k){ printf("bridge-fork-ring in move %d\n", k+1); continue; }
    if(fork==k && ring==k){ printf("fork-ring in move %d\n", k+1); continue; }
    if(bridge==k && ring==k){ printf("bridge-ring in move %d\n", k+1); continue; }
    if(bridge==k && fork==k){ printf("bridge-fork in move %d\n", k+1); continue; }
    if(ring==k){ printf("ring in move %d\n", k+1); continue; }
    if(fork==k){ printf("fork in move %d\n", k+1); continue; }
    if(bridge==k){ printf("bridge in move %d\n", k+1); continue; }
    puts("ERROR"); break;
  }

  return 0;
}
