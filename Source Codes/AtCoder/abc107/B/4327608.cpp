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
   int H, W;
   cin >> H >> W;
   vector<string> a;
   for(int h=0; h < H; h++){
      string s;
      cin >> s;
      a.push_back(s);
   }

   // true  : '#'
   // false : '.'
   vector<bool> height(H, false), width(W, false);

   for(int h=0; h < H; h++){
      for(int w=0; w < W; w++){
         if(a[h][w] == '#'){
            height[h] = true;
            width[w] = true;
         }
      }
   }

   for(int h=0; h < H; h++){
      // false : '.' : continue
      if(!height[h]){continue;}
      for(int w=0; w < W; w++){
         if(!width[w]){continue;}
         cout << a[h][w];
      }
      cout << endl;
   }
   return 0;

}