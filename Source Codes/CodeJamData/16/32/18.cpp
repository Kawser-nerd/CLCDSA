#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<vector>
#include<string>
#include<cstring>
#include<unordered_map>
#include<cassert>
#include<cmath>

//code by cl3488

#define dri(X) int (X); scanf("%d", &X)
#define drii(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define driii(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define pb push_back
#define mp make_pair
#define rep(i, s, t) for ( int i=(s) ; i <(t) ; i++)
#define fill(x, v) memset (x, v, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define why(x) cerr << #x << ": " << (x) << endl;
#define whisp(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define exclam cerr << "!!\n"
typedef long long ll;
using namespace std;
typedef pair<int, int> pii;
const ll inf = (ll)1e9 + 70;
const ll mod = 1e9 + 7;
const int maxn = 105;

ll p2[maxn];

int ans[maxn][maxn];
int B;

void printt(){
  rep(i, 1, B+1){
    rep(j, 1, B+1){
      cout << ans[i][j];
    }cout << "\n";
  }
}

void perform(){
    cin >> B; ll M; cin >> M;
  if(M > p2[B-2]){
    cout << "IMPOSSIBLE\n";
    return;
  }
  cout << "POSSIBLE\n";
  fill(ans, 0);
  for(int i = 1; i < B; i++){
    rep(j,i+1,B){
      ans[i][j] = 1;
    }
  }
  if(M == p2[B-2]){
    rep(i,1,B){
      ans[i][B] = 1;
    }
    printt();
    return;
  }
  vector<int> p;
  while(M != 0){
    p.pb(M % 2);
    M = M / (ll)2;
  }
  rep(i, 0, p.size()){
    if(p[i] == 1){
      ans[i+2][B] = 1;
    }
  }
  printt();
  return;
}

int main(){
  p2[0] = 1;
  rep(i,1,maxn){
    p2[i] = p2[i-1] * (ll)(2);
  }
  
	if (fopen("i.txt", "r")) freopen("i.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	dri(T);
	rep(Tc,0,T){
	  cout << "Case #" << (Tc+1) << ": ";
	  perform();
	}
	return 0;
}
