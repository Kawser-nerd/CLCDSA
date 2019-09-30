#include <cstdio>
#include <cstdlib>
#include <memory.h>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#define base 3002
using namespace std;
#define PI 3.14159265358979323846264338327950288
#define remin(a, b) ((a) = min(a, b))
#define remax(a, b) ((a) = max(a, b))
int T;
int N;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int all[2][6005][2];
int mark[6005][6005];
int point[3][2], s;
int main() {
   int i, j, Case = 1, k, l;
   int area;
   int cnt[3];
   char str[105];
   scanf("%d", &T);
   memset(mark, -1, sizeof(mark));
   while (T --) {
      scanf("%d", &N);
      for (i = 0; i < 6005; i ++) {
	 all[0][i][0] = all[1][i][0] = 1000000000;
	 all[0][i][1] = all[1][i][1] = -1000000000;
      }
      cnt[0] = cnt[1] = base;
      cnt[2] = 0;
      s = 0;
      for (i = 0; i < 6; i ++)
	 point[0][i] = base;
      area = 0;
      while (N --) {
	 scanf("%s", str);
	 scanf("%d", &k);
	 l = strlen(str);
	 while (k --)
	    for (i = 0; i < l; i ++)
	       switch (str[i]) {
		  case 'L':
		     cnt[2] = (cnt[2] + 3) % 4;
		     break;
		  case 'R':
		     cnt[2] = (cnt[2] + 1) % 4;
		     break;
		  case 'F':
		     cnt[0] += dx[cnt[2]];
		     cnt[1] += dy[cnt[2]];
		     area += (cnt[0] - point[(s + 2) % 3][0]) * point[s % 3][1];
		     s ++;
		     point[s % 3][0] = cnt[0];
		     point[s % 3][1] = cnt[1];
		     switch (cnt[2]) {
			case 0:
			   remin(all[0][cnt[1] - 1][0], cnt[0]);
			   remax(all[0][cnt[1] - 1][1], cnt[0]);
			   break;
			case 1:
			   remin(all[1][cnt[0] - 1][0], cnt[1]);
			   remax(all[1][cnt[0] - 1][1], cnt[1]);
			   break;
			case 2:
			   remin(all[0][cnt[1]][0], cnt[0]);
			   remax(all[0][cnt[1]][1], cnt[0]);
			   break;
			case 3:
			   remin(all[1][cnt[0]][0], cnt[1]);
			   remax(all[1][cnt[0]][1], cnt[1]);
			   break;
		     }
		     break;
	       }
      }
      for (i = 0; i < 2; i ++) {
	 area += (cnt[0] - point[(s + 2) % 3][0]) * point[s % 3][1];
	 s ++;
	 point[s % 3][0] = cnt[0];
	 point[s % 3][1] = cnt[1];
      }
      area = abs(area) / 2;
      int ret = -area;
      for (i = -3000; i <= 3000; i ++) {
	 for (j = all[0][i + base][0]; j < all[0][i + base][1]; j ++) {
	    if (mark[i + base][j] < Case)
	       ret ++;
	    mark[i + base][j] = Case;
	 }
	 for (j = all[1][i + base][0]; j < all[1][i + base][1]; j ++) {
	    if (mark[j][i + base] < Case)
	       ret ++;
	    mark[j][i + base] = Case;
	 }
      }
      printf("Case #%d: %d\n", Case ++, ret);
   }
   return 0;
}

