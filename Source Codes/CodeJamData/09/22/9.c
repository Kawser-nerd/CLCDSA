#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int less(const void *a, const void *b)
{
  return *(char *)a - *(char *)b;
}

char *
next(char *buffer)
{
  int numbers = strlen(buffer);
  int i,j,k = -1;

  for (j = numbers - 2; j >= 0; j--) {
    char c = '9' + 1;
    k = -1;
    for (i = j + 1; i < numbers; i++) {
      if (buffer[i] < c && buffer[i] > buffer[j]) { c = buffer[i]; k = i; }
    }
    if (k >= 0) break;
  }
  if (k >= 0) {
    char c = buffer[j]; 
    buffer[j] = buffer[k]; buffer[k] = c;
    qsort(buffer+j+1, numbers - j - 1, 1, less);
  } else {
    static char newbuf[100];
    for (i = 0, j = 0; i < numbers; i++) {
      if (buffer[i] != '0') newbuf[j++] = buffer[i];
    }
    qsort(newbuf, j, 1, less);
    k = numbers - j + 1;
    memmove(newbuf + k + 1, newbuf + 1, j - 1);
    memset(newbuf + 1, '0', k);
    newbuf[numbers + 1] = 0;
    return newbuf;
  }
  return buffer;
}

int
main()
{
  int cases, i;
  char buffer[100];
  scanf("%d\n", &cases);
  
  for (i = 1; i <= cases; i++) {
    gets(buffer);
    printf("Case #%d: %s\n", i, next(buffer));
  }
  return 0;
}

