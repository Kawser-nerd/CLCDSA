#include <stdio.h>
#include <string.h>

#define MAXLEN 1010

int p[5], used[6], min, k;
char s[MAXLEN], news[MAXLEN];


void try(int d)
{
     int i;
     if (d == k) {
	  for (i = 0; i < strlen(s); i++) {
	       news[(i/k)*k+p[i % k]] = s[i];
	  }
	  int cnt = 1;
	  for (i = 1; i < strlen(s); i++) {
	       if (news[i] != news[i-1])
		    cnt++;
	  }
	  min = (cnt < min)? cnt : min;
     } else {
	  for (i = 0; i < k; i++)
	       if (!used[i]) {
		    used[i] = 1;
		    p[d] = i;
		    try(d+1);
		    used[i] = 0;
	       }
     }
}

int main()
{
     int n, i;
     scanf("%d", &n);
     for (i = 1; i <= n; i++) {
	  scanf("%d\n%s", &k, s);
	  memset(used, 0, sizeof(used));
	  min = strlen(s);
	  try(0);
	  printf("Case #%d: %d\n", i, min);
     }
     
     return 0;
}
