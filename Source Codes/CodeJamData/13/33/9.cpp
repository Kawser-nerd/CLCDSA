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
// TREES
// Tree
#define INF 10000000000000000LL
#define SZ 8388608
ll set_to[2*SZ] , min_val[2*SZ];
void update(int vr){
  min_val[vr] = set_to[vr];
  if(vr < SZ)
   min_val[vr] = max(min_val[vr] , min(min_val[2*vr] , min_val[2*vr + 1]));
}
int LO , HI;
ll VAL;
void _add(int vr=1 , int _lo = 0 , int _hi = SZ-1){
  if(LO <= _lo && _hi <= HI){
   relaxMax(set_to[vr] , VAL);
   update(vr);
   return;
                            }
  if(_hi < LO || HI < _lo)return;
  int mid = (_lo + _hi)>>1;
  _add(2*vr , _lo , mid),
  _add(2*vr+1 , mid+1 , _hi);
  update(vr);
}
void add(int lo , int hi , ll how){
  LO = lo , HI = hi , VAL = how;
  _add();
}
ll _get_minimum(int vr=1 , int _lo = 0 , int _hi = SZ-1 , ll lb = 0){
  relaxMax(lb , set_to[vr]);
  if(LO <= _lo && _hi <= HI){
   ll val = min_val[vr];
   return max(lb , val);
                            }
  if(_hi < LO || HI < _lo)return INF;
  int mid = (_lo + _hi)>>1;
  ll val = min(
               _get_minimum(2*vr , _lo , mid),
               _get_minimum(2*vr+1 , mid+1 , _hi));
  return max(lb , val);
}
ll get_minimum(int lo , int hi){
  LO = lo , HI = hi;
  ll ret = _get_minimum();
}
void init(){
  memset(set_to , 0 , sizeof set_to);
  memset(min_val , 0 , sizeof min_val);
}
// </end>
struct attack{
  ll lo , hi , s;
  attack(ll _lo = 0 , ll _hi = 0 , ll _s = 0){
   lo = _lo , hi = _hi , s = _s;
                                             }
};
ll get_id(vector<ll>& coord , ll pos){
  return lower_bound(all(coord) , pos) - coord.begin();
}
void doit(int CASE){
  init();
  ll ans = 0;
  map< ll , vector<attack> > A;
  vector<ll> coord;
  int N;
  cin>>N;
  for(int i=0;i<N;++i){
   ll di, ni, wi, ei, si, delta_di, delta_pi, delta_si;
   cin>>di>>ni>>wi>>ei>>si>>delta_di>>delta_pi>>delta_si;
   for(int j=0;j<ni;++j){
    ll day = di + j*delta_di;
    ll lo = (wi + j*delta_pi);
    ll hi = (ei + j*delta_pi);
    ll power = si + j*delta_si;
    A[day].pb(attack(lo , hi , power));
    coord.pb(lo) , coord.pb(hi);
                        }
                      }
  sort(all(coord));
  coord.erase(unique(all(coord)) , coord.end());
  //-----------------
  for(map< ll , vector<attack> >::iterator it = A.begin();
      it!=A.end();
      ++it){
   vector<attack>& cur = it->se;
   for(int i=0;i<sz(cur);++i){
    bool OK = false;
    ll plo = 2*get_id(coord , cur[i].lo),
       phi = 2*get_id(coord , cur[i].hi);
    if(get_minimum(plo , phi) < cur[i].s)
     OK = true;
    if(OK)++ans;
                             }
   for(int i=0;i<sz(cur);++i){
    ll plo = 2*get_id(coord , cur[i].lo),
       phi = 2*get_id(coord , cur[i].hi);
    add(plo , phi , cur[i].s);
                             }
           }
  cout<<"Case #"<<CASE<<": "<<ans<<'\n';
}
int main(){
  int Q; scanf("%d" , &Q);
  for(int CASE=1;CASE<=Q;++CASE)
   doit(CASE);
  return 0;
}
