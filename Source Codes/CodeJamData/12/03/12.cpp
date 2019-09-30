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
#include <sstream>

#define MAXN 1001

using namespace std;
int t, a, b, sol, maxx;

void init()
{
   sol = 0;
}

void read()
{
   cin >> a >> b;
}

void write(int casen)
{
   cout << "Case #" << casen << ": " << sol << endl;
}

void process(int x)
{
   string str;
   stringstream stream;
   int num, i, j;
   vector<int> tempsols;

   stream << x;
   str = stream.str();
   int len = str.length();
   for (i = 1; i < len; i++)
   {
      num = 0;
      for (j = 0; j < len; j++)
         num = num * 10 + str[(i + j) % len] - '0';
      if (num > x && num <= b)
      {
         bool good = true;
         for (int k = 0, l = tempsols.size(); k < l; k++)
            if (tempsols[k] == num)
               good = false;
         if (good)
         {
            tempsols.push_back(num);
            sol++;
         }
      }
   }
}

void solve()
{
   for (int i = a; i <= b; i++)
      process(i);
}

int main()
{
   cin >> t;
   for (int casen = 0; casen < t; casen++)
   {
      init();
      read();
      solve();
      write(casen + 1);
   }
   return 0;
}
