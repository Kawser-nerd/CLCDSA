#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>
#include <string.h>

void tiskni(char c, int *n, char cd, int *nd) {
	putchar(c);
	(*n)--;

	while ((*nd) >0) {
		putchar(cd);
		(*nd)--;

		if((*n)>0) {
			putchar(c);
			(*n)--;
		} else {
			return;
		}
	}

}


int solve(int i, int Rn, int Yn, int Bn, int On, int Vn, int Gn) {
		int j,D, N;
		int NCR, NCY, NCB;	// main colours count without hybrids
		int minsdif;		// minor colours (without hybrids) minus major colurs(without hybrids)

		char Cmaj, Cmin1, Cmin2, Cdmaj, Cdmin1, Cdmin2;

		int Nmaj, Nmin1, Nmin2, Ndmaj, Ndmin1, Ndmin2;

		NCR = Rn - Gn;
		NCY = Yn - Vn;
		NCB = Bn - On;

		if (NCR >= NCY && NCR >= NCB && Rn>0 ) {
			// R is major
			Cmaj='R';
			Cmin1='Y';
			Cmin2='B';
			Cdmaj='G';
			Cdmin1='V';
			Cdmin2='O';
			Nmaj=Rn;
			Nmin1=Yn;
			Nmin2=Bn;
			Ndmaj=Gn;
			Ndmin1=Vn;
			Ndmin2=On;
		} else {

		if (NCY >= NCR && NCY >= NCB && Yn>0) {
			// Y is major
			Cmaj='Y';
			Cmin1='R';
			Cmin2='B';
			Cdmaj='V';
			Cdmin1='G';
			Cdmin2='O';
			Nmaj=Yn;
			Nmin1=Rn;
			Nmin2=Bn;
			Ndmaj=Vn;
			Ndmin1=Gn;
			Ndmin2=On;

		} else {
			// B is major
					Cmaj='B';
					Cmin1='R';
					Cmin2='Y';
					Cdmaj='O';
					Cdmin1='G';
					Cdmin2='V';
					Nmaj=Bn;
					Nmin1=Rn;
					Nmin2=Yn;
					Ndmaj=On;
					Ndmin1=Gn;
					Ndmin2=Vn;
		}
	}

	minsdif =  ( Nmin1-Ndmin1 + Nmin2-Ndmin2) - (Nmaj-Ndmaj)  ;

	if ( ((Nmin1 + Ndmin1 + Nmin2 + Ndmin2) == 0) && (Nmaj==Ndmaj) ) {
		printf("Case #%i: ", i);
		tiskni(Cmaj, &Nmaj, Cdmaj, &Ndmaj);
		printf("\n");
	} else {

		if( minsdif < 0 || (NCR < 1 && Gn>0) || (NCY <1 && Vn>0) || (NCB <1 && On>0) ) {
			printf("Case #%i: IMPOSSIBLE\n", i);
			return;
		} else {
			printf("Case #%i: ", i);

			while (Nmaj > 0) {
				tiskni(Cmaj, &Nmaj, Cdmaj, &Ndmaj);

				if (Nmin1 > 0) {
					tiskni(Cmin1, &Nmin1, Cdmin1, &Ndmin1);
					if (minsdif > 0) {
						minsdif--;
						tiskni(Cmin2, &Nmin2, Cdmin2, &Ndmin2);
					}
				} else {
					tiskni(Cmin2, &Nmin2, Cdmin2, &Ndmin2);
				}
			}
			printf("\n");
		}
	}

	if ( Nmaj !=0 || Ndmaj!=0 || Nmin1 !=0 || Ndmin1 != 0 || Nmin2!=0 || Ndmin2 !=0 ) {
		printf("Error case: %i\n",i);
	}

}

main(int argc, char ** argv) {
	int T,i,a;
	int Nn, Rn, On, Yn, Gn, Bn, Vn;

	fprintf(stderr,"argumentu: %i\n",argc);
	fflush(stdout);

	if(argc != 2 )	{
		fprintf (stderr,"at least one argument, please\n");
		exit (1);
	}

	FILE *f;
	if ( NULL == (f=fopen(argv[1],"r"))) {
		fprintf(stderr,"cant open file %s \n",argv[1]);
		exit(1);
	}

	fprintf(stderr,"file opened\n");
	fflush(stderr);


	if ( 1 != (a = fscanf(f,"%i\n",&T))) {
		fprintf(stderr,"error reading T, only %i args provided\n",a);
		exit (1);
	}

	for (i=1 ; i<=T; i++ ) {

		if ( 7 != (a = fscanf(f,"%i %i %i %i %i %i %i\n",&Nn, &Rn, &On, &Yn, &Gn, &Bn, &Vn))) {
			fprintf(stderr,"error reading line %i, only %i args provided\n",i, a);
			exit (1);
		}

		solve(i, Rn,  Yn, Bn, On, Vn, Gn);
	}

	fclose(f);
}
