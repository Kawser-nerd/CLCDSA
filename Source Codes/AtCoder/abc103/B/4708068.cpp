#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
  char a1[150],a2[150];
  char pt;
  int l1,l2,i,j;
  scanf("%s",&a1);
  scanf("%s",&a2);
  l1=strlen(a1);
  l2=strlen(a2);
  if(l1!=l2)
  {
      printf("No\n");
  }
  else
  {
      for(i=0;i<l1;i++)
      {
          if(strcmp(a1,a2)==0)
          {
              printf("Yes\n");
              break;
          }
          else
          {
              pt=a1[l1-1];
              for(j=l1-2;j>=0;j--)
              {
                  a1[j+1]=a1[j];
              }
              a1[0]=pt;
          }
      }
      if(i==l1)
      {
          printf("No\n");
      }
  }
    return 0;
} ./Main.cpp:11:14: warning: format specifies type 'char *' but the argument has type 'char (*)[150]' [-Wformat]
  scanf("%s",&a1);
         ~~  ^~~
./Main.cpp:12:14: warning: format specifies type 'char *' but the argument has type 'char (*)[150]' [-Wformat]
  scanf("%s",&a2);
         ~~  ^~~
2 warnings generated.