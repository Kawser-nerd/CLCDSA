#include <iostream>
#include <ccomplex>
#include <vector>
#include <cassert>
#include <utility>
#include <algorithm>
#include <string>
#include <deque>
#include <queue>
#include <functional>
#include <cmath>
#include <iomanip>
#include <map>
#include <numeric>
#include <list>
#include <assert.h>
#include <math.h>
#include <valarray>
#include <stdio.h>
#include <algorithm>
#include <set>
#include <complex>
#include <list>
#include <time.h>
#include <stack>
#include <locale>
#include <clocale>
#include <ctype.h>
#include <wchar.h>
#include <random>
#include <vector>
#include <unordered_map>
#include <bitset>

using namespace std;
typedef long long int LL;
typedef long long int ll;
typedef pair<long long int, long long int> pii;
typedef pair<double, double> pdd;

#define SORT(c) sort((c).begin(),(c).end())
#define BACKSORT(c) sort((c).begin(),(c).end(),std::greater<LL>())
#define FOR(i,a,b) for(LL i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  LL N;
  cin >> N;

  vector<pii> v;

  FOR(i,1,N+1){
    FOR(j,i+1,N+1){
      if(i+j!=(N/2)*2+1){
        v.push_back(make_pair(i, j));
      }
    }
  }

  cout << v.size() << endl;
  REP(i,v.size()){
    cout << v[i].first << " " << v[i].second << endl;
  }
}