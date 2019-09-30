#include <stdio.h>
#include <assert.h>
#include <string.h>

#define MAXS 101

char s1[MAXS];
char s2[MAXS]; 

char t[MAXS];
char r[MAXS];
char ok[MAXS];
const char *S;

int set_char (int v, int p, int l) {
  int e = 0;
  int i;
  t[v] = p;
  for (i = v; i < l; i++) {
    e += t[i] * t[v + l - 1 - i]; 
  }
  if (e  >= 10) { 
    return 0;
  }
  r[v + l - 1] = e;
  if (!ok[v + l] && r[v + l - 1] > S[v + l - 1]) {
    return 0;
  }
  ok[v + l - 1] = ok[v + l] || (r[v + l - 1] < S[v + l - 1]);
  return 1;
}

int che[MAXS];
int check (int l) {
  int i;
  if (ok[2 * l - 1]) {
    return 1;
  }
  int eq = 1;
  int j;
  for (i = 2 * l - 2; i >= 0; i--) {
    int z = 0;
    for (j = 0; j < l && j <= i; j++) if (i - j < l) {
      z += t[j] * t[i - j];
    }
    assert (z < 10);
    if (eq && z > S[i]) {
      return 0;
    }
    if (z < S[i]) {
      eq = 0;
    }
  }
  return 1;
}

long long poisk (int p, int l) {
  if (2 * p < l - 1) {
    int i;
    for (i = p; i >= 0; i --) {
      if (!set_char (i, t[l - 1 - i], l)) {
        return 0;
      }
    }
    if (!check (l)) {
      return 0;
    }
    return 1;
  }
  long long res = 0;
  int i;
  for (i = ((p == l - 1) ? 1 : 0); i < 4; i++) {
    if (set_char (p, i, l)) {
      res += poisk (p - 1, l);
    } else {
      return res;
    }
  }
  return res;
}

long long count (char *s) {
  int n = strlen (s);
  int i;
  for (i = 0; 2 * i < n; i++) {
    char c = s[i]; s[i] = s[n - 1 - i]; s[n - 1 - i] = c;
  }
  for (i = 0; i < n; i++) {
    s[i] -= '0';
  }
  S = s;

  int l;
  long long res = 0;
  for (l = 1; 2 * l - 1 <= n; l++) {
    if (2 * l - 1 < n) {
      ok[2 * l - 1] = 1;
    } else {
      ok[2 * l - 1] = 0;
    }
    for (i = 0; i <= n; i++) {
      r[i] = 0;
    }
    for (i = 0; i < l; i++) {
      t[i] = 0;
    }

    res += poisk (l - 1, l);
  }
  return res;
}

void solve (void) {
  assert (scanf ("%s %s\n", s2, s1) == 2);
  int cc = strlen (s2);
  cc --;
  s2[cc] --;
  while (s2[cc] == '0' - 1) {
    s2[cc] += 10;
    s2[--cc] --;
  }
  printf ("%lld\n", count (s1) - count (s2));
}

int main () {
  int _;
  assert (scanf ("%d\n", &_) > 0);
  int __;
  for (__ = 0; __ < _; __++) {
    printf ("Case #%d: ", __ + 1);
    solve ();
  }
  return 0;
}
