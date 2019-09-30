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
   string n;
   cin >> n;
   for(int i=0; i < (int)n.size(); i++){
      if(n[i] == '1'){n[i] = '9';}
      else if(n[i] == '9'){n[i] = '1';}
   }
   cout << n << endl;

   return 0;
}