#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>
#include <string.h>

int solve(int i, FILE *f) {
		int j,a,D, N;

		if ( 2 != (a = fscanf(f,"%i %i\n",&D, &N))) {
			fprintf(stderr,"error reading D, N, only %i args provided\n",a);
			exit (1);
		}

		double maxTime=0;
		double time;
		int Ki, Si;

		for (j=0 ; j<N; j++)
		{
			if ( 2 != (a = fscanf(f,"%i %i\n",&Ki, &Si))) {
				fprintf(stderr,"error reading Ki, Si, only %i args provided\n",a);
				exit (1);
			}

			time = ((double)(D - Ki)) / ((double)Si);
			//printf("Cas kone %i je: %G\n",j,time);

			if (time >= maxTime) {
				maxTime = time;
			}
		}

		printf("Case #%i: %10.10G\n", i, D/maxTime);
}

main(int argc, char ** argv) {
	int T,i,a;

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
		solve(i,f);
	}

	fclose(f);
}
