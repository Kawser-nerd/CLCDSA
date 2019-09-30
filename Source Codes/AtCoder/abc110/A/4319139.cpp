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
   array<int, 3> v;
   for(int i=0; i < 3; i++){
      cin >> v[i];
   }
   sort(v.begin(), v.end());
   cout << 10*v[2] + v[1] + v[0] << endl;
   return 0;
}