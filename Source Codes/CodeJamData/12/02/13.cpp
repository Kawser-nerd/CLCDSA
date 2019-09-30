#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <set>

#define MAXN 1001

using namespace std;
int n, g, s, p, score[MAXN], sol;
bool marked[MAXN];

void init()
{
   sol = 0;
   for (int i = 0; i < MAXN; i++)
      marked[i] = false;
}

void read()
{
   cin >> g >> s >> p;
   for (int i = 0; i < g; i++)
      cin >> score[i];
}

void write(int casen)
{
   cout << "Case #" << casen << ": " << sol << endl;
}

void solve()
{
   int bound = 3 * p - 2;
   for (int i = 0; i < g; i++)
   {
      if (score[i] == 0)
      {
         if (p == 0)
            sol++;
         continue;
      }
      if (score[i] >= bound)
      {
         sol++;
         marked[i] = true;
      }
   }

   for (int i = 0; i < g && s > 0; i++)
   {
      if (score[i] == 0 || score[i] == 1)
         continue;
      if (!marked[i] && score[i] >= 3 * p - 4)
      {
         sol++;
         s--;
      }
   }
}

int main()
{
   cin >> n;
   for (int casen = 0; casen < n; casen++)
   {
      init();
      read();
      solve();
      write(casen + 1);
   }
   return 0;
}
