#include <iostream>
#include <vector>
#include <set>

using namespace std;

long long answer();

int main(){
  int t;
  cin>>t;
  for(int i=1;i<=t;i++){
    cout<<"Case #"<<i<<": "<<answer()<<'\n';
  }
}

const int locations=4,dirs=4;
const long long infinity=999999999999999LL;

int dr[dirs][locations]={{0,-1,-1,0}, {0,0,0,0}, {1,0,0,1}, {0,0,0,0}};
int dc[dirs][locations]={{0,0,0,0}, {0,0,1,1}, {0,0,0,0}, {-1,-1,0,0}};
int nll[dirs][locations]={{1,0,3,2}, {3,2,1,0}, {1,0,3,2}, {3,2,1,0}};
int dt[dirs][locations]={{1,2,2,1}, {1,1,2,2}, {2,1,1,2}, {2,2,1,1}};
int wtt[dirs][locations]={{1,0,0,1}, {2,2,0,0}, {0,1,1,0}, {0,0,2,2}};

int R,C;
vector<vector<int> > S,W,T;

long long dykstra(int sr,int sc,int sl,int er,int ec,int el);

long long answer(){
  cin>>R>>C;
  S=W=T=vector<vector<int> >(R,vector<int>(C));
  for(int r=0;r<R;r++)
    for(int c=0;c<C;c++){
      cin>>S[r][c]>>W[r][c]>>T[r][c];
      T[r][c]%=S[r][c]+W[r][c];
    }
  return dykstra(R-1,0,0,0,C-1,2);
}

bool good(int r,int c){
  return r>=0 && c>=0 && r<R && c<C;
}

long long wait(int r,int c,int wt,long long t);

long long dykstra(int sr,int sc,int sl,int er,int ec,int el){
  vector<vector<vector<long long> > > dist(R,vector<vector<long long> >(C,vector<long long>(4,infinity)));
  dist[sr][sc][sl]=0;
  set<pair<pair<long long,int>,pair<int,int> > > q;
  q.insert(make_pair(make_pair(0LL,sl),make_pair(sr,sc)));
  while(q.size()){
    long long t=q.begin()->first.first;
    int r=q.begin()->second.first,c=q.begin()->second.second,l=q.begin()->first.second;
    q.erase(q.begin());
    if(dist[r][c][l]!=t)
      continue;
    if(r==er && c==ec && l==el)
      return t;

    for(int d=0;d<dirs;d++){
      int nr=r+dr[d][l],nc=c+dc[d][l],nl=nll[d][l];
      if(!good(nr,nc))
        continue;
      int wt=wtt[d][l];
      assert(wt==0 || (r==nr && c==nc));
      long long nt=t+dt[d][l]+wait(r,c,wt,t);
      if(nt<dist[nr][nc][nl]){
        dist[nr][nc][nl]=nt;
        q.insert(make_pair(make_pair(nt,nl),make_pair(nr,nc)));
      }
    }
  }
  assert(false);
}

long long wait(int r,int c,int wt,long long t){
  if(wt==0)
    return 0;
  int now=t%(S[r][c]+W[r][c]);
  if(now<T[r][c])
    now+=S[r][c]+W[r][c];
  int d=now-T[r][c];
  if(wt==1){
    if(d<S[r][c])
      return 0;
    return W[r][c]+S[r][c]-d;
  }
  assert(wt==2);
  if(d<S[r][c])
    return S[r][c]-d;
  return 0;
}
