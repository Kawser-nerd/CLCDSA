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
#include <array>
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
   int n, k;
   cin >> n >> k;
   vector<int> cnt(k, 0);

   int i = 0;
   while(n){
      cnt[i]++;
      n--;
      i++;
      if(i == k){i=0;}
   }

   sort(cnt.begin(), cnt.end());
   cout << abs(cnt.back() - cnt[0]) << endl;
   return 0;
}