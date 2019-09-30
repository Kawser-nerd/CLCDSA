#include<cstdio>
#include<cstring>
#include<cmath>
#include<ctime>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<vector>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define popb pop_back

#define pii pair<int,int>
#define mp make_pair
#define X first
#define Y second

#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)

int X, R, C;


void print(int t, string won) {
  if (won[0] == 'G') won = "GABRIEL";
  else won = "RICHARD";
  printf("Case #%d: %s\n", t, won.c_str());
}

int main(){
  int T;
  scanf("%d", &T);
  FOR(t, 1, T) {
    scanf("%d%d%d", &X, &R, &C);
    if (X >= 7 || (R < X && C < X) || ((R * C) % X != 0)) {
      print(t, "R"); continue;
    }
    if (R >= X + 1 && C >= X + 1) {
      print(t, "G"); continue;
    }
    if (R < (X + 1) / 2 || C < (X + 1) / 2) {
      print(t, "R"); continue;
    }
    if (X <= 3) {
      print(t, "G"); continue;
    }
    if (X == 4) {
      if (R <= 2 || C <= 2) {
        print(t, "R"); continue;
      }
      print(t, "G"); continue;
    }
    if (X == 6) {
      if (R <= 3 || C <= 3) {
        print(t, "R"); continue;
      }
      print(t, "G"); continue;
    }
    // X == 5
    if (min(R, C) == 3 && max(R, C) == 5) {
      print(t, "R"); continue;
    }
    print(t, "G");
  }

  return 0;
}
