#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#include "gmp.h"


#define bst( AA, BB_l, BB_u, CC_c )    int64_t lower##AA = BB_l; int64_t upper##AA = BB_u; int64_t AA; while ( lower##AA < upper##AA ) { AA = lower##AA + ((upper##AA - lower##AA)/2); if ( ! (CC_c) ) { lower##AA = AA + 1; } else { upper##AA = AA; } } AA = upper##AA;



int main( int argc, char ** argv, char ** envp ) {

int File = open(argv[1], O_RDONLY);
size_t Size = lseek(File, 0, SEEK_END);
char * Mem = malloc(Size);
lseek(File, 0, SEEK_SET);
read(File, Mem, Size);
close(File);
unsigned int q = 0;
while ( q < Size ) {
	if ( Mem[q] == 0x0a ) { Mem[q] = 0x00; }
	if ( Mem[q] == 0x20 ) { Mem[q] = 0x00; }
	q++;
}
unsigned int Cases = atoi(Mem);
q = strlen(Mem) + 1;
fprintf(stderr, "Cases: %u\n", Cases);
unsigned int Case_T = 0;


typedef struct {
	char s[128];
} st;

int n = 0;

st * ans = malloc(sizeof(st) * 150000 );
bzero(ans, sizeof(st) * 150000 );

st * anssq = malloc(sizeof(st) * 150000 );
bzero(anssq, sizeof(st) * 150000 );

int ya, yb, yc;


mpz_t tempmpz;

int d;
for ( d = 1; d < 51; d ++ ) {
	if ( d == 1 ) {
		ans[n].s[0] = '1';
		ans[n].s[1] = 0x00;
		n ++;

		ans[n].s[0] = '2';
		ans[n].s[1] = 0x00;
		n ++;

		ans[n].s[0] = '3';
		ans[n].s[1] = 0x00;
		n ++;
	} else {
		ya = d/2;
		while ( ya > 0 ) {
			yb = d/2;
			while ( yb >= ya ) {
				if ( (yb == ya) && (yb < d/2) ) { goto yb_go; }
				yc = d/2;
				while ( yc >= yb ) {
					if ( (yc == yb) && (yc < d/2) ) { goto yc_go; }


					memset( ans[n].s, '0', d );
					ans[n].s[d] = 0x00;
					ans[n].s[127] = 0x0a;
					ans[n].s[0]   = '1';
					ans[n].s[d-1] = '1';

					if ( ya < (d/2) ) {
						ans[n].s[        ya] = '1';
						ans[n].s[(d-1) - ya] = '1';
					}

					if ( yb < (d/2) ) {
						ans[n].s[        yb] = '1';
						ans[n].s[(d-1) - yb] = '1';
					}

					if ( yc < (d/2) ) {
						ans[n].s[        yc] = '1';
						ans[n].s[(d-1) - yc] = '1';
					}

					n ++;

					if ( d % 2 ) {
						memcpy( ans[n].s, ans[n-1].s, 128 );
						ans[n].s[d/2] = '1';
						n ++;
			
						if ( yb == (d/2) ) {
							memcpy( ans[n].s, ans[n-1].s, 128 );
							ans[n].s[d/2] = '2';
							n ++;
						}
					}


					yc_go :
					yc --;
				}

				yb_go :
				yb --;
			}
			ya --;
		}

		memset( ans[n].s, '0', d );
		ans[n].s[d] = 0x00;
		ans[n].s[127] = 0x0a;
		ans[n].s[0]   = '2';
		ans[n].s[d-1] = '2';
		n ++;

		if ( d % 2 ) {
			memcpy( ans[n].s, ans[n-1].s, 128 );
			ans[n].s[d/2] = '1';
			n ++;
		}

	}
}

//fprintf(stderr,"%d", n);

//write(1, ans, n * sizeof(st) );

mpz_init( tempmpz );

int x = 0;
while ( x < n ) {
	mpz_init_set_str( tempmpz, ans[x].s, 10 );
	mpz_mul( tempmpz, tempmpz, tempmpz );
	mpz_get_str( anssq[x].s, 10, tempmpz );
	anssq[x].s[127] = 0x0a;
	x ++;
}

//write(1, anssq, n * sizeof(st) );




char * A;
char * B;
while ( Case_T < Cases ) {
	A   = Mem + q; q += ( strlen(Mem + q) + 1 );
	B   = Mem + q; q += ( strlen(Mem + q) + 1 );

	bst( Abs, 0, n, (strlen(A) < strlen(anssq[Abs].s)) || ( (strlen(A) == strlen(anssq[Abs].s)) && (strcmp( A, anssq[Abs].s) <= 0) ) );
	bst( Bbs, 0, n, (strlen(B) < strlen(anssq[Bbs].s)) || ( (strlen(B) == strlen(anssq[Bbs].s)) && (strcmp( B, anssq[Bbs].s) <  0) ) );


	printf("Case #%u: %lld\n", Case_T + 1, Bbs - Abs );

	Case_T ++;
}



return 0;
}
