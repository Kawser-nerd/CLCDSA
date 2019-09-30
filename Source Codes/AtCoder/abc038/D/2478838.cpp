#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>
#include <deque>
#include <string>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; i++)
#define ALL(v) v.begin(),v.end()
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef pair<string,string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pi> vpi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

double EPS = 1e-9;
int INFi = 1000000005;
long long INFll = 1000000000000000005ll;
double PI = acos(-1);
int dirx[8] = {-1,0,0,1,-1,-1,1,1};
int diry[8] = {0,1,-1,0,-1,1,-1,1};
ll MOD = 1000000007;

const int MAX_N = 100000;

ll bit[MAX_N+1];

ll bit_max(int i){
  ll s = 0;
  while(i > 0){
    s = max(s,bit[i]);
    i -= i & -i;
  }
  return s;
}

void bit_set(int i, ll x, int n){
  while(i <= n){
    bit[i] = max(bit[i], x);
    i += i & -i;
  }
}


struct hako{
  int w;
  int h;
  bool operator<( const hako& right ) const {
        return w == right.w ? h > right.h : w < right.w;
    }
};

int main(){
  int n;
  cin >> n;
  int h[n], w[n];
  hako x[n];
  REP(i,n){
    cin >> w[i] >> h[i];
    x[i].w = w[i];
    x[i].h = h[i];
  }
  sort(x, x + n);
  memset(bit, 0, sizeof(bit));
  REP(i,n){
    bit_set(x[i].h, bit_max(x[i].h - 1) + 1, MAX_N+1);
  }

  cout << bit_max(MAX_N+1) << endl;

  return 0;
}