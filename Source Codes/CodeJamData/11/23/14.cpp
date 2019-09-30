#include<cassert>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<numeric>
#include<map>
#include<set>
#include<cstdlib>
#include<string>
#include<deque>
using namespace std;
int n,m,x[2010],y[2010],cnt,r[2010],maks;
vector<int> s[2010],nbr[2010];
deque<int> b[2010];
typedef pair<int,int> p2;
map<p2,int> nr;
void repair(vector<int> &t){
  bool used[2010]={};
  for(int i=0;i<t.size();i++)if(t[i]>-1)used[t[i]]=true;
  int next=1;
  for(int i=0;i<maks;i++)if(t[i]==-1){
    while(used[next])next++;
    used[next]=true;
    t[i]=next;
  }
  for(int i=maks;i+1<t.size();i++)t[i]=t[i-2];
  if(t.size()>maks)t[t.size()-1]=1;
  while(t[0]==t[t.size()-1]||t[t.size()-2]==t[t.size()-1])++t[t.size()-1];
  memset(used,0,sizeof(used));
  for(int i=0;i<t.size();i++)used[t[i]]=true;
  for(int i=1;i<=maks;i++)assert(used[i]);
}
void color(int x,int y=-1){
  if(y==-1){
    r[b[x][0]]=1;
    r[b[x][1]]=2;
  }
  while(r[b[x].front()]==-1){
    b[x].push_back(b[x].front());
    b[x].pop_front();
  }
  if(r[b[x][1]]==-1)reverse(b[x].begin()+1,b[x].end());
  vector<int> t;
  for(int i=0;i<b[x].size();i++)t.push_back(r[b[x][i]]);
  //for(int i=0;i<b[x].size();i++)printf("%d,%d ",t[i],b[x][i]);puts("");
  assert(r[b[x][0]]>-1);
  assert(r[b[x][1]]>-1);
  assert(r[b[x][0]]!=r[b[x][1]]);
  repair(t);
  //for(int i=0;i<b[x].size();i++)printf("%d,%d ",t[i],b[x][i]);puts("");
  for(int i=0;i<b[x].size();i++)r[b[x][i]]=t[i];
  for(int i=0;i<nbr[x].size();i++)if(nbr[x][i]!=y)color(nbr[x][i],x);
}
void solve(){
  scanf("%d %d",&n,&m);
  for(int i=1;i<=n;i++)s[i].clear();
  for(int i=0;i<m;i++)scanf("%d",&x[i]);
  for(int i=0;i<m;i++)scanf("%d",&y[i]);
  for(int i=0;i<m;i++){
    s[x[i]].push_back(y[i]);
    s[y[i]].push_back(x[i]);
  }
  for(int i=1;i<=n;i++){
    int x=i,y=i<n?i+1:1;
    s[x].push_back(y);
    s[y].push_back(x);
  }
  for(int i=1;i<=n;i++)sort(s[i].begin(),s[i].end());
  cnt=0;
  nr.clear();
  for(int i=1;i<=n;i++)for(int j=0;j<s[i].size();j++)if(nr.find(p2(i,s[i][j]))==nr.end()){
    int x=i,y=s[i][j];
    b[cnt].clear();
    while(nr.find(p2(x,y))==nr.end()){
      b[cnt].push_back(x);
      nr[p2(x,y)]=cnt;
      int pos=0;
      while(s[y][pos]!=x)pos++;
      int z=s[y][(pos+1)%s[y].size()];
      x=y;
      y=z;
    }
    ++cnt;
  }
  /*printf("cnt=%d\n",cnt);
  for(int i=0;i<cnt;i++){
    for(int j=0;j<b[i].size();j++)printf("%d ",b[i][j]);
    puts("");
  }puts("");*/
  maks=2010;
  for(int i=0;i<cnt;i++)if(b[i].size()<n)maks=min(maks,(int)b[i].size());
  for(int i=0;i<cnt;i++)nbr[i].clear();
  for(int i=0;i<m;i++){
    int a=nr[p2(x[i],y[i])],b=nr[p2(y[i],x[i])];
    nbr[a].push_back(b);
    nbr[b].push_back(a);
  }
  memset(r,-1,sizeof(r));
  for(int i=0;i<cnt;i++)if(b[i].size()==maks){
    color(i);
    break;
  }
  printf("%d\n",maks);
  for(int i=0;i<n;i++)printf("%d%c",r[i+1],i+1<n?' ':'\n');
}
main(){
  char in[100],out[100],*pos;
  strcpy(in,__FILE__);
  strcpy(out,__FILE__);
  pos=in;
  while(*pos!='.')pos++;
  strcpy(pos,".in");
  pos=out;
  while(*pos!='.')pos++;
  strcpy(pos,".out");
  freopen(in,"r",stdin);
  freopen(out,"w",stdout);
  int t;
  scanf("%d",&t);
  for(int tt=1;tt<=t;tt++){
    printf("Case #%d: ",tt);
    solve();
    fflush(stdout);
  }
}
