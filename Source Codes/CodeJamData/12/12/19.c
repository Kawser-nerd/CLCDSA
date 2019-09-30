#include <stdio.h>


int main(int argc, const char *argv[])
{
  int t, i, a, b, n, star, time,j ,count;
  int max, max_i;
  int level[1001][4];
  scanf("%d", &t);
  for ( i = 0 ; i < t ; i++) {
	scanf("%d", &n);
	for ( j = 0 ; j < n ; j++ ) {
	  scanf("%d %d", &level[j][0], &level[j][1]);
	  level[j][2] = 0;
	  level[j][3] = 0;
	}
	star = 0;
	time = 0;
	while (1) {
	  count = 0;
	  for (j = 0 ; j < n ; j++) {
		if (star >= level[j][1] && level[j][3] == 0) {
		  count++;
		  star++;
		  time++;
		  level[j][3] = 1;
		  if (level[j][2] == 0) {
			star++;
			level[j][2] = 1;
		  }
		}
	  }

	  if (count == 0) {
		max_i = -1;
		max = -1;

		for (j = 0 ; j < n ; j++) {
		  if (star >= level[j][0] && level[j][2] == 0) {
			if (max <= level[j][1]) {
			  max = level[j][1];
			  max_i = j;
			}
		  }
		}

		if (max_i != -1) {
		  star++;
		  time++;
		  level[max_i][2] = 1;
		  count++;
		}
	  }

	  if (count == 0)  {
		printf("Case #%d: Too Bad\n", i +1);
		break;
	  } else if (star == 2 * n) {
		printf("Case #%d: %d\n", i + 1, time);
		break;
	  }
	}
  }
  return 0;
}
