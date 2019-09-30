#include <stdio.h>

  int n, h, w, r, cs, i, j,k;
/*int forbid[20][2];*/
  int times[120][120];

int pc(int a, int b) { 
  if (a<1 || b<1) return 0;
  if (times[a][b]!=-1) return times[a][b];
  times[a][b]=0;
  times[a][b]+=pc(a-2,b-1);
  times[a][b]+=pc(a-1,b-2);
  times[a][b]%=10007;
  return times[a][b];
}

int main () {

  scanf("%d", &n);
  for (cs=1;cs<=n;cs++) {
    scanf("%d%d%d", &h, &w, &r);

    for (i=1;i<=h;i++)
      for (j=1; j<=w; j++)
	times[i][j]=-1;
    for (i=0;i<r;i++) {
      scanf("%d%d", &j, &k);
      times[j][k]=0;
    }
    times[1][1]=1;

    printf("Case #%d: %d\n",cs, pc(h,w)%10007);
  }

  return 0;
}
