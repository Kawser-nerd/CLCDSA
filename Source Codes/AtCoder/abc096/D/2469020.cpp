#include <cstdio>
#include <cstdlib>
#include <cstring>

bool matches_condition(int value)
{
  if(value % 5 != 1) {
    return false;
  }
  for(int i = 2; i * i <= value; i++) {
    if(value % i == 0) {
      return false;
    }
  }
  return true;
}

int generate_matched_value(int begin, int end)
{
  for(int i = begin; i < end; i++) {
    if(matches_condition(i)) {
      return i;
    }
  }
  fputs("Nothing found...\n", stderr);
  exit(1);
}

int main()
{
  int n;
  int result[100];

  scanf("%d", &n);

  result[0] = 11;
  for(int i = 1; i < n; i++) {
    result[i] = generate_matched_value(result[i-1]+1, 55555);
  }
  for(int i = 0; i < n; i++) {
    printf("%d", result[i]);
    if(i == n - 1) {
      putchar('\n');
    } else {
      putchar(' ');
    }
  }
  return 0;
}