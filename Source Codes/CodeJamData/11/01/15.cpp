#include <algorithm>
#include <iostream>
#define N 101
using namespace std;

main()
{
  int cases;
  cin >> cases;
  for(int loop=1; loop<=cases; loop++)
  {
    printf("Case #%d: ",loop);
    int n,p;
    int o=1,b=1;
    int ot=0,bt=0,t=0;

    char s[5];
    cin >> n; while(n--)
    {
      scanf("%s%d",s,&p);
      if (s[0]=='O')
      {
        int q = ot + abs(o-p) + 1;
        t = max(t+1,q); ot=t; o=p;
      }
      else
      {
        int q = bt + abs(b-p) + 1;
        t = max(t+1,q); bt=t; b=p;
      }
    }
    printf("%d\n",t);
  }
}
