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

const int oo = 1e9;
const ll ool = (ll)oo * oo;

string c, j;
int n;

ll pot[20];

ll memo[20][5];
bool bio[20][5];

ll dp(int id, int clr){
  if (id == n) return 0;
  ll &r = memo[id][clr];
  if (bio[id][clr]++) return r;

  if (clr == 0) r = ool;
  if (clr == 1) r = -ool;
  if (clr == 2) r = ool;

  vector < int > A, B;
  if (c[id] == '?') REP(i,10) A.pb(i);
  else A = {c[id]-'0'};
  if (j[id] == '?') REP(i,10) B.pb(i);
  else B = {j[id]-'0'};

  for (auto a : A) for (auto b : B){
      if (clr == 0){
	if (a == b) r = min(r, dp(id+1, 0));
	if (a > b) r = min(r, pot[n-1-id] * (a-b) + dp(id+1, 2));
	if (a < b) r = min(r, -(pot[n-1-id] * (a-b) + dp(id+1, 1)));
      }
      if (clr == 1){ // maxaj X-Y
	r = max(r, pot[n-1-id] * (a-b) + dp(id+1, 1));
      }
      if (clr == 2){ // minaj X-Y
	r = min(r, pot[n-1-id] * (a-b) + dp(id+1, 2));
      }
    } return r;
}

void rek(int id, int clr){
  if (id == n) return;
  ll r = dp(id, clr);

  vector < int > A, B;
  if (c[id] == '?') REP(i,10) A.pb(i);
  else A = {c[id]-'0'};
  if (j[id] == '?') REP(i,10) B.pb(i);
  else B = {j[id]-'0'};

  for (auto a : A) for (auto b : B){
      if (clr == 0){
	if (a == b) if (r == dp(id+1, 0)){c[id] = '0'+a, j[id] = '0'+b, rek(id+1, 0); return;}
	if (a > b) if (r == pot[n-1-id] * (a-b) + dp(id+1, 2)){c[id] = '0'+a, j[id] = '0'+b, rek(id+1, 2); return;}
	if (a < b) if (r == -(pot[n-1-id] * (a-b) + dp(id+1, 1))){c[id] = '0'+a, j[id] = '0'+b, rek(id+1, 1); return;}
      }
      if (clr == 1){ // maxaj X-Y
	if (r == pot[n-1-id] * (a-b) + dp(id+1, 1)){
	  c[id] = '0'+a, j[id] = '0'+b, rek(id+1, 1);
	  return;
	}
      }
      if (clr == 2){ // minaj X-Y
	if (r == pot[n-1-id] * (a-b) + dp(id+1, 2)){
	  c[id] = '0'+a, j[id] = '0'+b, rek(id+1, 2);
	  return;
	}
      }
    }
}

void Solve(){

  memset(bio, 0, sizeof bio);
  cin >> c >> j;
  n = (int)c.size();
  dp(0, 0);
  rek(0, 0);
  cout << c << " " << j << endl;
  
}

int main(){
  ios_base::sync_with_stdio(false);

  pot[0] = 1;
  REP(i,19) pot[i+1] = pot[i] * 10;

  int t;
  cin >> t;
  REP(i,t) cout << "Case #" << i+1 << ": ", Solve();

  return 0;
}
