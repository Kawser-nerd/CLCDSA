#ifdef _WIN32
#  define LL "%I64d"
#else
#  define LL "%Ld"
#endif

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <bitset>
#include <string>
#include <algorithm>
#include <complex>
#include <utility>
using namespace std;
#define null NULL
#define mp make_pair
#define pb(a) push_back(a)
#define sz(a) ((int)(a).size())
#define all(a) a.begin() , a.end()
#define fi first
#define se second
#define relaxMin(a , b) (a) = min((a),(b))
#define relaxMax(a , b) (a) = max((a),(b))
#define SQR(a) ((a)*(a))
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long ll;
bool bad[300];
char buf[1000010];
int cnt[1000010];
int n;
void doit(int CASE){
  scanf("%s%d" , &buf , &n);
  int L = strlen(buf);
  cnt[0] = (bad[buf[0]] ? 0 : 1);
  for(int i=1;i<L;++i)
   if(bad[buf[i]])cnt[i] = 0;
   else cnt[i] = 1+cnt[i-1];
  int lo = 0;
  ll ans = 0;
  for(int i=0;i<L;++i){
   if(cnt[i] >= n)lo = i;
   if(cnt[lo] >= n){
    int spos = lo - n + 1;
    ans += spos + 1;
                   }
                      }
  cout<<"Case #"<<CASE<<": "<<ans<<'\n';
}
int main(){
  bad['a'] = bad['e'] = bad['i'] = bad['o'] = bad['u'] = true;
  int Q; scanf("%d" , &Q);
  for(int i=1;i<=Q;++i)
   doit(i);
  return 0;
}
