#include <stdio.h>
#include <string.h>

typedef char string[250];

int n;
string allstr[250];

void init()
{
  n = 0;
}

#define INF 999999

int min(int x, int y)
{
  return ((x < y) ? x : y);
}

int count(int i, char *str)
{
  int result = 0;
  for (; str[i]; ++i) {
    result += (str[i] == '/');
  }
  return result;
}

int catezice(char *str, char *deja)
{
  int ls = strlen(str);
  int ld = strlen(deja);
  int i;
  int result = INF;

  for (i = 0; i < min(ls, ld); ++i) {
    if (str[i] != deja[i]) {
      break;
    }
    if (str[i] == '/') {
      result = min(result, count(i, str));
    }
  }
  if (i < min(ls, ld)) {
    result = min(result, result);
  } else if (ld == ls) { 
    result = min(result, 0);
  } else if (ld < ls && str[ld] == '/') {
    result = min(result, count(ld, str));
  } else if (ls < ld && deja[ls] == '/') {
    result = min(result, 0);
  }
  return result;
}

int add(char *str)
{
  int i, result = count(0, str);

  for (i = 0; i < n; ++i) {
    //    printf("compare %s   AND   %s\n", str, allstr[i]);
    result = min(result, catezice(str, allstr[i]));
    //    printf("result  %s   AND   %s = %d\n", str, allstr[i], catezice(str, allstr[i]));
  }
  strcpy(allstr[n++], str);
  return result;
}

int solve()
{
  char string[150];
  int result = 0;
  int i, N, M;

  scanf("%d %d\n", &N, &M);
  for (i = 0; i < N; ++i) {
    fgets(string, 150, stdin);
    string[strlen(string) - 1] = 0;
    add(string);
  }
  for (i = 0; i < M; ++i) {
    fgets(string, 150, stdin);
    string[strlen(string) - 1] = 0;
    //    printf("temp %s\n", string);
    result += add(string);
    //    printf("temp %d\n", result);
  }
  return result;
}

int main()
{
  int T, t;
  scanf("%d\n", &T);
  for (t = 1; t <= T; ++t) {
    init();
    printf("Case #%d: %d\n", t, solve());
  }
  return 0;
}
