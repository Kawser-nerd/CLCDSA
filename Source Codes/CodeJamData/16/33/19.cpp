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
const int maxn = 1e5 + 1000;

void perform(){
  driii(J,P,S);
  dri(K);
  if(K < S){
    cout << J * P * K << "\n";
    map<pii, int> f1;
    map<pii, int> f2;
    map<pii, int> f3;
    int start = 0;
    for(int j = 1; j <= J; j++){
      int tt = start; start++;
      rep(p, 1, P+1){
	rep(i, 0, K){
	  cout << j << " " << p << " " << (tt+1) << "\n";
	  int&a = f1[pii(j,p)];
	  int&b = f2[pii(j,tt+1)];
	  int&c = f3[pii(p,tt+1)];
	  a++; b++; c++;
	  assert(a <= K);
	  assert(b <= K);
	  assert(c<=K);
	  tt = (tt+1) % S;
	}
      }
    }
    return;
  }
  else{
    cout << J * P * S << "\n";
    rep(j,1,J+1)rep(p,1,P+1)rep(s,1,S+1){
      cout << j << " " << p << " " << s << "\n";
    }
    return;
  }
}

int main(){
	if (fopen("i.txt", "r")) freopen("i.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	dri(T);
	rep(Tc,0,T){
	  cout << "Case #" << (Tc+1) << ": ";
	  perform();
	}
	return 0;
}
