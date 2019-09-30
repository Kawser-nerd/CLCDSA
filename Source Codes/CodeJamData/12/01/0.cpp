#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const char *a = "y qeez ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
const char *b = "a zooq our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";

int main() {
  int tc; scanf("%d\n", &tc);
  for(int tci = 0; tci < tc; tci++) {
    static char str[109]; scanf("%[a-z ]\n", str);
    for(int i = 0; str[i]; i++) {
      str[i] = b[find(a, a+133, str[i])-a];
    }
    printf("Case #%d: %s\n", tci+1, str);
  }
  return 0;
}
