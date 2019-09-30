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
   int n;
   cin >> n;
   vector<int> p;
   for(int i=0; i < n; i++){
      int p_tmp;
      cin >> p_tmp;
      p.push_back(p_tmp);
   }
   sort(p.begin(), p.end());
   int p_max = p.back();

   int p_sum = 0;
   for(int i = 0; i < (int)p.size() -1; i++){
      p_sum += p[i];
   }
   p_sum += p_max/2;
   cout << p_sum << endl;

   return 0;
}