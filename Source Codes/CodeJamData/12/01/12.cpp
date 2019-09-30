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
int n;
char lookup[MAXN];
string line;

void init()
{
}

void read()
{
   getline(cin, line);
}

void write(int casen)
{
   cout << "Case #" << casen << ": " << line << endl;
}

void solve()
{
   for (int i = 0, len = line.length(); i < len; i++)
      if (line[i] >= 'a' && line[i] <= 'z')
         line[i] = lookup[(int)line[i]];
}

int main()
{
   lookup['a'] = 'y';
   lookup['b'] = 'h';
   lookup['c'] = 'e';
   lookup['d'] = 's';
   lookup['e'] = 'o';
   lookup['f'] = 'c';
   lookup['g'] = 'v';
   lookup['h'] = 'x';
   lookup['i'] = 'd';
   lookup['j'] = 'u';
   lookup['k'] = 'i';
   lookup['l'] = 'g';
   lookup['m'] = 'l';
   lookup['n'] = 'b';
   lookup['o'] = 'k';
   lookup['p'] = 'r';
   lookup['q'] = 'z';
   lookup['r'] = 't';
   lookup['s'] = 'n';
   lookup['t'] = 'w';
   lookup['u'] = 'j';
   lookup['v'] = 'p';
   lookup['w'] = 'f';
   lookup['x'] = 'm';
   lookup['y'] = 'a';
   lookup['z'] = 'q';

   cin >> n;
   getline(cin, line);
   for (int casen = 0; casen < n; casen++)
   {
      init();
      read();
      solve();
      write(casen + 1);
   }
   return 0;
}
