#include <stdio.h>

#define ML 4096
static char buf[ML*100];
static int sp;
static float weight[1000];
static char feature[1000][1000];
static int right[1000], left[1000];
static char *cur;
static char *fp[1000];

int readnode()
{
  int c;

  int csp = sp;
  if (*cur == '(') {
    cur++;
    while (*cur == ' ') cur++;
    sscanf(cur, "%f", &weight[csp]);
    sp++;
    while ((*cur < 'a' || *cur > 'z') && *cur != '(' && *cur != ')') cur++;
    if (*cur != ')') {
      c = 0;
      while (*cur >= 'a' && *cur <= 'z') feature[csp][c++] = *(cur++);
      feature[csp][c++] = '\0';
      while (*cur == ' ') cur++;
      right[csp] = readnode();
      while (*cur == ' ') cur++;
      left[csp] = readnode();
      while (*cur == ' ') cur++;
    }
    if (*cur != ')') {
      fprintf(stderr, "err1\n");
      return -1;
    }
    cur++;
    return csp;
  } else {
    fprintf(stderr, "err2%s\n", cur);
    return -1;
  }
}

int main()
{
  int num, base;
  int i, j, k, n;
  int ll, nf;
  float p;

  fgets(buf, ML, stdin);
  sscanf(buf, "%d", &num);

  for (n = 0; n < num; n++) {
    sp = 0;
    for (i = 0; i < 1000; i++) feature[i][0] = 0;
    fgets(buf, ML, stdin);
    sscanf(buf, "%d", &ll);
    cur = &buf[0];
    for (i = 0; i < ll; i++) {
      fgets(cur, ML, stdin);
      while (*cur != '\r' && *cur != '\n') cur++;
      *cur++ = ' ';
    }
    cur = &buf[0];
    readnode();

    fgets(buf, ML, stdin);
    sscanf(buf, "%d", &ll);
    printf("Case #%d:\n", n+1);
    for (i = 0; i < ll; i++) {
      fgets(buf, ML, stdin);
      sscanf(buf, "%d", &ll);
      cur = &buf[0];
      while (*cur != ' ') cur++;
      cur++;
      sscanf(cur, "%d", &nf);
      for (j = 0; j < nf; j++) {
	while (*cur != ' ') cur++;
	*cur = '\0';
	cur++;
	fp[j] = cur;
      }
      while (*cur != ' ' && *cur != '\r' && *cur != '\n') cur++;
      *cur = '\0';

      k = 0;
      p = 1.0;
      while (1) {
	p *= weight[k];
	if (feature[k][0] == 0) break;
	for (j = 0; j < nf; j++)
	  if (strcmp(feature[k], fp[j]) == 0) break;
	if (j < nf) k = right[k];
	else k = left[k];
      }
      printf("%.7f\n", p);
    }
  }

  return 0;
}
