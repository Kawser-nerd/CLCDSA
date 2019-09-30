#include<stdio.h>
#include<assert.h>

typedef struct __node {
  double weight;
  char feat[16];
  int left, right;
} node;

int ptr;
node pool[4096];
char a[16];
char f[100][16];
int n;
double p;

char buf;
char nextchar()
{
  char ch;
  if(buf != EOF) {
    ch = buf;
    buf = EOF;
    return ch;
  }
  while(isspace(ch = getchar())) { }
  return ch;
}

void parse()
{
  node *p = &pool[ptr];
  char c;
  int i = 0;
  assert(nextchar() == '(');
  scanf("%lf", &p->weight);
  p->left = p->right = -1;
  c = nextchar();
  if(c == ')') return;
  do {
    p->feat[i++] = c;
  } while(!isspace(c = nextchar()) && c != '(');
  p->feat[i] = '\0';
  if(c == '(') buf = c;
  p->left = ++ptr;
  parse();
  p->right = ++ptr;
  parse();
  assert(nextchar() == ')');
  return;
}

int has(char *s)
{
  int i;
  for(i = 0; i < n; ++i)
    if(!strcmp(s, f[i]))
      return 1;
  return 0;
}

void rec(int x)
{
  p *= pool[x].weight;
  if(pool[x].left == -1)
    return;
  if(has(pool[x].feat)) {
    rec(pool[x].left);
  } else {
    rec(pool[x].right);
  }
}

int main()
{
  int sc, N;
  scanf("%d", &N);
  for(sc = 1; sc <= N; ++sc) {
    int L, A, i, j;
    scanf("%d", &L);
    ptr = 0;
    buf = EOF;
    parse();
    printf("Case #%d:\n", sc);
    scanf("%d", &A);
    for(i = 0; i < A; ++i) {
      scanf("%s%d", a, &n);
      for(j = 0; j < n; ++j)
	scanf("%s", f[j]);
      p = 1.0;
      rec(0);
      printf("%.9lf\n", p);
    }
  }
  return 0;
}
