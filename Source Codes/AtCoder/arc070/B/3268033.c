#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef unsigned long long int uint64;

typedef struct bitSetBy64bit{
  uint64 *a;
  int len;
  int n;
} bitSet;

const int bitSet_numOfBit=64;

bitSet* newBitSet(int n){
  bitSet *res=(bitSet *)malloc(sizeof(bitSet));
  res->a=(uint64 *)calloc((n+bitSet_numOfBit-1)/bitSet_numOfBit,sizeof(uint64));
  res->len=(n+bitSet_numOfBit-1)/bitSet_numOfBit;
  res->n=n;
  return res;
}

void freeBitSet(bitSet *b){
  free(b->a);
  free(b);
  return;
}

inline void fix(bitSet *b){
  if(b->n%bitSet_numOfBit!=0) b->a[b->len-1]&=(((uint64)1)<<(b->n%bitSet_numOfBit))-1;
}

void setBitSet(bitSet *b){
  const uint64 t=~((uint64)0);
  int i;
  for(i=0;i<b->len;i++) b->a[i]=t;
  fix(b);
  return;
}

void clearBitSet(bitSet *b){
  const uint64 t=0;
  int i;
  for(i=0;i<b->len;i++) b->a[i]=t;
  return;
}

void flipBitSet(bitSet *b){
  int i;
  for(i=0;i<b->len;i++) b->a[i]=~b->a[i];
  fix(b);
  return;
}

int getAtBitSet(bitSet *b,int index){
  assert(0<=index && index<b->n);
  return (b->a[index/bitSet_numOfBit]>>(index%bitSet_numOfBit))&0x01;
}

void setAtBitSet(bitSet *b,int index){
  assert(0<=index && index<b->n);
  uint64 t=b->a[index/bitSet_numOfBit];
  b->a[index/bitSet_numOfBit]=t|(((uint64)1)<<(index%bitSet_numOfBit));
  return;
}

void clearAtBitSet(bitSet *b,int index){
  assert(0<=index && index<b->n);
  uint64 t=b->a[index/bitSet_numOfBit];
  b->a[index/bitSet_numOfBit]=t&(~(((uint64)1)<<(index%bitSet_numOfBit)));
  return;
}

void flipAtBitSet(bitSet *b,int index){
  assert(0<=index && index<b->n);
  uint64 t=b->a[index/bitSet_numOfBit];
  b->a[index/bitSet_numOfBit]=t^(((uint64)1)<<(index%bitSet_numOfBit));
  return;
}

void assignBitSet(bitSet *x,const bitSet *a){
  int i;
  for(i=0;i<x->len;i++) x->a[i]=a->a[i];
  fix(x);
}

void orBitSet(bitSet *c,const bitSet *a,const bitSet *b){
  int i;
  for(i=0;i<c->len;i++) c->a[i]=a->a[i]|b->a[i];
  fix(c);
  return;
}

void andBitSet(bitSet *c,const bitSet *a,const bitSet *b){
  int i;
  for(i=0;i<c->len;i++) c->a[i]=a->a[i]&b->a[i];
  fix(c);
  return;
}

void xorBitSet(bitSet *c,const bitSet *a,const bitSet *b){
  int i;
  for(i=0;i<c->len;i++) c->a[i]=a->a[i]^b->a[i];
  fix(c);
  return;
}

//x!=a
void leftShiftBitSet(bitSet *x,const bitSet *a,const int c){
  assert(c>=0);
  clearBitSet(x);
  int p=c/bitSet_numOfBit;
  int q=c%bitSet_numOfBit;
  if(q==0){
    int i;
    for(i=0;i<x->len-p && i<a->len;i++){
      x->a[i+p]=a->a[i];
    }
  } else {
    int i;
    for(i=0;i<x->len-p-1 && i<a->len;i++){
      uint64 t=a->a[i];
      x->a[i+p]|=t<<q;
      x->a[i+p+1]|=t>>(bitSet_numOfBit-q);
    }
    if(i<a->len && i+p<x->len) x->a[i+p]|=a->a[i]<<q;
  }
  fix(x);
  return;
}

int cmp(const void *a,const void *b){
  return *(int *)a-*(int *)b;
}

void run(void){
  int n,k;
  scanf("%u%u",&n,&k);
  int *a=(int *)malloc(sizeof(int)*n);
  int i;
  for(i=0;i<n;i++) scanf("%d",a+i);
  qsort(a,n,sizeof(int),cmp);
  bitSet *now =newBitSet(k);
  bitSet *next=newBitSet(k);
  int l=-1;
  int r=n;
  while(r-l>1){
    int m=(l+r)/2;
    clearBitSet(now);
    setAtBitSet(now,0);
    for(i=0;i<n;i++){
      if(i==m) continue;
      const int aa=a[i];
      leftShiftBitSet(next,now,aa);
      orBitSet(next,next,now);
      bitSet *swap=now;
      now=next;
      next=swap;
    }
    for(i=k-1;getAtBitSet(now,i)==0;i--);
    if(a[m]+i>=k){
      r=m;
    } else {
      l=m;
    }
  }
  printf("%d\n",l+1);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:138:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%u%u",&n,&k);
   ^
./Main.c:141:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%d",a+i);
                    ^