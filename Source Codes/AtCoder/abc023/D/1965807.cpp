#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <bitset>
#include <climits>
#define REP(i,n) for (int i=0;i<(n);i++)
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
#define RFOR(i,a,b) for (int i=(a)-1;i>=(b);i--)
#define ll long long
#define ull unsigned long long
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
const int INF = 1e9;
const ll LL_INF = 1e18;
const int MOD = 1e9 + 7;

using namespace std;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  int H[100005], S[100005];
  REP(i,N){
    cin >> H[i] >> S[i];
  }

  int imos[100005];
  ll l = 1, r = (long long)1e15 + 1;
  while(abs(r - l) > 1){
    ll mid = (r + l)/2;
    fill(imos, imos + N, 0);
    REP(i,N){
      if((mid - H[i]) < 0){
        imos[0] = 1000;
        break;
      }else if(((mid - H[i]) / S[i]) < N){
        imos[((mid - H[i]) / S[i])]++;
      }
    }
    bool ok = true;
    REP(i,N - 1){
      if(i){
        imos[i] += imos[i - 1];
        if(imos[i] > i + 1){
          ok = false;
          break;
        }
      }else{
        if(imos[i] > 1){
          ok = false;
          break;
        }
      }
    }
    if(ok) r = mid;
    else l = mid;
  }
  cout << r << endl;
  return 0;
}