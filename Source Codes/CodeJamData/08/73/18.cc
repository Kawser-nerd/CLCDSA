#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<map>
#include<set>
#include<queue>
#include<vector>
using namespace std;

#define MAXM 10000
#define MAXQ 30

double logvals[MAXQ][4];
int m, q;

int compare(const void *a, const void *b){
  double d = *((double *)a) - *(double *)b;
  if (d < 0)
    return 1;
  else if (d > 0)
    return -1;
  else
    return 0;
}

struct state{
  long long int low, high;
  double value;
  state(long long int l, long long int h, double v){
    low = l;
    high = h;
    value = v;
  }
  int get(int i){
    if (i >= 15){
      return (high >> (2*(i-15))) & 3;
    } else {
      return (low >> 2*(i)) & 3;
    }
  }
  state decrease(int i){
    int old = get(i);
    double diff = logvals[i][old+1] - logvals[i][old];
    if (i >= 15){
      return state(low, high + (1LL << (2 * (i-15))), value+diff);
    } else {
      return state(low  + (1LL << (2 * (i))) , high, value+diff);
    }
  }
};

struct ltstr
{
  bool operator()(const state s1, const state s2) const
  {
    return s1.value < s2.value;
  }
};


#define TABLESIZE 1000007
struct Hashnode{
  long long int a, b;
  Hashnode *next;
} *table[TABLESIZE];

int addHash(const state s){
  Hashnode *p;
  int h = ((s.low * 103LL + s.high) % TABLESIZE);
  h = (h + TABLESIZE)%TABLESIZE;
  for(p = table[h]; p != NULL; p=p->next) {
    if (p->a == s.low && p->b == s.high)
      return 1;
  }
  //printf("Done\n");
  p = new Hashnode;
  p->next = table[h];
  p->a = s.low;
  p->b = s.high;
  table[h] = p;
  return 0;
}

double ans = 0;

void search(){
}

int main(){
  int ncases;
  double v;
  scanf("%d", &ncases);
  for(int ncase = 0; ncase < ncases; ncase++){
    printf("Case #%d: ", ncase+1);
    scanf("%d %d\n", &m, &q);
    double maxp = 0;
    for(int x = 0; x < q; x++){
      for(int j = 0; j < 4; j++){
	scanf("%lf", &v);
	if (v < 1e-9)
	  logvals[x][j] = -1000000;
	else
	  logvals[x][j] = log(v);
      }
      qsort(logvals[x], 4, sizeof(logvals[x][0]), compare);
      maxp += logvals[x][0];
    }
    if (q < 10 && m >= 1LL << (2*q)) {
      printf("1.0\n");
      continue;
    }
    //printf("MOO\n");
    priority_queue<state, vector<state>, ltstr> Q;
    for(int i = 0; i < TABLESIZE; i++){
      Hashnode *q = NULL;
      for (Hashnode *p = 0; p != NULL; p = p->next) {
	if (q)
	  delete q;
	q = p;
      }
      if (q)
	delete q;	
    }
    memset(table, 0, sizeof(table));
    state start(0, 0, maxp);
    Q.push(start);
    ans = 0;
    for(int i = 0; i < m; i++){
      state next = Q.top();
      Q.pop();
      ans += exp(next.value);
      for(int i = 0; i < q; i++){
	if (next.get(i) == 3)
	  continue;
	state possible = next.decrease(i);
	if (!addHash(possible)) {
	  Q.push(possible);
	}
      }
    }
    printf("%lf\n", ans);
    fflush(stdout);
  }

  return 0;
}
