#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int main()
{
    char a[10],b[10],c[10];
        int i,j;
         memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        scanf("%s",&a);
        scanf("%s",&b);
        int len=strlen(b);
        for (i=0,j=len-1;i<len,j>=0 ;i++,j--)
        {
            c[i]=b[j];
        }
        if(strcmp(a,c)==0)
            printf("YES\n");
        else
            printf("NO\n");
  return 0;
} ./Main.cpp:12:20: warning: format specifies type 'char *' but the argument has type 'char (*)[10]' [-Wformat]
        scanf("%s",&a);
               ~~  ^~
./Main.cpp:13:20: warning: format specifies type 'char *' but the argument has type 'char (*)[10]' [-Wformat]
        scanf("%s",&b);
               ~~  ^~
./Main.cpp:15:27: warning: relational comparison result unused [-Wunused-comparison]
        for (i=0,j=len-1;i<len,j>=0 ;i++,j--)
                         ~^~~~
3 warnings generated.