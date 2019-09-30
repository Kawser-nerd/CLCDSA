#include <cstdio>
#include <vector>
#include <algorithm>

typedef long long int ll;

//const double th0 = 0;
//const double th1 = 1e+6;
 
struct state {
  ll aw;
  ll av;
  state(ll aw=0, ll av=0): aw(aw), av(av) {}
};

struct item {
  int w;
  int v;
  double d;
  item(int w, int v): w(w), v(v), d((double) v/w) { }
};
 
int n, w;

ll lower;
 
std::vector<item> is;
std::vector<state> dp[2];
 
void add(const std::vector<state> &s, const item &k, std::vector<state> &u, ll uw){
  auto i = s.cbegin();
  auto j = s.cbegin();
  while(i != s.cend() && j != s.cend()){
    if(i->aw > uw){ i = s.cend(); break; }
    ll jav = j->av + k.v;
    ll jaw = j->aw + k.w;
    if(jaw > uw){ j = s.cend(); break; }
    if(i->aw <= jaw && i->av >= jav){ ++j; }
    else if(i->aw >= jaw && i->av <= jav){ ++i; }
    else if(i->aw < jaw){ u.push_back(*i++); }
    else { u.emplace_back(state(jaw, jav)); ++j;}
  }
  while(i != s.cend()){
    if(i->aw > uw) return;
    u.push_back(*i++);
  }
  while(j != s.cend()){
    ll jav = j->av + k.v;
    ll jaw = j->aw + k.w;
    if(jaw > uw) return;
    u.emplace_back(state(jaw, jav));
    ++j;
  }
}

void remove(const std::vector<state> &s, const item &k, std::vector<state> &u, ll uw){
  auto i = s.cbegin();
  auto j = s.cbegin();
  while(i != s.cend() && j != s.cend()){
    if(i->aw > uw){ i = s.cend(); break; }
    ll jav = j->av - k.v;
    ll jaw = j->aw - k.w;
    if(jaw > uw){ j = s.cend(); break; }
    if(i->aw <= jaw && i->av >= jav){ ++j; }
    else if(i->aw >= jaw && i->av <= jav){ ++i; }
    else if(i->aw < jaw){ u.push_back(*i++); }
    else { u.emplace_back(state(jaw, jav)); ++j;}
  }
  while(i != s.cend()){
    if(i->aw > uw) return;
    u.push_back(*i++);
  }
  while(j != s.cend()){
    ll jav = j->av - k.v;
    ll jaw = j->aw - k.w;
    if(jaw > uw) return;
    u.emplace_back(state(jaw, jav));
    ++j;
  }
}

//ll upper;

 
/*
inline void shrink(const std::vector<state> &s, double d0, double d1, std::vector<state> &u){
  for(auto x: s){
    ll t = 1 + (ll) ((x.aw > w) ? x.av - (x.aw - w) * d0 : x.av + (w - x.aw) * d1);
    if(t >= lower) u.push_back(x);
//    if(t > upper) upper = t;
  }
}
*/

void shrink(const std::vector<state> &s, const item &i0, const item &i1, std::vector<state> &u){
  for(auto x: s){
    if(x.aw > w){
      __int128 t =  2 * ((__int128) x.av) * i0.w - ((__int128) (x.aw - w)) * i0.v;
      if(t >= (__int128) lower * i0.w) u.push_back(x);
    }
    else {
      __int128 t =  2 * ((__int128) x.av) * i1.w + ((__int128) (w - x.aw)) * i1.v;
      if(t >= (__int128) lower * i1.w) u.push_back(x);
    }
//    if(t > upper) upper = t;
  }
}

 
int main(){
  scanf("%d%d", &n, &w);
  is.reserve(200);
  dp[0].reserve(300);
  dp[1].reserve(300);

  is.emplace_back(item(1,0));

  for(int i=0;i<n;i++){
    int ww, vv;
    scanf("%d%d",&vv,&ww);
    if(ww <= w) is.emplace_back(item(ww,vv));
  }
  n = is.size()-1;

  std::sort(is.begin()+1, is.end(), [](const item &x, const item &y){ return (ll) x.v * y.w > (ll) y.v * x.w; });
  is.emplace_back(item(1,0));


  ll aw = 0;
  ll av = 0;
  int ii;
  for(ii=1;ii<=n;ii++){
    const item &x = is[ii];
    if(aw + x.w > w) break;
    aw += x.w;
    av += x.v;
  }

  dp[0].emplace_back(state(aw, av));

  lower = av;
  ll sumw = w+aw;

  for(int i=ii-1, j=ii; i>0||j<=n; ){
    if(i>0){
//      if(av - is[i].v + (ll) ((double) (w - aw + is[i].w) * is[ii].d) > lower)
      sumw -= is[i].w;
      remove(dp[0], is[i], dp[1], sumw);
//      if(is[i-1].d>th0 && is[i-1].d<th1 && is[j].d>th0 && is[j].d<th1){
      if(1){
        dp[0].resize(0);
        lower = (std::upper_bound(dp[1].cbegin(), dp[1].cend(), w, [](int w, const state &x){ return x.aw > w; })-1)->av;
        shrink(dp[1], is[i-1], is[j], dp[0]);
      }
      else dp[0].swap(dp[1]);
      dp[1].resize(0);
      --i;
    }
//std::for_each(dp[0].cbegin(), dp[0].cend(), [](const state &x){ printf("(%lld, %lld), ", x.aw, x.av); });

    if(j<=n){
//      if(av + is[j].v + (ll) ((double) (w - aw - is[j].w) * is[ii-1].d) > lower){
      add(dp[0], is[j], dp[1], sumw);
//      if(is[i].d>th0 && is[i].d<th1 && is[j+1].d>th0 && is[j].d<th1){
      if(1){
        dp[0].resize(0);
        lower = (std::upper_bound(dp[1].cbegin(), dp[1].cend(), w, [](int w, const state &x){ return x.aw > w; })-1)->av;
        shrink(dp[1], is[i], is[j+1], dp[0]);
      }
      else dp[0].swap(dp[1]);
      dp[1].resize(0);
      ++j;
    }
//std::for_each(dp[0].cbegin(), dp[0].cend(), [](const state &x){ printf("(%lld, %lld), ", x.aw, x.av); });
    if(dp[0].size() == 1) break;
//printf("%lu\n", dp[0].size());
  }

//std::for_each(dp[0].cbegin(), dp[0].cend(), [](const state &x){ printf("(%lld, %lld), ", x.aw, x.av); });
//puts("");
  lower = (std::upper_bound(dp[0].cbegin(), dp[0].cend(), w, [](int w, const state &x){ return x.aw > w; })-1)->av;
  printf("%lld\n", lower);
 
  return 0;
}