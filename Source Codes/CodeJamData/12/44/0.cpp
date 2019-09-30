#include<cstdio>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<algorithm>
#include<string>
#include<utility>
#include<iostream>
using namespace std;

#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define VS vector<string> 

int X, Y, XY;

set<VS> reached;
stack<VS> st;

int con[500][500];

void solve(VS in, int d){
  int i,j,k;
  int ij, cnt;
  int id, ok, las;
  int dx[3] = { 0, 0, 1};
  int dy[3] = {-1, 1, 0};
  int ni, nj;
  VS next, send;

  rep(i,XY) rep(j,XY) con[i][j] = 0;
  rep(i,XY) con[i][i] = 1;
  rep(i,X) rep(j,Y) if(in[i][j]!='#'){
    ij = i*Y+j;
    if(in[i+1][j]!='#') con[ij][ij+Y] = 1;
    if(in[i][j-1]!='#') con[ij][ij-1] = 1;
    if(in[i][j+1]!='#') con[ij][ij+1] = 1;
  }

  rep(k,XY) rep(i,XY) rep(j,XY) con[i][j] |= (con[i][k]&con[k][j]);

  rep(i,X) rep(j,Y){
    if(in[i][j] == '0'+d) id = i*Y + j;
    if('0' <= in[i][j] && in[i][j] <= '9') in[i][j] = '.';
  }

  cnt = 0;
  rep(i,X) rep(j,Y) if(con[i*Y+j][id]) in[i][j] = 'o', cnt++;
  printf("%d: %d ",d,cnt);

  reached.clear();
  while(st.size()) st.pop();

  reached.insert(in);
  st.push(in);

  ok = 0;
  while(st.size()){
    in = st.top(); st.pop();
    next = in;

    cnt = 0;
    rep(i,X) rep(j,Y) if(next[i][j]=='o'){
      next[i][j] = '.';
      cnt++; las = i*Y+j;
      if(i > id/Y){ cnt=-10000; break; }
    }
    if(cnt<0) continue;
    if(cnt==1 && las==id){ ok=1; break; }

    rep(k,3){
      send = next;
      rep(i,X) rep(j,Y) if(in[i][j]=='o'){
        ni = i + dx[k];
        nj = j + dy[k];
        if(in[ni][nj]=='#') ni=i, nj=j;
        send[ni][nj]='o';
      }
      if(reached.count(send)) continue;
      reached.insert(send);
      st.push(send);
    }
  }

  if(ok) puts("Lucky"); else puts("Unlucky");
}

int main(){
  int i,j,k,l,m,n;
  VS in;
  string str_tmp;
  int size, count = 0;

  scanf("%d",&size);
  while(size--){
    fprintf(stderr,"rest %d\n",size);
    
    printf("Case #%d:\n",++count);
    in.clear();
    scanf("%d%d",&X,&Y); XY = X*Y;
    rep(i,X){
      cin >> str_tmp;
      in.push_back(str_tmp);
    }

    rep(k,10){
      rep(i,X) rep(j,Y) if(in[i][j]=='0'+k) solve(in,k);
    }
  }

  return 0;
}
