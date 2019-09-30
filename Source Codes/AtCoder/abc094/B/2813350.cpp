#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <cstring>
#include <utility>
#include <algorithm>
#include <functional>
#include <deque>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;

int main(){
   int n, m, x;
   cin >> n >> m >> x;
   int a[m];
   for (int i = 0; i < m; i++) cin >> a[i];
   int l = 0, r = 0;
   for (int i = 0; i < m; i++){
      if (a[i]<x) l++;
      else r++;
   }
   cout << min(l, r) << endl;
}