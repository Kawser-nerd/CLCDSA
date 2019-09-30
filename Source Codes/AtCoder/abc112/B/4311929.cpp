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

   int N, T;
   cin >> N >> T;
   int c[N], t[N];
   int c_min = INF;
   vector<int> costs;
   for(int i=0; i < N; i++)
   {
      cin >> c[i] >> t[i];
      if(t[i] <= T)
      {
         costs.push_back(c[i]);
      }
   }
   sort(costs.begin(), costs.end());
   if(costs.empty() == true){
      cout << "TLE" << endl;
    }
   else{
      cout << costs[0] << endl;
   }


   return 0;
}