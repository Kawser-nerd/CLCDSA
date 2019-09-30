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

int n;
map < string, int > Ma, Mb;
vector < pii > E;

int taken[2005];
vector < int > nxt[2005];

bool bio[2005];
bool DFS(int id){
  if (bio[id]++) return false;
  for (auto t : nxt[id]){
    if (taken[t] == -1){taken[t] = id; return true;}
    if (DFS(taken[t])){taken[t] = id; return true;}
  } return false;
}

int Match(){

  memset(taken, -1, sizeof taken);
  REP(i,2005) nxt[i].clear();
  for (auto t : E) nxt[t.x].pb(t.y);

  int R = 0;
  REP(i,2005){
    memset(bio, 0, sizeof bio);
    if (DFS(i)) ++R;
  } return R;
  
}

void Solve(){

  Ma.clear();
  Mb.clear();
  E.clear();

  cin >> n;
  REP(i,n){
    string a, b;
    cin >> a >> b;
    if (Ma.count(a) == 0) Ma[a] = (int)Ma.size();
    if (Mb.count(b) == 0) Mb[b] = (int)Mb.size();
    E.pb({Ma[a], Mb[b]});
  }

  cout << n-((int)Ma.size()+Mb.size()-Match()) << endl;
  
}

int main(){
  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;
  REP(i,t) cout << "Case #" << i+1 << ": ", Solve();

  return 0;
}
