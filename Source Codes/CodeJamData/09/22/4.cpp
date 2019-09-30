#include <cstdio>
#include <cstdlib>
#include <memory.h>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
#define PI 3.14159265358979323846264338327950288
int T;
char N[25];
int main() {
   int i, j, Case = 1;
   scanf("%d", &T);
   while (T --) {
      scanf("%s", N + 1);
      N[0] = '0';
      int len = strlen(N);
      vector <char> list;
      for (i = len - 1; i > 0; i --) {
	 list.push_back(N[i]);
	 if (N[i] > N[i - 1])
	    break;
      }
      list.push_back(N[i - 1]);
      j = i;
      int mini = -1;
      for (i = 0; i < list.size(); i ++)
	 if (list[i] > N[j - 1] && (mini == -1 || list[i] < list[mini]))
	    mini = i;
      N[j - 1] = list[mini];
      list.erase(list.begin() + mini);
      sort(list.begin(), list.end());
      for (i = j; i < len; i ++)
	 N[i] = list[i - j];
      if (N[0] != '0')
	 printf("Case #%d: %s\n", Case ++, N);
      else
	 printf("Case #%d: %s\n", Case ++, N + 1);

   }
   return 0;
}

