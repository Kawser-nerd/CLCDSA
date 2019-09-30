#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

#include <complex>

#include <functional>
#include <cassert>

typedef long long ll;
using namespace std;

#define debug(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl;


#define mod 1000000007 //1e9+7(prime number)
#define INF 1000000000 //1e9
#define LLINF 2000000000000000000LL //2e18
#define SIZE 100010


int main(){
  int n, k, a[SIZE];

  scanf("%d%d", &n, &k);

  int pos1 = 0;
  
  for(int i=0;i<n;i++){
    scanf("%d", a+i);
    if(a[i] == 1) pos1 = i;
  }

  int ans = INF;

  int L = pos1;
  int R = n - pos1 - 1;
  
  for(int i=0;i<k;i++){
    ans = min(ans, max(0, L - i + k-2)/(k-1) + max(0, R-(k-i-1) + k-2)/(k-1));
  }
  
  cout << ans + 1 << endl;
  
  
  return 0;
}