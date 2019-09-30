#include <stdio.h>

#define MAXN 201
#define MAXLEN 200

int n, m;
int cnt;
char paths[MAXN][MAXLEN];

int common_prefix(char *s, char *t) {
  int a = 0;

  while (*s != 0 && *s == *t) {
    ++a; ++s; ++t;
  }

  if ( (*s == 0 || *s == '/') && *t != 0 && *t != '/' 
       || (*t == 0 || *t == '/') && *s != 0 && *s != '/')
    --a;
  return a;
}

int main() {
  int t, i, j, k, p, max;

  scanf("%d\n", &t);
  for (i = 1; i <= t; ++i) {
    scanf("%d %d\n", &n, &m);
    cnt = 0;

    for (j = 0; j < n; ++j)
      gets(paths[j]);
    m += n;
    for (j = n; j < m; ++j) {
      gets(paths[j]);
      max = 0;
      for (k = 0; k < j; ++k) {
	p = common_prefix(paths[j], paths[k]);
	if (p > max)
	  max = p;
      }

      if (paths[j][max] != '\0') {
	++cnt;
	for (p = max + 1; paths[j][p]; ++p)
	  if (paths[j][p] == '/')
	    ++cnt;
      }
    }

    printf("Case #%d: %d\n", i, cnt);
  }

  return 0;
}
