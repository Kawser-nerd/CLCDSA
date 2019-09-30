#include<map>
#include<iostream>
#include<deque>
#include<algorithm>
#include<string>
#include<cctype>
#include<iomanip>
#include<vector>
#include<queue>
 
using namespace std;
#define REP(i,b,e) for(ll i=(ll)b;i<(ll)e;i++)
#define rep0(i,n) REP(i,0ll,n)
#define rep1(i,n) REP(i,1ll,n+1)
 
#define shosu setprecision(10)
 
typedef long long ll;
typedef pair<int,int> P;
ll longinf=1ll<<60;
int inf=1<<29;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};


string a[10];
string cp[10];

void dfs(int i,int j){
      if(cp[i][j]=='o'){
            cp[i][j]='x';
            rep0(k,4){
                  int ni=i+dx[k];
                  int nj=j+dy[k];
            if(ni>=0&&ni<10&&nj>=0&&nj<10){
                  dfs(ni,nj);
            }
            }
      }
}

int main(){
      rep0(i,10){
            cin>>a[i];
      }
      bool ok=false;
      rep0(i,10){
            rep0(j,10){
                  rep0(k,10){
                        
                              cp[k]=a[k];
                        
                  }
                  cp[i][j]='o';
                  dfs(i,j);
                  int cnt=0;
                  rep0(k,10){
                        rep0(l,10){
                              if(cp[k][l]=='o'){
                                    cnt++;
                              }
                        }
                  }
                  if(cnt==0) ok=true;
            }
      }
      if(ok) cout<<"YES"<<endl;
      else cout<<"NO"<<endl;
      return 0;
}