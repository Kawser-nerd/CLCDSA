#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N, T, NA, NB;
int answerA, answerB;

char routesFromA[100][10];
char routesFromB[100][10];

char routesToA[100][10];
char routesToB[100][10];

typedef struct Edge_
{
	int from;
	int to;
} Edge;


Edge ab[105];
Edge ba[105];

int edgeABUsed[105];
int edgeBAUsed[105];

int _cmp( const void* aa, const void* bb )
{
	const Edge* a = (Edge*)aa;
	const Edge* b = (Edge*)bb;

	if ( a->from < b->from )
		return -1;
	if ( a->from > b->from )
		return 1;

	if ( a->to < b->to )
		return -1;

	if ( a->to > b->to )
		return 1;

	return 0;
}

int getMinutes( char* time )
{
	int h, m;

	sscanf( time, "%d:%d", &h, &m );

	return h*60 + m;
}

int findEdgeStartingAfter( Edge* edges, int* usedEdges, int edgesCount, int time )
{
	for( int i=1; i<=edgesCount; i++ )
	{
		if ( ( usedEdges[i] == 0 ) && ( edges[i].from >= time ) )
			return i;
	}

	return -1;
}

int findAnswer()
{
	memset( edgeABUsed, 0, sizeof( edgeABUsed ) );
	memset( edgeBAUsed, 0, sizeof( edgeBAUsed ) );

	qsort( &ab[1], NA, sizeof(Edge), _cmp );
	qsort( &ba[1], NB, sizeof(Edge), _cmp );

	int currentTime = -1;

	int eAB = -1;
	int eBA = -1;

	answerA = 0;
	answerB = 0;


	int ABUsed = 0;
	int BAUsed = 0;


	while( (ABUsed < NA) || (BAUsed < NB) )
	{
		int eFromA = findEdgeStartingAfter( ab, edgeABUsed, NA, 0 );
		int eFromB = findEdgeStartingAfter( ba, edgeBAUsed, NB, 0 );

		int startFromA = 0;
		int startFromB = 0;

		if ( ( eFromA > 0 ) && ( eFromB > 0 ) )
		{
			if( ab[eFromA].from < ba[eFromB].from )
				startFromA = 1;
			else
				startFromB = 1;
		}
		else if ( eFromA == -1 )
		{
			startFromB = 1;
		}
		else if ( eFromB == -1 )
		{
			startFromA = 1;
		}

		if ( startFromA )
		{
			answerA++;
			currentTime = -1;

			while( 1 == 1 )
			{
				eAB = findEdgeStartingAfter( ab, edgeABUsed, NA, currentTime );
				if ( eAB == -1 )
					break;
				currentTime = ab[eAB].to;
				edgeABUsed[ eAB ] = 1;
				ABUsed++;

				eBA = findEdgeStartingAfter( ba, edgeBAUsed, NB, currentTime );
				if ( eBA == -1 )
					break;
				currentTime = ba[eBA].to;
				edgeBAUsed[ eBA ] = 1;
				BAUsed++;
			}
		}
		else
		{
			answerB++;
			currentTime = -1;

			while( 1 == 1 )
			{
				eBA = findEdgeStartingAfter( ba, edgeBAUsed, NB, currentTime );
				if ( eBA == -1 )
					break;
				currentTime = ba[eBA].to;
				edgeBAUsed[ eBA ] = 1;
				BAUsed++;

				eAB = findEdgeStartingAfter( ab, edgeABUsed, NA, currentTime );
				if ( eAB == -1 )
					break;
				currentTime = ab[eAB].to;
				edgeABUsed[ eAB ] = 1;
				ABUsed++;
			}
		}

	}

	return 0;
}

int main(int argc,char *argv[])
{
	FILE* fin = fopen( "input.txt", "r" );
	FILE* fout = fopen( "output.txt", "w" );

	fscanf( fin, "%d", &N );

	char time1[ 10 ];
	char time2[ 10 ];

	for( int i=1; i<=N; i++ )
	{

		fscanf( fin, "%d", &T);
		fscanf( fin, "%d %d", &NA, &NB );

		for( int k=1; k<=NA; k++ )
		{
			fscanf( fin, "%s %s", time1, time2 );
			ab[k].from = getMinutes( time1 );
			ab[k].to = getMinutes( time2 ) + T;
		}

		for( int p=1; p<=NB; p++ )
		{
			fscanf( fin, "%s %s", time1, time2 );
			ba[p].from = getMinutes( time1 );
			ba[p].to = getMinutes( time2 ) + T;
		}

		printf( "Case #%d:...\n", i );
		findAnswer();

		fprintf( fout, "Case #%d: %d %d\n", i, answerA, answerB );
	}

	fclose( fin );
	fclose( fout );

	return 0;
}
