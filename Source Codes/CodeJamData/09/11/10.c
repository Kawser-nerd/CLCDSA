// GCJ 1A 2009, Problem A
// Lucas Garron

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 512
#define MAX_NUM_BASES 16
#define MAX_SQSUM_ITERATIONS 32

int digsqsum(int a, int base)
{
	int s=1, t, dig, out=0;;

	while(s<=a)
	{
		t=s*base;
		dig=(a%t)/s;
		out+=dig*dig;
		s=t;
	}

  return out;
}

int not_in(int log[], int l_size, int memq)
{
	int i=0;
	for(i=0; i<l_size; i++)
	{
		if(log[i]==memq)
			return 0;
	}
	return 1;
}

int happyq_single(int a, int base)
{
	int log[MAX_SQSUM_ITERATIONS], l=0, n=a;
	while(not_in(log, l, n))
	{
		log[l] = n;
		++l;
		n=digsqsum(n, base);
		//printf("__%d\n", n);
	}
	return (n==1);
}

int happyq(int a, int bases[], int num_bases)
{
	int i=0;
	for(i=0; i<num_bases; ++i)
	{
		if(!happyq_single(a, bases[i]))
			return 0;
	}
	return 1;
}

int earliest_happy(int bases[], int num_bases)
{
	int i=2;
	while(!happyq(i, bases, num_bases))
		++i;
	return i;
}

int main(int argc, char** argv)
{
  printf("\nBeginning 09-1A-A: %s\n", argv[1]);

  FILE *file;
  FILE *fileout;
  int T, X, num_bases, bases[MAX_NUM_BASES];
  char buffer[MAX_LINE_LENGTH];

  file = fopen(argv[1], "r");
  fileout = fopen(argv[2], "w");
  if (file == NULL || fileout == NULL) {
    printf("Couldn't open file %s or %s\n", argv[1], argv[2]);
    return -1;
  }

  fscanf(file, "%d\n", &T);
  printf("%d cases.\n", T);
  
  for(X = 0; X < T; ++X)
  {
    fgets(buffer, MAX_LINE_LENGTH, file);
		
		num_bases = sscanf(buffer, "%d %d %d %d %d %d %d %d %d", &bases[0], &bases[1], &bases[2], &bases[3], &bases[4], &bases[5], &bases[6], &bases[7], &bases[8]);
		printf("Case #%d: %d | %s", X+1, earliest_happy(bases, num_bases), buffer);
		fprintf(fileout, "Case #%d: %d\n", X+1, earliest_happy(bases, num_bases));
  }

	printf("\n");
  return 0;
}