#include <stdio.h>

static int bits_in_char [256] ;           

int SPobitcount (unsigned int n)  {
   int count = 0 ;
   while (n)  {
      count++ ;
      n &= (n - 1) ;
   }
   return count ;
}


void init_bits_in_char() {
  for(int i=0;i<256;++i) {
    bits_in_char[i] = SPobitcount(i);
  }
} 


int bitcount (unsigned int n)  {
  // works only for 32-bit ints

  return bits_in_char [n  & 0xffu]
      +  bits_in_char [(n >>  8 ) & 0xffu]
      +  bits_in_char [(n >> 16) & 0xffu]
      +  bits_in_char [(n >> 24) & 0xffu] ;
}

int isPure(unsigned int x) {
  unsigned int idx = bitcount(x);
  while(idx > 1) {
    //printf("idx - %d, x - %x\n", idx, x);
    if((x & (1 << (idx-1))) == 0) {
      return 0;
    }
    x &= (1 << (idx-1)) - 1;
    idx = bitcount(x);
  }
  return 1;
}

void processCase(int caseNum) {
  int goal;
  unsigned int count = 0;
  scanf("%d",&goal);
  for(int i=1;i<(1<<(goal-1));i+=2) {
    if(isPure(i)) {
      //printf("%x\n",i);
      ++count;
    }
  }
  printf("Case #%d: %u\n",caseNum,(count % 100003));
}

int main() {
  int casesCount;
  init_bits_in_char();
  scanf("%d",&casesCount);
  for(unsigned int i=0;i<casesCount;++i) {
    processCase(i+1);
  }
}
