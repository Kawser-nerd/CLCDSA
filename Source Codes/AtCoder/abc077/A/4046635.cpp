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
        int len=strlen(b);
        j=len;
        for (i=0;i<len;i++)
        {
            j--;
            c[i]=b[j];
        }
        if(strcmp(a,c)==0)
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