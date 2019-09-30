#include <iostream>
#include <vector>

using namespace std;

#define EACH(i,a) for (auto& i : a)
#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define RFOR(i,a,b) for(int i=(int)b-1;i>=(int)a;--i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define ALL(a) (a).begin(),(a).end()
#define debug(x) cerr << #x << ":" << x << endl;
#define OK(ok) cout << (ok ? "Yes" : "No") << endl;
typedef long double ll;

void CINT(){}
template <class Head,class... Tail>
void CINT(Head&& head,Tail&&... tail) {
  cin >> head; CINT(move(tail)...);
}
#define CIN(...) int __VA_ARGS__;CINT(__VA_ARGS__)

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  CIN(n, a, b);
  vector< int > s(n);
  
  ll sum = 0.0;
  REP(i, n) {
    cin >> s[i];
    sum += s[i];
  }
  
  sum /= (ll)n;
  
  sort(ALL(s));
  
  double p, q;
  if (s[0] == s[n - 1]) {
    cout << -1 << endl;
    return 0;
  } else {
    p = (double)b / (double)(s[n - 1] - s[0]);
    q = a - sum * p;
  }
  printf("%lf %lf\n",p ,q);

  return 0;
}