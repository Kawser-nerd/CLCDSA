#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
  int a, b;
  cin >> a >> b;

  if(a < b) swap(a, b);

  int ans = a - b;
  if(a - b >= 9-a + b) ans = 10-a + b;

  cout << ans << endl;

  return 0;

}