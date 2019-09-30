#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cassert>
#include<cstring>
#include<climits>
#include<sstream>
#include<unordered_map>
#include<deque>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<bitset>

#define REP(i,s,n) for(int i=s;i<n;++i)
#define rep(i,n) REP(i,0,n)

using namespace std;

typedef long long ll;

#define MAX 100
int K,N;
string v[MAX],w[MAX];
const bool debug = true;

bool check(deque<int> &lens) {
  unordered_map<char,string> mp;
  rep(i,N) {
    int cur = 0;
    rep(j,(int)v[i].size())  {
      char c = v[i][j];
      if( cur + lens[c-'0'] - 1 >= (int)w[i].size() ) return false;
      string s = w[i].substr(cur,lens[c-'0']);
      if( mp.count(c) ) {
	if( mp[c] != s ) return false;
      } else {
	mp[c] = s;
      }
      cur += lens[c-'0'];
    }
    if( cur != (int)w[i].size() ) return false;
  }
  if( (int)mp.size() >= K ) {
    for(char c='1';c<=(char)('0'+K);++c) {
      cout << mp[c] << endl;
    }
    return true;
  }
  return false;
}

bool dfs(int cur,deque<int> &lens) {
  if( cur > K ) return check(lens);
  REP(i,1,4) {
    lens.push_back(i);
    if( dfs(cur+1,lens) ) return true;
    lens.pop_back();
  }
  return false;
}

void compute() {
  deque<int> lens;
  lens.push_back(0);
  assert(dfs(0,lens));
}

int main() {
  cin >> K >> N;
  rep(i,N) cin >> v[i] >> w[i];
  compute();
  return 0;
}