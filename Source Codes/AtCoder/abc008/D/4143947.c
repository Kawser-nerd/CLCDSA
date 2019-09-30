#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct WBTNode {
  int lsize;
  int rsize;
  struct WBTNode *parent;
  struct WBTNode *left;
  struct WBTNode *right;
  unsigned long long int val[];
} WBTNode;

WBTNode* newNode (const void *val, const size_t size) {
  WBTNode *r = (WBTNode *) malloc (sizeof (WBTNode) + size);
  r -> lsize = 0;
  r -> rsize = 0;
  r -> parent = NULL;
  r -> left = NULL;
  r -> right = NULL;
  memcpy (r -> val, val, size);
  return r;
}

int getTreeSize (const WBTNode *t) {
  return t == NULL ? 0 : t -> lsize + t -> rsize + 1;
}

int getBias (const WBTNode *t, const int b) {
  if (t == NULL) return 0;
  int l = t -> lsize + 1;
  int r = t -> rsize + 1;
  if (b * l >= r && l <= b * r) {
    return 0;
  }
  return b * l < r ? -1 : 1;
}

void update (WBTNode *t) {
  t -> lsize = getTreeSize (t -> left);
  t -> rsize = getTreeSize (t -> right);
}

int isLeftChild (const WBTNode *t) {
  return t != NULL && t -> parent != NULL && t -> parent -> left == t;
}

void concatL (WBTNode *parent, WBTNode *child) {
  if (child != NULL) {
    child -> parent = parent;
  }
  if (parent != NULL) {
    parent -> left = child;
  }
}

void concatR (WBTNode *parent, WBTNode *child) {
  if (child != NULL) {
    child -> parent = parent;
  }
  if (parent != NULL) {
    parent -> right = child;
  }
}

void replaceChild (WBTNode *parent, const WBTNode *prevChild, WBTNode *nextChild) {
  if (isLeftChild (prevChild)) {
    concatL (parent, nextChild);
  } else {
    concatR (parent, nextChild);
  }
}

WBTNode* rightRotate (WBTNode *v) {
  WBTNode *u = v -> left;
  concatL (v, u -> right);
  replaceChild (v -> parent, v, u);
  concatR (u, v);
  update (v);
  update (u);
  return u;
}

WBTNode* leftRotate (WBTNode *u) {
  WBTNode *v = u -> right;
  concatR (u, v -> left);
  replaceChild (u -> parent, u, v);
  concatL (v, u);
  update (u);
  update (v);
  return v;
}

WBTNode* balance (WBTNode *t) {
  const int b = getBias (t, 3);
  if (b == 0) {
    return t;
  }
  if (b < 0) {
    if (getBias (t -> right, 2) > 0) {
      rightRotate (t -> right);
    }
    return leftRotate (t);
  } else {
    if(getBias (t -> left, 2) < 0){
      leftRotate (t -> left);
    }
    return rightRotate (t);
  }
}

WBTNode* saveTree (WBTNode *t) {
  WBTNode *now = t;
  WBTNode *before = NULL;
  while (now != NULL) {
    update (now);
    before = balance (now);
    now = before -> parent;
  }
  return before;
}

typedef struct MultiSet_WBT {
  WBTNode *root;
  size_t valSize;
  int (*cmp) (const void *, const void *);
} multiset;

multiset* newMultiSet (const size_t size, int (*cmp) (const void *, const void *)) {
  multiset *mset = (multiset *)malloc(sizeof (multiset));
  mset -> root = NULL;
  mset -> valSize = size;
  mset -> cmp = cmp;
  return mset;
}

int getSize (const multiset *set) {
  return getTreeSize (set -> root);
}

WBTNode* getMaxRef (const multiset *set) {
  if (set -> root == NULL) {
    return NULL;
  }
  WBTNode *now = set -> root;
  while (now -> right != NULL) {
    now = now -> right;
  }
  return now;
}

WBTNode* getMinRef (const multiset *set) {
  if (set -> root == NULL) {
    return NULL;
  }
  WBTNode *now = set -> root;
  while (now -> left != NULL) {
    now = now -> left;
  }
  return now;
}

WBTNode* getAtRef (const multiset *set, int k) {
  if (k < 1 || getSize (set) < k) {
    return NULL;
  }
  WBTNode *now = set -> root;
  while (1) {
    int lsize = now -> lsize;
    if (k == lsize + 1){
      return now;
    }
    if (k <= lsize) {
      now = now -> left;
    } else {
      k -= lsize + 1;
      now = now -> right;
    }
  }
}

WBTNode* nextRef(WBTNode *t){
  if (t -> right != NULL) {
    WBTNode *s = t -> right;
    while (s -> left != NULL) {
      s = s-> left;
    }
    return s;
  }
  WBTNode *now = t -> parent;
  WBTNode *before = t;
  while (now != NULL && now -> left != before) {
    before = now;
    now = now -> parent;
  }
  return now;
}

