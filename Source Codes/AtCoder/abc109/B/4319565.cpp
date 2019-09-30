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
   int N;
   cin >> N;
   vector<string> W;
   for(int i=0; i<N; i++){
      string w;
      cin >> w;
      W.push_back(w);
   }

   for(int i=0; i < N-1; i++){
      if(W[i].back() != W[i+1][0]){
         cout << "No" << endl;
         return 0;
      }
      for(int j=i+1; j < N; j++){
         if(W[i] == W[j]){
            cout << "No" << endl;
            return 0;
         }
      }
   }
   cout << "Yes" << endl;

   return 0;
}