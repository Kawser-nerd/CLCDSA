#include <cstdio>
#include <cstdlib>
#include <cstring>
#include<cmath>
using namespace std;
int main()
{
    long long a,b,c;
    while(~scanf("%lld",&a))
    {

    b=sqrt(a);
    printf("%d\n",b*b);
    }
  return 0;
} ./Main.cpp:13:19: warning: format specifies type 'int' but the argument has type 'long long' [-Wformat]
    printf("%d\n",b*b);
            ~~    ^~~
            %lld
1 warning generated.