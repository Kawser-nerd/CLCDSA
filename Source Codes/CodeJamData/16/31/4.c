#include <stdio.h>
int v[27];
int vv[2];
int n;
char r[100000];
int ri;
int chk() {
  int m = 26, s = 0;
  vv[1] = vv[0] = 26;
  for (int i = 0; i < n; ++i) {
    if (v[m] < v[i])
      m = i;
    s += v[i];
    if (v[vv[0]] <= v[i])
      vv[1] = vv[0], vv[0] = i;
    else if (v[vv[1]] <= v[i])
      vv[1] = i;
  }
  if (s == 0)
    return 2;
  else if (s >= v[m] && s > 1)
    return 1;
  else
    return 0;
}

int rec() {
  int c = chk();
  if (c == 2)
    return 1;
  if (c == 0)
    return 0;
  int a = vv[0], b = vv[1];
  if (v[a] > 0 && v[b] > 0) {
    --v[a];
    --v[b];
    r[ri++] = ' ';
    r[ri++] = 'A' + a;
    r[ri++] = 'A' + b;
    if (rec())
      return 1;
    ri -= 3;
    ++v[a];
    ++v[b];
  }
  if (v[a] > 1) {
    --v[a];
    --v[a];
    r[ri++] = ' ';
    r[ri++] = 'A' + a;
    r[ri++] = 'A' + a;
    if (rec())
      return 1;
    ri -= 3;
    ++v[a];
    ++v[a];
  }
  if (v[a] > 0) {
    --v[a];
    r[ri++] = ' ';
    r[ri++] = 'A' + a;
    if (rec())
      return 1;
    ri -= 2;
    ++v[a];
  }
  return 0;
}

int main() {
  int Ti, Tn;
  scanf("%d", &Tn);
  for (Ti = 1; Ti <= Tn; ++Ti) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
      scanf("%d", v + i);
    printf("Case #%d: ", Ti);
    rec();
    r[ri] = '\0';
    printf("%s\n", r);
    ri = 0;
  }
}