#undef DEBUG

#ifdef DEBUG
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...) do ; while(0)
#define NDEBUG
#endif

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#undef ANALYZE

#define MAX 200
char fwd[26], rev[26];
char g[MAX], s[MAX];

int main ()
{
  int tests, i;

  scanf("%d\n", &tests);

#ifdef ANALYZE
  for (i=0; i<26; i++)
    fwd[i] = rev[i] = '?';
#else
  strcpy(fwd, "ynficwlbkuomxsevzpdrjgthaq");
  for (i=0; i<26; i++)
    rev[fwd[i] - 'a'] = i + 'a';
#endif

  for (int test=1; test<=tests; test++) {
    // input
    fgets(g, MAX, stdin);
#ifdef ANALYZE
    fgets(s, MAX, stdin);
    // calc mapping
    for (i=0; g[i] != '\0'; i++)
      if ('a' <= g[i] && g[i] <= 'z') {
        if (rev[g[i] - 'a'] == '?') {
          rev[g[i] - 'a'] = s[i];
          assert('a' <= s[i] && s[i] <= 'z');
          fwd[s[i] - 'a'] = g[i];
        }
        else if (rev[g[i] - 'a'] != s[i])
          fprintf(stderr, "%c rev translated as %c and now %c\n",
                  g[i], rev[g[i] - 'a'], s[i]);
      }
    // print mapping
    printf("Case #%d: ", test);
    for (i=0; i<26; i++)
      printf("%c", fwd[i]);
    printf("\n");
#else
    // translate
    for (i=0; g[i] != '\0'; i++)
      if ('a' <= g[i] && g[i] <= 'z')
        s[i] = rev[g[i] - 'a'];
      else
        s[i] = g[i];
    s[i] = '\0';
    // output
    printf("Case #%d: %s", test, s);
#endif
  }
  return 0;
}
