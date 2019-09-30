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
int k;
char s[5010];
char leet(char c){
switch(c){
case 'o':return '0';
case 'i':return '1';
case 'e':return '3';
case 'a':return '4';
case 's':return '5';
case 't':return '7';
case 'b':return '8';
case 'g':return '9';
default:return c;
}
}
bool seen[256][256],b[256],any;
int diff[256],balance,cnt;
void dfs(int x){
  b[x]=true;
  FOR(y,256)any|=seen[x][y]||seen[y][x];
  FOR(y,256)if(!b[y]&&(seen[x][y]||seen[y][x]))dfs(y);
  if(diff[x]>0)balance+=diff[x];
}
void solve(){
  scanf("%d %s",&k,&s);
  assert(k==2);
  memset(seen,0,sizeof(seen));
  FOR(i,strlen(s)-1)seen[s[i]][s[i+1]]=seen[s[i]][leet(s[i+1])]=seen[leet(s[i])][s[i+1]]=seen[leet(s[i])][leet(s[i+1])]=true;
  memset(b,0,sizeof(b));
  int edges=0,add=0;
  FOR(i,256)FOR(j,256)edges+=seen[i][j];
  memset(diff,0,sizeof(diff));
  FOR(i,256)FOR(j,256)if(seen[i][j])diff[i]++,diff[j]--;
  FOR(i,256)if(!b[i]){
    balance=0;
    any=false;
    dfs(i);
    if(!any)continue;
    //printf("%d\n",balance);
    add+=balance;
    if(!balance)++add;
  }
  printf("%d\n",1+edges+max(0,add-1));
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
    printf("Case #%d: ",tt);
    solve();
    fflush(stdout);
  }
  freopen(out,"r",stdin);
  char c;while((c=getc(stdin))!=EOF)putc(c,stderr);
}

