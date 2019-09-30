#include <stdio.h>

unsigned int interval[2000];

int share_prime(int a, int b, int p)
{
	int i,j;
	int faca[20] = {0,}, fai=0;
	int facb[20] = {0,}, fbi=0;

	/* get a factors */
	for (i=2; i <= a; i++) {
		if ((a % i) == 0) {
			if (i >= p)
				faca[fai++] = i;
			a /= i;
			i = 1;
		}
	}

	for (i=2; i <= b; i++) {
		if ((b % i) == 0) {
			if (i>=p)
				facb[fbi++] = i;
			b /= i;
			i = 1;
		}
	}

	for (i=0; i < fai; i++)
		for (j=0; j < fbi; j++)
			if (faca[i] == facb[j]) {
				return 1;
			}
	return 0;
}

int cmp(int *a, int *b)
{
	return *b - *a;
}

int main()
{
	int C,A,B, f, P, i,j, sets, k, e;

	scanf("%d\n", &C);

	for (f=0; f < C; f++) {
		memset(interval, 0, 2000*4);
		scanf("%d %d %d\n", &A, &B, &P);
		
		for (i=A; i <= B; i++)
			interval[i] = i;
		
		//for (k=0; k < 4; k++)
		for (i=A; i <=B; i++)
			for (j=A; j <=B; j++) {
				if (i==j)
					continue;
			
				if (share_prime(i,j,P)) {
					e = interval[i];
					for (k=A; k <=B; k++)
						if (interval[k] == e)
							interval[k] = interval[j];
				}
			}

		qsort(&interval[A], B-A+1, 4, cmp);
		
		/*for (i=A; i <= B; i++)
			printf("%d %d\n", i, interval[i]);*/
		
		sets = 1;
		for (i=A; i < B; i++)
			if (interval[i] != interval[i+1])
				sets++;

		printf("Case #%d: %d\n", f+1, sets);
	}

	return 0;

}

