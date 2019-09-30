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
using namespace std;
#define PI 3.14159265358979323846264338327950288
struct node {
   double prob;
   string name;
   node *left, *right;
};
int T, L, N, s;
node *rroot;
char all[8005];
set <string> cnt;
int get(node* &root) {
   int i;
   root = new node;
   s ++;
   sscanf(all + s, "%lf", &root -> prob);
   while (all[s] == '.' || all[s] >= '0' && all[s] <= '9')
      s ++;
   if (all[s] == ')') {
      s ++;
      root -> left = root -> right = 0;
      return 0;
   }
   root -> name = "";
   while (all[s] != '(')
      root -> name += all[s ++];
   get(root -> left);
   get(root -> right);
   s ++;
}
double solve(node *root) {
   double ret = 1;
   while (root -> left || root -> right) {
      ret *= root -> prob;
      if (cnt.find(root -> name) != cnt.end())
	 root = root -> left;
      else
	 root = root -> right;
   }
   ret *= root -> prob;
   return ret;
}
int disp(node *root) {
   if (root -> left || root -> right) {
      disp(root -> left);
      disp(root -> right);
   }
   delete root;
   return 0;
}
int main() {
   int i, j, Case = 1;
   scanf("%d", &T);
   while (T --) {
      scanf("%d", &L);
      j = 0;
      while (getchar() != '\n');
      while (L --) {
	 fgets(all + j, 85, stdin);
	 while (all[j])
	    j ++;
      }
      s = 0;
      char tmp[8005];
      for (i = 0; i < j; i ++)
	 if (all[i] > ' ')
	    tmp[s ++] = all[i];
      memcpy(all, tmp, sizeof(tmp));
      s = 0;
      get(rroot);
      printf("Case #%d:\n", Case ++);
      scanf("%d", &N);
      while (N --) {
	 scanf("%*s");
	 scanf("%d", &i);
	 cnt.clear();
	 while (i --) {
	    scanf("%s", tmp);
	    cnt.insert(string(tmp));
	 }
	 printf("%.8lf\n", solve(rroot));
      }
      disp(rroot);
   }
   return 0;
}

