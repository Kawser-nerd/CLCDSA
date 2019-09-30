#include <stdio.h>

int x[4242], y[4242];
int a[4242], ans[4242], mx, n;
bool was[4242];

bool lies(int p, int q, int r) {
  int a = y[q]-y[p];
  int b = x[p]-x[q];
  int c = -a*x[p]-b*y[p];
  int z = a*x[r]+b*y[r]+c;
  if (z != 0) return false;
  int smul = (x[p]-x[r]) * (x[q]-x[r]) + (y[p]-y[r]) * (y[q]-y[r]);
  if (smul > 0) return false;
  return true;
}

bool intersect(int p, int q, int r, int s) {
  int a = y[q]-y[p];
  int b = x[p]-x[q];
  int c = -a*x[p]-b*y[p];
  int z1 = a*x[r]+b*y[r]+c;
  int z2 = a*x[s]+b*y[s]+c;
  if (z1 < 0 && z2 > 0 || z1 > 0 && z2 < 0) {
    a = y[s]-y[r];
    b = x[r]-x[s];
    c = -a*x[r]-b*y[r];
    z1 = a*x[p]+b*y[p]+c;
    z2 = a*x[q]+b*y[q]+c;
    if (z1 < 0 && z2 > 0 || z1 > 0 && z2 < 0) return true;
    return false;
  }
  return false;
}

void go(int v) {
  if (v == n) {
    a[n] = a[0];
    for (int i=0;i<n;i++)
      for (int j=i+2;j<n;j++)
         if (intersect(a[i], a[i+1], a[j], a[j+1])) return;
    for (int i=0;i<n;i++)
      for (int j=0;j<n;j++)
        if (j != i && j != i+1 && j != i+1-n)
          if (lies(a[i], a[i+1], a[j])) return;
    int area = 0;
    for (int i=0;i<n;i++) area += (x[a[i]]-x[a[i+1]]) * (y[a[i]]+y[a[i+1]]);
    if (area < 0) area = -area;
    if (area > mx) {
      mx = area;
      for (int i=0;i<n;i++) ans[i] = a[i];
    }
    return;
  }
  for (int i=0;i<n;i++)
    if (!was[i]) {
      a[v] = i;
      was[i] = true;
      go(v+1);
      was[i] = false;
    }
}

int main() {
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  int tt;
  scanf("%d", &tt);
  for (int qq=1;qq<=tt;qq++) {
    printf("Case #%d:", qq);
    scanf("%d", &n);
    for (int i=0;i<n;i++) scanf("%d %d", x+i, y+i);
    for (int i=0;i<n;i++) was[i] = false;
    a[0] = 0;
    was[0] = true;
    mx = -1;
    for (int i=0;i<n;i++) ans[i] = -1;
    go(1);
    for (int i=0;i<n;i++) printf(" %d", ans[i]);
    printf("\n");
    fflush(stdout);
  }
  return 0;
}
