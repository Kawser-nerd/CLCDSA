#include<cstdio>
#include<algorithm>
#include<vector>
#include<numeric>
#include<map>
#include<set>
#include<cstdlib>
#include<string>
using namespace std;
void solve(){
  int n,cnt[110]={};
  char t[110][110];
  scanf("%d",&n);
  for(int i=0;i<n;i++)scanf(" %s",t[i]);
  double wp[110]={},owp[110]={},oowp[110]={};
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++)if(t[i][j]!='.')++cnt[i],wp[i]+=t[i][j]=='1';
    wp[i]/=cnt[i];
   
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++)if(t[i][j]!='.'){
      int tmp_cnt=0;
      double tmp_wp=0.0;
      for(int k=0;k<n;k++)if(k!=i&&t[j][k]!='.')++tmp_cnt,tmp_wp+=t[j][k]=='1';
      tmp_wp/=tmp_cnt;
      owp[i]+=tmp_wp;
    }
    owp[i]/=cnt[i];
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++)if(t[i][j]!='.')oowp[i]+=owp[j];
    oowp[i]/=cnt[i]; 
  }
  for(int i=0;i<n;i++)printf("%.8lf\n",wp[i]/4+owp[i]/2+oowp[i]/4);
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
    printf("Case #%d:\n",tt);
    solve();
    fflush(stdout);
  }
}
