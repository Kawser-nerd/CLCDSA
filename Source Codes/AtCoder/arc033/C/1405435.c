#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static unsigned x = 123456789;
static unsigned y = 362436069;
static unsigned z = 521288629;
static unsigned w = 88675123;

unsigned xorShift(void) {
  unsigned t;

  t = x ^ (x << 11);
  x = y; y = z; z = w;
  return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
}

typedef struct node {
  int val;
  struct node *ch[2];
  int pri;
  int cnt; //???????
  int sum; //???????
}node;

int count(node *t) {return t == NULL ? 0: t->cnt;}
int sum(node *t) {return t == NULL ? 0: t->sum;}

node *make_node(int v, double p) {
  node *ret = (node*) malloc(sizeof(node));
  if (ret == NULL) {
		printf("malloc error\n");
		exit(-1);
	}
  ret->val = v, ret->pri = p, ret->cnt = 1, ret->sum = v;
  //printf("make_a\n");
  ret->ch[0] = ret->ch[1] = NULL;
  //printf("make_b\n");
  return ret;
}

node *update(node *t) {
  t->cnt = count(t->ch[0]) + count(t->ch[1]) + 1;
  t->sum = sum(t->ch[0]) + sum(t->ch[1]) + t->val;
  return t;
}

// b=0?????b=1????
node *rotate(node *t, int b) {
  node *s = t->ch[1-b];
  t->ch[1-b] = s->ch[b];
  s->ch[b] = t;
  update(t);
  update(s);
  return s;
}

node *insert(node *t, int val, int pri) {
  //printf("%d %d %d", t->val, val, pri);
  if(t == NULL) return make_node(val, pri);
  else if(val == t->val) return t;
  else if(val < t->val) {
    t->ch[0] = insert(t->ch[0], val, pri);
    if(t->pri > t->ch[0]->pri) {
      t = rotate(t, 1);
    }
  } else{
    t->ch[1] = insert(t->ch[1], val, pri);
    if(t->pri > t->ch[1]->pri) {
      t = rotate(t, 0);
    }
  }
  return update(t);
}

node *erase(node *t, int x) {
  if (t->val == x) {
    if (t->ch[0] && t->ch[1]) {
      if (t->ch[0]->pri < t->ch[1]->pri) {
        t = rotate(t, 1);
        t->ch[1] = erase(t->ch[1], x);
        return update(t);
      } else {
        t = rotate(t, 0);
        t->ch[0] = erase(t->ch[0], x);
        return update(t);
      }
    } else {
      return t->ch[0] ? t->ch[0] : t->ch[1];
    }
  } else if (x < t->val) {
    t->ch[0] = erase(t->ch[0], x);
  } else {
    t->ch[1] = erase(t->ch[1], x);
  }
  return update(t);
}

int level(node *t, int k) {
  //printf("%d %d\n", t->val, k);
  if(k < count(t->ch[0])) return level(t->ch[0], k);
  if(k == count(t->ch[0])) return t->val;
  return level(t->ch[1], k-count(t->ch[0])-1);
}

void print_tree(node *t) {
  if(t == NULL) return;
  print_tree(t->ch[0]);
  printf("%d ", t->val);
  print_tree(t->ch[1]);
}

void free_tree(node *t) {
  if(t == NULL) return;
	free_tree(t->ch[0]);
  free_tree(t->ch[1]);
	free(t);
}

int main() {
  int n;
  scanf("%d", &n);
  node *root = NULL;
  for(int i=0; i<n; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    double p = xorShift();
    if(a == 1) {
      //printf("%lf", p);
      root = insert(root, b, p);
    } else if(a == 2){
      b--;
      int r = level(root, b);
      printf("%d\n", r);
      root = erase(root, r);
    } else {
      exit(-1);
    }
    /*printf("tree:");
    print_tree(root);
    printf("\n");*/
  }

  free_tree(root);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:122:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &n);
   ^
./Main.c:126:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &a, &b);
     ^