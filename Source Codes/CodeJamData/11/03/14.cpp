#include <algorithm>
#include <iostream>
using namespace std;

main()
{
  int cases;
  cin >> cases;
  for(int loop=1; loop<=cases; loop++)
  {
    printf("Case #%d: ",loop);
    int m=1000001, s=0, t=0;
    int n; cin >> n;
    for(int i=0;i<n;i++)
      { int x; cin >> x; s += x; t ^= x; m = min(m,x); }
    if (t) puts("NO"); else printf("%d\n", s-m);
  }
}
