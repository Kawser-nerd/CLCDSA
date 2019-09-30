#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<numeric>
#include<map>
#include<set>
#include<cstdlib>
#include<string>
#include<cassert>
#include<iostream>
using namespace std;
typedef vector<int> vi;
typedef long long int64;
#define FOR(i,n)for(int i=0;i<(int)(n);i++)
int n,l[1010],p[1010],t[1010];
bool cmp(int x,int y){
  if(l[x]*100+l[y]*(100-p[x])!=l[y]*100+l[x]*(100-p[y]))return l[x]*100+l[y]*(100-p[x])<l[y]*100+l[x]*(100-p[y]);
  return x<y;
}
void solve(){
  scanf("%d",&n);
  FOR(i,n)scanf("%d",&l[i]);
  FOR(i,n)scanf("%d",&p[i]);
  FOR(i,n)t[i]=i;
  sort(t,t+n,cmp);
  for(int i=0;i<n;i++)printf(" %d",t[i]);
  printf("\n");
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
    fprintf(stderr,"processing case %d\n",tt);
    printf("Case #%d:",tt);
    solve();
    fflush(stdout);
  }
  freopen(out,"r",stdin);
  char c;while((c=getc(stdin))!=EOF)putc(c,stderr);
}

