#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

/* */ #include "gmp.h"

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


int N;
int X;
int Y;

double ans;


mpq_t tmpz;
mpq_t accmpz;

mpq_t ampz;
mpq_t bmpz;

mpq_init( accmpz );
mpq_init( tmpz );

mpq_init( ampz );
mpq_init( bmpz );

mpz_t num;
mpz_t den;

mpz_init(num);
mpz_init(den);

while ( Case_T < Cases ) {
/* --------------------- */
	N   = atoi(Mem + q ); q += ( strlen(Mem + q) + 1 );
	X   = atoi(Mem + q ); q += ( strlen(Mem + q) + 1 );
	Y   = atoi(Mem + q ); q += ( strlen(Mem + q) + 1 );

	int mx;
	mx = X;
	if (X < 0) { mx = 0-X; }

	int L = ((mx + Y) / 2) + 1;

	int z = (L * ((2*L)-1));


//	fprintf(stderr, "\n %d (%d,%d): Layer %d\n", N, X, Y, L);


	if ( z <= N ) {
		ans = 1.0;
//	fprintf(stderr, "jump yes\n");
		goto End;
	}

	L --;
	z = (L * ((2*L)-1));
	L ++;
	if ( z >= N ) {
//	fprintf(stderr, "jump no\n");
		ans = 0.0;
		goto End;
	}

	int nres = N - z;

	int target = Y + 1;

	int max = ((2*L) - 2);

if ( nres > (max*2) ) {
	fprintf(stderr, ">>case #%u: err 1, %d, %d\n", Case_T + 1, nres, max );
}

if ( target > max ) {
	if ( target != (max + 1) ) {
		fprintf(stderr, ">>case #%u: err 2, %d, %d\n", Case_T + 1, target, max );
	}
//	fprintf(stderr, "jump no top\n");
	ans = 0.0;
	goto End;
}


	//2825

	//accmpz = 0;
	mpq_set_si( accmpz, 0,1 );

//fprintf(stderr, "nres, max: %d, %d\n", nres, max);


	int x = 0;
	while ( x < (nres+1) ) {
		// tmpz = binomial( nres, x );
		mpz_bin_uiui( num, nres, x );
		mpz_ui_pow_ui( den, 2, nres);

		mpq_set_z( ampz, num );
		mpq_set_z( bmpz, den );

		mpq_div( tmpz, ampz, bmpz );

		int y = x;
		if ( (nres - x) > max ) {
			y += ((nres-x) - max);
		}
		if ( y >= target ) {
			// accmpz += tmpz;
			mpq_add( accmpz, accmpz, tmpz);
		}
		x ++;
	}

//	fprintf(stderr, "calc\n");
	ans = mpq_get_d( accmpz );


	End:

	printf("Case #%u: %lf\n", Case_T + 1, ans );

	Case_T ++;
/* --------------------- */
}

return 0;
}
