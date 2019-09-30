#include <stdio.h>
#include <string.h>

#define MAX_NAME    105
#define MAX_ENGINES 105
#define MAX_QUERY   1005

char e[MAX_ENGINES][MAX_NAME];
char can[MAX_ENGINES];
int q[MAX_QUERY];
int ne, nq;

int num(char *s) {
  int i;
  for (i=0; i<ne; i++) {
    /*printf("(%s) (%s)\n",e[i],s);*/
    if (!strcmp(s, e[i])) return i;
  }
  return -1;
}

int main() {
  int i, j, n, count, remain;
  char tmp[MAX_NAME];
  
  scanf("%d",&n);
  for (i=1; i<=n; i++) {
    scanf("%d",&ne);
    gets(tmp);
    for (j=0; j<ne; j++)
      gets(e[j]);
    scanf("%d",&nq);
    gets(tmp);
    for (j=0; j<nq; j++) {
      gets(tmp);
      q[j] = num(tmp);
    }

    memset(can, 1, sizeof(can));
    count = 0; remain=ne;
    for (j=0; j<nq; j++) {
      if (q[j]>=0 && can[q[j]]) {
	can[q[j]]=0;
	remain--;
      }
      if (remain == 0) {
	count++;
	remain = ne;
	memset(can, 1, sizeof(can));
	can[q[j]]=0;
	remain--;
      }
    }
    
    printf("Case #%d: %d\n", i, count);
  }



  return 0;
}
