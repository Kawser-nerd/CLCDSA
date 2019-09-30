#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define A 50

int a[A];
int n[100];
int size;
int cdigit=1;
int mbase=2;
long long value=0;

int main() {
	int i;
	const char infile[] = "input.txt";
	const char outfile[] = "output.txt";

	int testcases;
	int testcase;

	FILE *inf;
	FILE *outf;

	inf = fopen ( infile, "r" ); if ( inf == NULL ) { perror(infile); return 1; }
	outf = fopen ( outfile, "w" ); if ( outf == NULL ) { perror(outfile); return 1; }

	fscanf(inf, "%d", &testcases);

	for (testcase=0; testcase<testcases; testcase++) {
		char c;
		size=0;
		value=0;
		for (i=0; i<A; i++)
			a[i]=-1;
		int cdigit=1;
		int mbase=2;
		int ze = 0;
		int zu = 0;

		fscanf(inf, "%c", &c);
		while (!(((c>='a')&&(c<='z'))||((c>='0')&&(c<='9'))))
			fscanf(inf, "%c", &c);

		while (((c>='a')&&(c<='z'))||((c>='0')&&(c<='9'))) {

			//int v = (int) c;
			//printf("%d",v);

			if (((c>='a')&&(c<='z')))
				c=c-'a';
			else
				c=c-'0'+'z'-'a'+1;

			if (a[c]==-1) {
				if (ze&&(!zu)) {
					a[c] = 0;
					n[size] = 0;
					zu=1;
				} else {
					a[c] = cdigit;
					n[size] = cdigit++;
				}
			} else {
				n[size] = a[c];
			}

			if (n[size]+1>=mbase)
				mbase = n[size]+1;

			size++;
			fscanf(inf, "%c", &c);

			ze=1;
		}

		value = 0;
		// calc
		for (i=0; i<size; i++) {
			;//fprintf(outf, "%c", '0'+n[i]);
		}
		for (i=0; i<size; i++) {
			value = (long long)mbase*(long long)value + (long long)n[i];
			//fprintf(outf, "%c", '0'+n[i]);
			//fprintf(outf, "  %d  ", value);
		}
		fprintf(outf, "Case #%d: %lld\n", testcase+1, value);
	}

	return 0;
}
