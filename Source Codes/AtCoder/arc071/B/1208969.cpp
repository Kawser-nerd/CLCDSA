#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>
using namespace std;



int main()
{
  int i;
  long long int M = 1000000007;
  long long int n,m;
  long long int x,y;
  long long int ans = 0;
  cin >> n >> m;
  x = y =  0;

  for(i=0;i<n;i++){
    long long int tmp_sum,tmp;
    cin >> tmp;
    tmp_sum = (tmp * ( (1 - n) + 2 * i ) ) % M;
    x += tmp_sum;
    x %= M;
  }

  for(i=0;i<m;i++){
    long long int tmp_sum,tmp;
    cin >> tmp;
    tmp_sum = (tmp * ( (1 - m) + 2 * i ) ) % M;
    y += tmp_sum;
    y %= M;
  }

  ans = ( y * x ) % M;

  cout << ans << endl;

  return 0;
}