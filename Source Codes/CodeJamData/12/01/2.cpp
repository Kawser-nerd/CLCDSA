#include <cassert>
#include <cstdio>
#include <map>
#include <set>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

const char *s[4] = 
{"ejp mysljylc kd kxveddknmc re jsicpdrysi",
"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
"de kr kd eoya kw aej tysr re ujdr lkgc jv",
"y qee"};

const char *t[4] = 
{"our language is impossible to understand",
"there are twenty six factorial possibilities",
"so it is okay if you want to just give up",
"a zoo"};

int a[150], b[150];
char g[1000];

int main(void) {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; s[i][j]; j++) {
      a[s[i][j]] = t[i][j];
      b[t[i][j]] = 1;
    }
  }

  int x = 0;
  for (int i = 'a'; i <= 'z'; i++) {
    if (!b[i]) {
      assert (!x);
      x = i;
    }
  }

  for (int i = 'a'; i <= 'z'; i++) {
    if (!a[i]) {
      assert (x);
      a[i] = x, x = 0;
    }

    assert (a[i]);
  }

  int tn, nt;
  scanf("%d\n", &nt);
  for (tn=1; tn<=nt; tn++) {
    printf ("Case #%d: ", tn);
    gets (g);
    for (int i = 0; g[i]; i++)
      g[i] = a[g[i]];
    puts (g);
  }

  return 0;
}
