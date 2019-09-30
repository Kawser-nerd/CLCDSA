#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
#include<stack>
#include<sstream>
#include<ctime>
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define VI vector<int>
#define PQ priority_queue
#define pii pair<int,int>
#define pdd pair<double,double>
#define ll long long
using namespace std;
struct node
{
  VI neigh;
  string name;
  int pred;
};
node make_node(VI u,string nm,int pr)
{
  node w;
  w.neigh=u;
  w.name=nm;
  w.pred=pr;
  return w;
}
vector<node> A;
int N,M;
string B[128],E[128];
void read()
{
  int i;
  cin>>N>>M;
  for(i=0;i<N;++i)cin>>B[i];
  for(i=0;i<M;++i)cin>>E[i];
}
string crop(string e,int pos)
{
  int i;
  string ret;
  for(i=pos;i<e.length();++i)ret.pb(e[i]);
  return ret;
}
void create_tree()
{
  int i,j,k,l;
  VI emp;
  A.pb(make_node(emp,"samolevskishampion",-1));
  for(i=0;i<N;++i)
  {
    B[i]=crop(B[i],1);
    int cr=0;
    //cout<<i<<":\n";
    while(B[i].size())
    {
      //cout<<B[i]<<'\n';
      string d;
      for(j=0;j<B[i].size();++j)
      {
        for(k=j;k<B[i].size();++k)
        {
          if(B[i][k]=='/')goto skip;
          d.pb(B[i][k]);
        }
        if(k==B[i].size())break;
      }
      skip:
      for(l=0;l<A[cr].neigh.size();++l)
        if(A[A[cr].neigh[l]].name==d)
        {
          cr=A[cr].neigh[l];
          goto end;
        }
      int fd=A.size();
      A.pb(make_node(emp,d,cr));
      A[cr].neigh.pb(fd);
      cr=fd;
      end:
      B[i]=crop(B[i],k+1);
    }
  }
  /*for(i=0;i<A.size();++i)
  {
    cout<<A[i].name<<": ";
    for(j=0;j<A[i].neigh.size();++j)cout<<A[i].neigh[j]<<' ';
    cout<<'\n';
  }*/
}
void solve()
{
  int i,j,k,l;
  int ans=0;
  VI emp;
  for(i=0;i<M;++i)
  {
    E[i]=crop(E[i],1);
    int cr=0;
    while(E[i].size())
    {
      string d;
      for(j=0;j<E[i].size();++j)
      {
        for(k=j;k<E[i].size();++k)
        {
          if(E[i][k]=='/')goto skip;
          d.pb(E[i][k]);
        }
        if(k==E[i].size())break;
      }
      skip:
      for(l=0;l<A[cr].neigh.size();++l)
        if(A[A[cr].neigh[l]].name==d)
        {
          cr=A[cr].neigh[l];
          goto end;
        }
      int fd=A.size();
      A.pb(make_node(emp,d,cr));
      A[cr].neigh.pb(fd);
      cr=fd;
      ++ans;
      end:
      E[i]=crop(E[i],k+1);
    }
  }
  printf("%d\n",ans);
}
int main()
{
  int tc,T;
  cin>>T;
  for(tc=1;tc<=T;++tc)
  {
    A.clear();
    printf("Case #%d: ",tc);
    read();
    create_tree();
    solve();
  }
  return 0;
}