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
  pair<int, int> x[200005];
  REP(i,N){
    cin >> x[i].first;
    x[i].second = i;
  }
  sort(x, x + N);
  int f = x[N/2 - 1].first;
  int s = x[N/2].first;
  REP(i,N){
    if(i >= N/2){
      x[i].first = f;
    }else{
      x[i].first = s;
    }
  }
  sort(x, x + N, [](const pair<int, int>& a, const pair<int,int>& b){
      return a.second < b.second;});
  REP(i,N){
    cout << x[i].first << endl;
  }
  return 0;
}