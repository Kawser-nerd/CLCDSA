#include <stdio.h>

#define MAX_N 150
#define MAX_L 40


int main(void) {
  unsigned casen=1,t;

  // get num cases
  scanf("%u\n",&t);

  while(t--) { 
	unsigned N, L;
	unsigned nb;
	char o[MAX_N][MAX_L+1];
	unsigned long ou[MAX_N];
	char t[MAX_N][MAX_L+1];
	unsigned long tu[MAX_N];\
	unsigned long tou;
	unsigned long c[MAX_N][2];
	unsigned i, j, k;
	unsigned found_one;
	unsigned m;

	found_one = 0;
	nb = 1000;
	
	// inputs
	scanf("%u %u\n", &N, &L);
	for (i=0; i< N; i++) {
	  scanf("%s", &o[i][0]);
	  ou[i] = 0L;
	  for (j=0; j<L; j++) {
		ou[i] |= (o[i][j] == '1') ? 1L << j : 0;
	  }
	}
	for (i=0; i< N; i++) {
	  scanf("%s", &t[i][0]);
	  tu[i] = 0L;
	  for (j=0; j<L; j++) {
		tu[i] |= (t[i][j] == '1') ? 1L << j : 0;
	  }
	}

	// if we cannot find a combination with any target satisfying ou[0] then it is impossible
	for (i=0; i< N; i++) {
	  tou = ou[0] ^ tu[i]; // find bits to flip 

	  // note: we could check here to start with the ones which having the min number of flip
	  // but for now brute force
	  
	  // apply the bit flip to candidates
	  for (j=0; j<N; j++) {
		c[j][0] = ou[j] ^ tou;
		c[j][1] = 0;  // mark as unused
	  }
	  
	  // check whether there is a possible permutation matching
	  m=0;
	  for (j=0; j<N; j++) {
		for (k=0; k<N; k++) {
		  if (!c[k][1] && (tu[j] == c[k][0])) {
			m++;
			c[k][1] = 1;
			break;
		  }
		}
	  }
	  // one full match
	  if (m == N) {
		found_one = 1;
		// how many bits needs to be flipped?
		unsigned count=0;
		for (j=0; j<L; j++) {
		  if (tou & (1L << j)) count++;
		}
		//printf("found %u bit flips\n", count);
		
		if (count < nb) nb = count;
		if (nb == 0) break; // optimization in case of no fliip, there is no better minimum
	  }

	  /* printf("0x%lx ", ou[i]); */
	}

	printf("Case #%u: ", casen++);
	if (!found_one) {
	  printf("NOT POSSIBLE\n");
	} else {
	  printf("%u\n", nb);
	}

  }

  return 0;
}
