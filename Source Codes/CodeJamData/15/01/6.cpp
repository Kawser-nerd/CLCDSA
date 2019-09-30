#include<cstdio>
#include<cstring>
#include<cmath>
#include<ctime>
#include<algorithm>
#include<map>
#include<set>
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

#define maxN 1005

int T;
char str[maxN];
int num;
int max_diff;

int main(){
  scanf("%d", &T);
  FOR(t, 1, T) {
    max_diff = 0;
    int Smax;
    scanf("%d%s", &Smax, str);
    num = 0;
    REP(i, Smax+1) {
      if (str[i] - '0' > 0) {
        max_diff = max(max_diff, i - num);
        num += str[i] - '0';
      }
    }
    printf("Case #%d: %d\n", t, max_diff);
  }


  return 0;
}
