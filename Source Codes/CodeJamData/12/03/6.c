#include <stdio.h>
#include <assert.h>

static inline
unsigned num_digits(unsigned n) {
  unsigned s=1;
  while(n>=10) {s++, n/=10;}
  return s;
}



int main(void) {
  unsigned number_of_test_cases, test_case;

  if(scanf("%u", &number_of_test_cases)!=1) {
    fprintf(stderr, "error reading test_cases\n");
    return 1;
  }
  for( test_case=1; test_case<=number_of_test_cases; test_case++){
    unsigned sum=0, A, B, cache[8], pow10, rank;
    int i,j,k;
    if(scanf("%d %d", &A, &B)!=2) {
      fprintf(stderr, "error reading A,B\n");
      return 1;
    }
      
    assert(num_digits(A)==num_digits(B));
    if(A<10) A=10;
    for(pow10=1; pow10<A; pow10 *= 10);
    assert(pow10>=A);
    if(pow10>A) pow10 /= 10;
    assert( pow10<=A);
    assert(10*pow10 > A);
    rank=num_digits(A)-1;
    while(A<=B) {
      unsigned num=A;
      for(j=i=0; i<rank; i++) {
	unsigned d=num%10;
	num = (num-d)/10 + pow10*d;
	if(d!=0 && num<=B && num>A) {
	  for(k=0; k<j; k++) {
	    if(num==cache[k]) break;
	  }
	  if(k==j) { 
	    sum++;
	    cache[j++]=num;
	  }
	}
      }
      A++;
    }
    printf("Case #%u: %u\n", test_case, sum);
  }
  return 0;
}
  
