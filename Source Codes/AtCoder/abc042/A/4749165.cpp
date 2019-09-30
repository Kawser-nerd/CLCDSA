#include <stdio.h>

int main() {
  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);

  if ((a == 1) || (b == 1) || (c == 1)) {
    puts("NO");
    return 0;
  }    
  
  if (a*b*c == 175) {
    puts("YES");
  } else {
    puts("NO");
  }
  return 0;
}