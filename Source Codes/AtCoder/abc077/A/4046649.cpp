#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int main()
{
    char a[10]={'\0'},b[10]={'\0'},c[10]={'\0'};
        int i,j;
        scanf("%s",&a);
        scanf("%s",&b);;
        if(a[0]==b[2]&&a[1]==b[1]&&a[2]==b[0])
            printf("YES\n");
        else
            printf("NO\n");
  return 0;
} ./Main.cpp:9:20: warning: format specifies type 'char *' but the argument has type 'char (*)[10]' [-Wformat]
        scanf("%s",&a);
               ~~  ^~
./Main.cpp:10:20: warning: format specifies type 'char *' but the argument has type 'char (*)[10]' [-Wformat]
        scanf("%s",&b);;
               ~~  ^~
2 warnings generated.