#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int n;
int edge[510][510], es[510];
int edge_mat[510][510];

int dist[500];

int q[500], q_st, q_size;

int now[510], chk[510];
int best;

void solve(int node){
  int i,j,k;

  now[dist[node]] = node;
  if(node==1){
    rep(i,n) chk[i] = 0;
    rep(i,dist[node]) rep(j,es[now[i]]) chk[ edge[now[i]][j] ] = 1;
    k = 0;
    rep(i,n) k += chk[i];
    k -= dist[node] - 1;
    if(dist[node]>1) k--;
    if(best < k) best = k;
    return;
  }

  rep(i,es[node]){
    k = edge[node][i];
    if(dist[node]+1 != dist[k]) continue;

    solve(k);
  }
}

int main(){
  int i,j,k,l,m;
  int size, count = 0;

  scanf("%d",&size);
  while(size--){
    scanf("%d%d",&n,&m);

    rep(i,n) es[i] = 0;
    while(m--){
      scanf(" %d,%d ",&i,&j);
      edge[i][es[i]++] = j;
      edge[j][es[j]++] = i;
    }

    rep(i,n) rep(j,n) edge_mat[i][j]=0;
    rep(i,n) rep(j,es[i]) edge_mat[i][edge[i][j]] = 1;

    rep(i,n) dist[i] = -1; dist[0] = 0;
    q_size = 1; q_st = 0; q[0] = 0;
    while(q_size){
      i = q[q_st++]; q_size--;
      rep(j,es[i]){
        k = edge[i][j];
        if(dist[k] >= 0) continue;
        dist[k] = dist[i] + 1;
        q[q_st+q_size++] = k;
      }
    }

    best = 0;
    solve(0);
    k = best;

    printf("Case #%d: %d %d\n",++count,dist[1]-1,k);
  }

  return 0;
}
