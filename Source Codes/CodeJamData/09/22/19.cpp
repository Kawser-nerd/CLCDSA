#pragma comment(linker,"/STACK:100000000")  

#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int n, tn, nt;

char s[1000000];

int main(void)
{
   int i, j, k, l, m;
   //freopen("B-small-attempt0.in", "r", stdin);
   //freopen("B-small-attempt0.out", "w", stdout);
   freopen("B-large.in", "r", stdin);
   freopen("B-large.out", "w", stdout);

   scanf("%d\n", &nt);
   for (tn=0; tn<nt; tn++)
   {
      fprintf(stderr, "Case #%d: ", tn+1);
      s[0]='0';
      gets(s+1);
      next_permutation(s, s+strlen(s));

      printf("Case #%d: ", tn+1);
        if (s[0]=='0') puts(s+1);
        else puts(s);
   }
   return 0;
}
