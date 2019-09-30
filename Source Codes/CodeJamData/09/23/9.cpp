#include<iostream>
#include<string>
#include<vector>
#include<cstring>
#include<queue>
#include<locale>
using namespace std;

const int dr[]={-1,0,1,0};
const int dc[]={0,-1,0,1};
const int imax=0x3f3f3f3f;
const int vmax=700;
const int voff=100;

vector<string> board;
int sz;

int best[20][20][700];
struct state { int r,c,val; };
state prev[20][20][700];

bool better(state s,state nxt)
{
  while(1)
  {
    if(board[s.r][s.c]!=board[nxt.r][nxt.c])
      return board[s.r][s.c]<board[nxt.r][nxt.c];
    if(best[s.r][s.c][s.val+voff]==1) break;
    s=prev[s.r][s.c][s.val+voff];
    nxt=prev[nxt.r][nxt.c][nxt.val+voff];
  }
  return false;
}

string bfs(int target)
{
  queue<state> q;
  int r,c,v;
  memset(best,0x3f,sizeof(best));
  for(r=0;r<sz;++r) for(c=0;c<sz;++c) if(isdigit(board[r][c]))
  { state s={r,c,board[r][c]-'0'};
    best[r][c][board[r][c]-'0'+voff]=1;
    prev[r][c][s.val+voff].val=0;
    q.push(s);
  }
  state s;
  state final={-1,-1,-1};
  while(!q.empty())
  { s=q.front(); q.pop();
    if(isdigit(board[s.r][s.c])&&s.val==target) 
    { if(final.r<0) { final=s; continue; }
      if(better(s,final)) { final=s; continue; }
    }
    if(final.r>=0 
        && best[final.r][final.c][final.val+voff]<best[s.r][s.c][s.val+voff])
      break;
    for(int i=0;i<4;++i)
    { int nr=s.r+dr[i], nc=s.c+dc[i];
      if(nr<0||nc<0||nc>=sz||nr>=sz) continue;
      state nxt={nr,nc,s.val};
      if(board[nr][nc]=='-') nxt.val-=(board[s.r][s.c]-'0')*2;
      else if(isdigit(board[nr][nc])) nxt.val+=board[nr][nc]-'0';
      if(nxt.val+voff<0||nxt.val+voff>=vmax) continue;
      if(best[nxt.r][nxt.c][nxt.val+voff]>best[s.r][s.c][s.val+voff]+1
          || (best[nxt.r][nxt.c][nxt.val+voff]==best[s.r][s.c][s.val+voff]+1 &&
            better(s,prev[nxt.r][nxt.c][nxt.val+voff])))
      { best[nxt.r][nxt.c][nxt.val+voff]=best[s.r][s.c][s.val+voff]+1;
        prev[nxt.r][nxt.c][nxt.val+voff]=s;
        q.push(nxt);
      }
    }
  }

  s=final;
  string rv;
  while(1)
  { rv+=board[s.r][s.c];
    if(best[s.r][s.c][s.val+voff]==1) break;
    s=prev[s.r][s.c][s.val+voff];
  }
  return rv;
}

int main()
{
  int ci,cn;
  cin>>cn;
  for(ci=1;ci<=cn;++ci)
  {
    int qn,i;
    cin>>sz>>qn;
    board.resize(sz);
    for(i=0;i<sz;++i) cin>>board[i];
    cout<<"Case #"<<ci<<':'<<endl;
    for(i=0;i<qn;++i)
    { int t;
      cin>>t;
      cout<<bfs(t)<<endl;
    }
    cerr<<"done with case "<<ci<<endl;
  }
}