WBTNode* prevRef(WBTNode *t){
  if (t -> left != NULL) {
    WBTNode *s = t -> left;
    while (s -> right != NULL) {
      s = s-> right;
    }
    return s;
  }
  WBTNode *now = t -> parent;
  WBTNode *before = t;
  while (now != NULL && now -> right != before) {
    before = now;
    now = now -> parent;
  }
  return now;
}

WBTNode* insert (multiset *set, const void *val) {
  WBTNode * const in = newNode (val, set -> valSize);
  if (set -> root == NULL) {
    set -> root = in;
    return in;
  }
  int (*cmp) (const void *, const void *) = set -> cmp;
  WBTNode *before = NULL;
  WBTNode *now = set -> root;
  int cmpRes = 0;
  while (now != NULL) {
    before = now;
    cmpRes = cmp (in -> val, now -> val);
    now = cmpRes <= 0 ? now -> left : now -> right;
  }
  if (cmpRes <= 0) {
    concatL (before, in);
  } else {
    concatR (before, in);
  }
  set -> root = saveTree (before);
  return in;
}

void eraseByRef (multiset * const set, WBTNode * const t) {
  if (t == NULL) {
    return;
  }
  if(t -> left == NULL && t -> right == NULL) {
    replaceChild (t -> parent, t, NULL);
    set -> root = saveTree (t -> parent);
    free (t);
  } else if (t -> left == NULL) {
    replaceChild (t -> parent, t, t -> right);
    set -> root = saveTree (t -> right);
    free (t);
  } else if (t -> right == NULL) {
    replaceChild (t -> parent, t, t -> left);
    set -> root = saveTree (t -> left);
    free (t);
  } else {
    WBTNode *max = t -> left;
    while (max -> right != NULL) {
      max = max -> right;
    }
    WBTNode *p = NULL;
    if (max != t -> left) {
      concatR (max -> parent, max -> left);
      t -> left -> parent = NULL;
      p = saveTree (max -> parent);
    } else {
      p = t -> left -> left;
    }
    concatL (max, p);
    concatR (max, t -> right);
    replaceChild (t -> parent, t, max);
    set -> root = saveTree (max);
    free (t);
  }
}

void eraseAt (multiset *set, const int k) {
  if (k < 1 || getSize (set) < k) {
    return;
  }
  eraseByRef (set, getAtRef (set, k));
}

WBTNode* elem (multiset *set, const void *val) {
  WBTNode *r = set -> root;
  int (*cmp) (const void *, const void *) = set -> cmp;
  while (r != NULL) {
    int c = cmp (val, r -> val);
    if (c == 0) return r;
    if (c < 0) {
      r = r -> left;
    } else {
      r = r -> right;
    }
  }
  return NULL;
}

typedef WBTNode Ref;

#define MAX(a,b) ((a)>(b)?(a):(b))

typedef struct point{
  int x,y;
} point;

typedef struct areaVal{
  int a,b,c,d;
  int val;
} area;

int cmpArea(const void *a,const void *b){
  area *p=(area *)a;
  area *q=(area *)b;
  if(p->a!=q->a) return p->a-q->a;
  if(p->b!=q->b) return p->b-q->b;
  if(p->c!=q->c) return p->c-q->c;
  return p->d-q->d;
}

int calc(int a,int b,int c,int d,point *p,int n,multiset *memo){
  Ref *r=elem(memo,&((area){a,b,c,d,0}));
  if(r!=NULL) return ((area *)r->val)->val;
  int max=0;
  for(int i=0;i<n;i++){
    int x=p[i].x;
    int y=p[i].y;
    if(a<=x && x<=b && c<=y && y<=d){
      int local=(b-a)+(d-c)+1;
      local+=calc(a,x-1,c,y-1,p,n,memo);
      local+=calc(a,x-1,y+1,d,p,n,memo);
      local+=calc(x+1,b,c,y-1,p,n,memo);
      local+=calc(x+1,b,y+1,d,p,n,memo);
      max=MAX(max,local);
    }
  }
  insert(memo,&((area){a,b,c,d,max}));
  return max;
}

void run(void){
  int w,h;
  scanf("%d%d",&w,&h);
  int n;
  scanf("%d",&n);
  point p[30];
  int i;
  for(i=0;i<n;i++) scanf("%d%d",&p[i].x,&p[i].y);
  multiset *memo=newMultiSet(sizeof(area),cmpArea);
  int ans=calc(1,w,1,h,p,n,memo);
  printf("%d\n",ans);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:343:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&w,&h);
   ^
./Main.c:345:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:348:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%d%d",&p[i].x,&p[i].y);
                    ^