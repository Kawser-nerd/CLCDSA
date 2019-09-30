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
   int d;
   cin >> d;

   if(d == 25){cout << "Christmas" << endl;}
   else if(d == 24){cout << "Christmas Eve" << endl;}
   else if(d == 23){cout << "Christmas Eve Eve" << endl;}
   else if(d == 22){cout << "Christmas Eve Eve Eve" << endl;}

   return 0;
}