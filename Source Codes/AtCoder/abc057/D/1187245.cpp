#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <utility>
#include <string>
#include <cstring>
#include <queue>
#include <cmath>
#include <iomanip>
#include <cassert>
#include <numeric>
#define EPS 1e-9
#define INF 1070000000LL
#define MOD 1000000007LL
#define fir first
#define foreach(it,X) for(auto it=(X).begin();it!=(X).end();it++)
#define numa(x,a) for(auto x: a)
#define ite iterator
#define mp make_pair
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define pb push_back
#define pf push_front
#define sec second
#define sz(x) ((int)(x).size())
#define ALL( c ) (c).begin(), (c).end()
#define gcd(a,b) __gcd(a,b)
#define mem(x,n) memset(x,n,sizeof(x))
#define endl "\n"
using namespace std;
template <int POS, class TUPLE> void deploy(std::ostream &os, const TUPLE &tuple){}
template <int POS, class TUPLE, class H, class ...Ts> void deploy(std::ostream &os, const TUPLE &t){ os << (POS == 0 ? "" : ", ") << get<POS>(t); deploy<POS + 1, TUPLE, Ts...>(os, t); }
template <class T,class U> std::ostream& operator<<(std::ostream &os, std::pair<T,U> &p){ os << "(" << p.first <<", " << p.second <<")";return os; }
template <class T> std::ostream& operator<<(std::ostream &os, std::vector<T> &v){ int remain = v.size(); os << "{"; for(auto e: v) os << e << (--remain == 0 ? "}" : ", "); return os; }
template <class T> std::ostream& operator<<(std::ostream &os, std::set<T> &v){ int remain = v.size(); os << "{"; for(auto e: v) os << e << (--remain == 0 ? "}" : ", "); return os; }
template <class T, class K> std::ostream& operator<<(std::ostream &os, std::map<T, K> &mp){ int remain = mp.size(); os << "{"; for(auto e: mp) os << "(" << e.first << " -> " << e.second << ")" << (--remain == 0 ? "}" : ", "); return os; }
#define DEBUG1(var0) { std::cerr << (#var0) << "=" << (var0) << endl; }
#define DEBUG2(var0, var1) { std::cerr << (#var0) << "=" << (var0) << ", ";DEBUG1(var1); }
#define DEBUG3(var0, var1, var2) { std::cerr << (#var0) << "=" << (var0) << ", ";DEBUG2(var1,var2); }
#define DEBUG4(var0, var1, var2, var3) { std::cerr << (#var0) << "=" << (var0) << ", ";DEBUG3(var1,var2,var3); }
using ll = long long;

int N,A,B;
vector <ll> nums;
ll table[60][60];
void pascal_init(int n){
  rep(i,n+1){
    table[i][i] = 1;
    table[i][0] = 1;
  }
  
  rep2(i,2,n+1){
    rep2(j,1,i){
      table[i][j] = table[i-1][j-1] + table[i-1][j];
    }
  }
}


inline auto nCm(int n, int m) {
  return table[n][m];
}

int main()
{
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  pascal_init(55);
  cin >> N >> A >> B;
  nums.resize(N);
  rep(i,N){
    cin >> nums[i];
  }
  sort(ALL(nums));
  reverse(ALL(nums));
  ll sum = accumulate(nums.begin(), nums.begin() + A, 0LL);
  cout <<  fixed << setprecision(10) << sum / (double) A << endl;
  //A
  map <ll, int> memo;
  map <ll,int> As;
  rep(i,N){
    if (i < A) {
      As[nums[i]] += 1;
    }
    memo[nums[i]] += 1;
  }
  ll patA = 1;
  for (auto x : As) {
    ll k = x.fir;
    auto n = memo[k];
    auto m = x.sec;
    patA *= nCm(n,m);
  }
  if (nums[0] == nums[A-1]) {
    ll patb = 0;
    for (int a = A + 1; a <= B; a++) {
      auto n = memo[nums[0]];
      auto m = a;
      if (m > n) {
        break;
      }
      patb += nCm(n,m);
    }
    cout <<patA + patb << endl;
  } else {
    cout << patA << endl;
  }

  return 0;
}