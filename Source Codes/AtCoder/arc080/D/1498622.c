int printf();
int scanf();
void *malloc();
void *realloc();
void free();

int isprime(int x){
  int i;
  if(x<2)return 0;
  if(x==2)return 1;
  if(x-(x/2)*2==0)return 0;
  i=3;
  while(i*i<x+1){
    if(x-(x/i)*i==0)return 0;
    i = i + 2;
  }
  return 1;
}

/* [size, maxlen, v[0], v[1], ...] */
int *vector_init(){
  int *v;
  int n;
  n = 256;
  v = malloc(4 * (2+n));
  *(v+0) = 0; /* v[0] := size */
  *(v+1) = 4; /* v[1] := maxlen */
  return v;
}
int *vector_push_back(int *vector, int value){
  int size;
  int maxlen;
  size = *(vector+0);
  maxlen = *(vector+1);
  if(size == maxlen){
    maxlen = maxlen * 2;
    vector = realloc(vector, 4 * (2+maxlen));
    *(vector+1) = maxlen;
  }
  *(vector+2+size) = value;
  size = size + 1;
  *(vector+0) = size;
  return vector;
}
int *vector_pop_back(int *vector){
  int size;
  size = *(vector+0);
  if(size == 0){
    return vector;
  }else{
    *(vector+0) = size - 1;
    return vector;
  }
}
int *vector_back(int *vector){
  int size;
  size = *(vector+0);
  if(size==0)return vector;
  return vector+1+size;
}

int calc_max_flow(int n, int **cap, int s, int t){
  int flow;
  int i;
  flow = 0;
  while(1){
    int cur;
    int *bef;
    int *visited;
    int *stack;
    bef = malloc(4 * n);
    visited = malloc(4 * n);
    i = 0;
    while(i < n){
      *(bef+i) = -1;
      *(visited+i) = 0;
      i = i + 1;
    }
    stack = vector_init();
    stack = vector_push_back(stack, s);
    *(visited+s) = 1;
    while(!(*(stack+0) == 0)){
      int p;
      p = *vector_back(stack);
      stack = vector_pop_back(stack);
      if(p==t)goto goal;
      i = 0;
      while(i < n){
        if(*(*(cap+p)+i)==1 && !*(visited+i)){
          *(visited+i) = 1;
          *(bef+i) = p;
          stack = vector_push_back(stack, i);
        }
        i = i + 1;
      }
    }
goal:
    free(stack);
    free(visited);
    if(*(bef+t)==-1){
      free(bef);
      return flow;
    }
    flow = flow + 1;
    /* reverse */
    cur = t;
    while(1){
      int nxt;
      nxt = *(bef+cur);
      if(nxt == -1)goto reverse_end;
      *(*(cap+nxt)+cur) = 0;
      *(*(cap+cur)+nxt) = 1;
      cur = nxt;
    }
reverse_end:
    free(bef);
  }
  return flow;
}

int n;
int *x;
int **cap;
int main(){
  int i;
  int j;
  int *b;
  int size;
  int *head;
  int *even;
  int *odd;
  int m;
  int source;
  int sink;
  int evensize;
  int oddsize;
  int *evenhead;
  int *oddhead;
  int flow;
  int ans;

  /* input */
  /* n */
  scanf("%d", &n);
  /* x */
  x = malloc(4 * n);
  i = 0;
  while(i<n){
    scanf("%d", x+i);
    i = i + 1;
  }

  /* convert to b-array */
  b = vector_init();
  i = 0;
  while(i<n){
    int val;
    int *back;
    val = *(x+i);
    back = vector_back(b);
    if((!(back == b)) && (*back == val)){
      *back = val + 1;
    }else{
      b = vector_push_back(b, val);
      b = vector_push_back(b, val + 1);
    }
    i = i + 1;
  }

  /* split into even and odd */
  even = vector_init();
  odd = vector_init();
  size = *(b+0);
  head = b+2;
  i = 0;
  while(i<size){
    int val;
    val = *(head+i);
    if(val-(val/2)*2==0){
      even = vector_push_back(even, val);
    }else{
      odd = vector_push_back(odd, val);
    }
    i = i + 1;
  }

  /* construct graph */
  m = size + 2;
  source = size;
  sink = size + 1;
  evensize = *(even+0);
  oddsize = *(odd+0);
  evenhead = even + 2;
  oddhead = odd + 2;

  cap = malloc(8 * m);

  i = 0;
  while(i < m){
    *(cap+i) = malloc(4 * m);
    i = i + 1;
  }

  i = 0;
  while(i < evensize){
    *(*(cap+source)+i) = 1;
    i = i + 1;
  }

  i = 0;
  while(i < oddsize){
    *(*(cap+evensize+i)+sink) = 1;
    i = i + 1;
  }

  i = 0;
  while(i < evensize){
    j = 0;
    while(j < oddsize){
      int d;
      d = *(evenhead+i) - *(oddhead+j);
      if(d < 0)d = -d;
      if(!(d<3) && isprime(d)){
        *(*(cap+i)+evensize+j) = 1;
      }
      j = j + 1;
    }
    i = i + 1;
  }

  /* flow */
  flow = calc_max_flow(m, cap, source, sink);
  ans = flow + (evensize-flow) + (oddsize-flow);
  evensize = evensize - flow;
  if(evensize - (evensize/2)*2 == 1){
    ans = ans + 1;
  }
  printf("%d\n", ans);
  return 0;
} ./Main.c:1:5: warning: conflicting types for built-in function ‘printf’
 int printf();
     ^
./Main.c:2:5: warning: conflicting types for built-in function ‘scanf’
 int scanf();
     ^