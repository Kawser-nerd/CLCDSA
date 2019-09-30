#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N;

char engines[105][105];
int eCount;

char queries[1005][105];
int qCount;

#define MIN 99999

int findAnswer()
{
	int d[1005][105];

	memset( d, 0, sizeof(d) );

	for( int qq=1; qq<=qCount; qq++ )
		for( int ee=1; ee<=eCount; ee++ )
			if ( 0 == strcmp( queries[qq], engines[ee] ) )
				d[qq][ee] = MIN;


	for( int q=2; q<=qCount; q++ )
	{
		for( int e=1; e<=eCount; e++ )
		{
			if ( d[q][e] != MIN )
			{
				d[q][e] = d[q-1][e];

				for( int c=1; c<=eCount; c++ )
					if ( c != e )
						d[q][e] = min( d[q][e], d[q-1][c] + 1 );
			}
		}
	}

	int m = MIN;
	for( int e=1; e<=eCount; e++ )
		m = min( m, d[qCount][e] );

	return m;
}

int main(int argc,char *argv[])
{
	FILE* fin = fopen( "input.txt", "r" );
	FILE* fout = fopen( "output.txt", "w" );

	fscanf( fin, "%d", &N );

	for( int i=1; i<=N; i++ )
	{
		fscanf( fin, "%d", &eCount );
		fgets( engines[0], 101, fin );

		for( int j=1; j<=eCount; j++ )
			fgets( engines[j], 101, fin );

		fscanf( fin, "%d", &qCount );
		fgets( queries[0], 101, fin );

		for( int j=1; j<=qCount; j++ )
			fgets( queries[j], 101, fin  );

		int answer = findAnswer();
		fprintf( fout, "Case #%d: %d\n", i, answer );
	}

	fclose( fin );
	fclose( fout );

	return 0;
}
