#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define ll long long
#define pb push_back
#define pii pair < int, int >
#define x first
#define y second

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

int num[256];
int out[20];

void Solve(){
  string s;
  cin >> s;
  memset(num, 0, sizeof num);
  memset(out, 0, sizeof out);
  for (auto t : s) ++num[(int)t];

  out[0] = num['Z'];
  out[2] = num['W'];
  out[6] = num['X'];
  out[8] = num['G'];
  out[7] = num['S'] - out[6];
  out[4] = num['U'];
  out[5] = num['F'] - out[4];
  out[9] = num['I'] - out[6] - out[8] - out[5];
  out[1] = num['N'] - out[7] - out[9]*2;
  out[3] = num['H'] - out[8];

  REP(i,10) REP(j,out[i]) cout << i; cout << endl;
  
}

int main(){
  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;
  REP(i,t) cout << "Case #" << i+1 << ": ", Solve();

  return 0;
}
