#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<map>
#include<set>
using namespace std;

#define MAXN 1000

int n;
int children[MAXN][MAXN], nchildren[MAXN];
int parent[MAXN];
int depth[MAXN];


char moo[MAXN][MAXN];

int m;

int getvalue(char *s){
  for(int i = 0; i < m; i++){
    if (!strcmp(s, moo[i]))
      return i;
  }
  strcpy(moo[m++], s);
  return m-1;
}

int root;

void search(int node, int d=0){
  depth[node] = d;
  for(int i = 0; i < nchildren[node]; i++)
    search(children[node][i], d+1);
}

int order[MAXN];
int best[MAXN];

int compare (const void *a, const void *b){
  return depth[(*((int*) b))] - depth[(*((int *) a))];
}

int min(int a, int b){
  return a < b ? a : b;
}
int max(int a, int b){
  return a > b ? a : b;
}

int getbest(int node){
  //printf("Getting best %s\n", moo[node]);
  int childmax = 0;
  for(int i = 0; i < nchildren[node]; i++){
    childmax = max(childmax, best[children[node][i]]);
  }
  int childmin = childmax;
  for(int i = 0; i < nchildren[node]; i++){
    childmin = min(childmin, best[children[node][i]]);
  }
  int ans =  max(max(childmax, nchildren[node] - 1 + childmin),
		 nchildren[node] + 1);
  //printf("%d %d %d %d\n", childmax, childmin, nchildren[node], ans);
  return ans;
}

int main(){
  int ncases;
  int x;
  int p, c;
  char name[40];
  scanf("%d", &ncases);
  for(int ncase = 0; ncase < ncases; ncase++){
    printf("Case #%d: ", ncase+1);
    memset(moo, 0, sizeof(moo));
    memset(best, 0, sizeof(best));
    memset(nchildren, 0, sizeof(nchildren));
    memset(children, 0, sizeof(children));
    scanf("%d\n", &n);
    m = 0;
    memset(parent, -1, sizeof(parent));
    for(int i = 0; i < n; i++){
      scanf("%s %d", name, &x);
      p = getvalue(name);
      for(int j = 0; j < x; j++){
	scanf("%s", name);
	if (name[0] >= 'A' && name[0] <= 'Z') {
	  c = getvalue(name);
	  children[p][nchildren[p]++] = c;
	  parent[c] = p;
	}
      }
    }
    for(x = 0; x < m; x++){
      if (parent[x] == -1)
	break;
    }
    root = x;
    for(x = 0; x < m; x++){
      order[x] = x;
    }
    search(root);
    qsort(order, m, sizeof(order[0]), compare);
    for(int i = 0; i < m; i++){
      best[order[i]] = getbest(order[i]);
    }
    printf("%d\n", best[root]);
  }
  return 0;
}
