#include <iostream>
#include <cstdio>
#include <cmath>
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

int f(int a)
{
   if(a % 2 == 0){return a/2;}
   else{return 3*a + 1;}
}

int main(){
   int s;
   cin >> s;
   vector<int> a;
   a.push_back(s);

   int i = 1;
   while(true){
      int a_i = f(a[i-1]);
      i++;
      for(int j=0; j < (int)a.size(); j++){
         if(a_i == a[j]){
            cout << i << endl;
            return 0;
         }
      }
      a.push_back(a_i);
   }

}