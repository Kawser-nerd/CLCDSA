#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef unsigned short us;
typedef unsigned char uc;

int main()
{
  int cases;
  cin >> cases;
  for(int loop=1; loop<=cases; loop++)
  {
    ull r,t; cin >> r >> t;
    ull a=1, b=1 + t/(2*r+1);
    while(b-a > 1)
    {
      ull c = (a+b)/2;
      if (t/c >= 2*r+2*c-1) a=c; else b=c;
    }
    assert(b-a==1);
    printf("Case #%d: ",loop);
    cout << a << endl;
    // puts("");
  }
}
