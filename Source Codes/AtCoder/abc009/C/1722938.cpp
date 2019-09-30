#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <ctime>
#define INF 1000000000
#define LINF 9000000000000000000
#define mod 1000000007

#define rep(i,n) for(int i=0;i<int(n);i++)
#define rrep(i,n) for(int i=(n);i>=0;i--)
#define REP(i,a,b) for(int i=(a);i<int(b);i++)
#define all(x) (x).begin(),x.end()
#define rsort(x) sort(all(x));reverse(all(x))
#define pb push_back
#define mp make_pair
#define MOD(x) (x%(mod))
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> pi;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
bool debug=false;
/*---------------------------------------------------*/

int n,k;
string s;

void solve(){
  bool used[101]={false}; // i????????????
  string ans="",str=s;
  sort(all(str));
  rep(i,s.size()){
    rep(j,s.size()){
      if(!used[j]){
	int num1=0,num2=0;
	string tmp=ans+str[j];
        rep(k,i+1)if(tmp[k]!=s[k])num1++;
	int a[26]={0},b[26]={0};
	rep(k,n)if(k!=j&&!used[k])a[str[k]-'a']++;
	REP(k,i+1,n)b[s[k]-'a']++;
	rep(k,26)num2+=min(a[k],b[k]);

	if(num1+n-i-1-num2<=k){ans+=str[j];used[j]=true;break;}
      }
    }
  }
  rep(i,n)if(!used[i])ans+=str[i];
  cout<<ans<<endl;
}

int main(){
  cin>>n>>k>>s;
  solve();
  return 0;
}