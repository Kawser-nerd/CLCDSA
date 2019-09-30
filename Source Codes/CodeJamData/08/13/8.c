#include <stdio.h>

int num[31] = {1, 5, 27, 143, 751, 935, 607, 903, 991, 335,
	       47, 943, 471, 55, 447, 463, 991, 95, 607, 263,
	       151, 855, 527, 743, 351, 135, 407, 903, 791, 135, 647};

int main()
{
     int t, n, i;
     scanf("%d", &t);
     for (i = 1; i <= t; i++) {
	  scanf("%d", &n);
	  printf("Case #%d: ", i);
	  if (num[n] < 10)
	       printf("00%d\n", num[n]);
	  else if (num[n] < 100)
	       printf("0%d\n", num[n]);
	  else
	       printf("%d\n", num[n]);
     }
     
     return 0;
}
