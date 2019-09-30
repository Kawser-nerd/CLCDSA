#include <iostream>
#include <string>

using namespace std;

typedef long long LL;

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))
#define ALL(a)  (a).begin(),(a).end()
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

#define dump(x)  cerr << #x << " = " << (x) << endl;

LL p = 1000*1000*1000 + 7;

int main() {
  string S;
  cin >> S;

  LL a_count = 0, h_cum = 1, incre = 0, count = 0;

  for (const auto &c : S) {
    if (c == 'A') {
      a_count = (a_count + h_cum)%p;
    } else if (c == 'B') {
      incre = (incre + a_count)%p;
    } else if (c == 'C') {
      count = (count + incre)%p;
    } else if (c == '?') {
      count = (count*3 + incre)%p;
      incre = (incre*3 + a_count)%p;
      a_count = (a_count*3 + h_cum)%p;
      h_cum = (h_cum*3)%p;
    }
  }
  
  cout << count % p << endl;


  return 0;
}