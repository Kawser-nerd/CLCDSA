#include <cstdio>
#include <cstdlib>
#include <memory.h>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <queue>
#include <cassert>
using namespace std;
#define PI 3.14159265358979323846264338327950288
struct node {
   map <string, node *> sons;
};
node *root;
int T;
int N, M;
char tmp[100005];
int ans = 0;
void insert(node *cnt, char *tmp) {
   int i;
   if (tmp[0] == 0)
      return;
   assert(tmp[0] == '/');
   string str;
   for (i = 1; tmp[i] != '/' && tmp[i] != 0; i ++)
      str += tmp[i];
   if (cnt -> sons.find(str) == cnt -> sons.end()) {
      ans ++;
      struct node *tmp2 = new node();
      cnt -> sons[str] = tmp2;
   }
   insert(cnt -> sons[str], tmp + i);
}
int main() {
   int i;
   int Case = 1;
   scanf("%d", &T);
   while (T --) {
      scanf("%d%d", &N, &M);
      root = new node();
      for (i = 0; i < N; i ++) {
	 scanf("%s", tmp);
	 insert(root, tmp);
      }
      ans = 0;
      for (i = 0; i < M; i ++) {
	 scanf("%s", tmp);
	 insert(root, tmp);
      }
      printf("Case #%d: %d\n", Case ++, ans);
   }
   return 0;
}

