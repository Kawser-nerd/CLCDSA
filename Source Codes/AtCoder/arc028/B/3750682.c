#include<stdio.h>
#include<string.h>
#include<stdlib.h>

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

int getSize (const WBTNode *t) {
  return t == NULL ? 0 : t -> lsize + t -> rsize + 1;
}

int getBias (const WBTNode *t, const int b) {
  if (t == NULL) return 0;
  int l = t -> lsize;
  int r = t -> rsize;
  if (3 * l >= r && l <= 3 * r) {
    return 0;
  }
  return 3 * l < r ? -2 : 2;
}

void update (WBTNode *t) {
  t -> lsize = getSize (t -> left);
  t -> rsize = getSize (t -> right);
}

int isLeftChild (const WBTNode *t) {
  return t != NULL && t -> parent != NULL && t -> parent -> left == t;
}

void concatL (WBTNode *parent, WBTNode *child) {
  if(child != NULL) {
    child -> parent = parent;
  }
  if(parent != NULL) {
    parent -> left = child;
  }
}

void concatR (WBTNode *parent, WBTNode *child) {
  if(child != NULL) {
    child -> parent = parent;
  }
  if(parent != NULL) {
    parent -> right = child;
  }
}

WBTNode* rightRotate (WBTNode *v) {
  WBTNode *u = v -> left;
  concatL (v, u -> right);
  if (isLeftChild (v)) {
    concatL (v -> parent, u);
  } else {
    concatR (v -> parent, u);
  }
  concatR (u, v);
  update (v);
  update (u);
  return u;
}

WBTNode* leftRotate (WBTNode *u) {
  WBTNode *v = u -> right;
  concatR (u, v -> left);
  if (isLeftChild (u)) {
    concatL (u -> parent, v);
  } else {
    concatR (u -> parent, v);
  }
  concatL (v, u);
  update (u);
  update (v);
  return v;
}

WBTNode* balance (WBTNode *t) {
  const short b = getBias (t, 3);
  if (-1 <= b && b <= 1) {
    return t;
  }
  if (b < -1) {
    if (getBias (t -> right, 2) >= 1) {
      rightRotate (t -> right);
    }
    return leftRotate (t);
  } else {
    if(getBias (t -> left, 2) <= -1){
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

int getSetSize (const multiset *set) {
  return getSize (set -> root);
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

WBTNode* getMinRef (multiset *set) {
  if (set -> root == NULL) {
    return NULL;
  }
  WBTNode *now = set -> root;
  while (now -> left != NULL) {
    now = now -> left;
  }
  return now;
}

WBTNode* getAtRef (multiset *set, int k) {
  if (k <= 0 || getSetSize (set) < k) {
    return NULL;
  }
  WBTNode *now = set -> root;
  while (1) {
    int lSize = getSize (now -> left);
    if (k == lSize + 1){
      return now;
    }
    if (k <= lSize) {
      now = now -> left;
    } else {
      k -= lSize + 1;
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
    if(isLeftChild (t)) {
      concatL (t -> parent, NULL);
    } else {
      concatR (t -> parent, NULL);
    }
    set -> root = saveTree (t -> parent);
    free (t);
  } else if (t -> left == NULL) {
    if (isLeftChild (t)) {
      concatL (t -> parent, t -> right);
    } else {
      concatR (t -> parent, t -> right);
    }
    set -> root = saveTree (t -> right);
    free (t);
  } else if (t -> right == NULL) {
    if (isLeftChild (t)) {
      concatL (t -> parent, t -> left);
    } else {
      concatR (t -> parent, t -> left);
    }
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
    if(isLeftChild (t)) {
      concatL (t -> parent, max);
    } else {
      concatR (t -> parent, max);
    }
    set -> root = saveTree (max);
    free (t);
  }
}

void eraseAt (multiset *set, const int k) {
  if (k < 1 || getSize (set -> root) < k) {
    return;
  }
  eraseByRef (set, getAtRef (set, k));
}

typedef WBTNode Ref;

typedef struct nodeVal{
  int x;
  int index;
} node;

int cmp(const void *a,const void *b){
  return *(int *)a-*(int *)b;
}

void run(void){
  int n,k;
  scanf("%d%d",&n,&k);
  multiset *set=newMultiSet(sizeof(node),cmp);
  int i;
  for(i=0;i<k-1;i++){
    int x;
    scanf("%d",&x);
    insert(set,&((node){x,i+1}));
  }
  for(i=k-1;i<n;i++){
    int x;
    scanf("%d",&x);
    insert(set,&((node){x,i+1}));
    Ref *p=getAtRef(set,k);
    printf("%d\n",((node *)p->val)->index);
  }
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:313:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&k);
   ^
./Main.c:318:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&x);
     ^
./Main.c:323:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&x);
     ^