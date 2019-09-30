#include <iostream>
#define ll long long
#define endl '\n'
using namespace std;

int main(void)
{
  ll X, t; cin >> X >> t;
  ll ret = X - t;
  if(ret < 0) ret = 0;
  cout << ret;
  
  return 0;
}