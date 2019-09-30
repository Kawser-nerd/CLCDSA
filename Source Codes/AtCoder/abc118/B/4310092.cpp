#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef long long unsigned int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

int main(){

   int n, m;
   cin >> n >> m;

   // vector cnt(???m, 0????)
   // m??????????????????
   vector<int> cnt(m,0);

   for(int i=0; i < n; i++){
      int k;
      cin >> k;
      for(int j=0; j < k; j++){
         int a;
         cin >> a;
         a--;
         cnt[a]++;
      }
   }

   int ans = 0;
   for(int i=0; i < m; i++){
      if(cnt[i] == n){
         ans++;
      }
   }
   cout << ans << endl;

   return 0;
}