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
   int N, M, X, Y;
   cin >> N >> M >>X >>Y;
   vector<int> x, y;
   for(int i=0; i < N; i++){
      int x_tmp;
      cin >> x_tmp;
      x.push_back(x_tmp);
   }
   x.push_back(X);
   for(int i=0; i < M; i++){
      int y_tmp;
      cin >> y_tmp;
      y.push_back(y_tmp);
   }
   y.push_back(Y);
   sort(x.begin(), x.end());
   sort(y.begin(), y.end());
   int x_max = x.back();
   int y_min = y[0];

   // abs(x_max - y_min) == 0??????,
   // ??x, y??????????????????,
   // ????????.
   if(not(x_max < y_min)){
      cout << "War" << endl;
      return 0;
   }
      cout << "No War" << endl;

   return 0;
}