#pragma comment(linker,"/STACK:100000000")  

#include <cstdio>
#include <cmath>
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

int main(void)
{
   int i, j, k, l;
   //freopen("A-small-attempt0.in", "r", stdin);
   //freopen("A-small-attempt0.out", "w", stdout);
   freopen("A-large.in", "r", stdin);
   freopen("A-large.out", "w", stdout);

   scanf("%d\n", &nt);
   for (tn=0; tn<nt; tn++)
   {
      //fprintf(stderr, "Case #%d: \n", tn+1);

      printf("Case #%d: ", tn+1);
      scanf("%d%d\n", &n, &k);
      puts((k+1)%(1<<n)==0 ? "ON" : "OFF");
   }
   return 0;
}
