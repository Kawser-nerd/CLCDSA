// Jacek Migdal 2008 Google code jam
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

const int MAX = 1024;

void doIt() {
	int nLettersForKey;
	int nKeys;
	int nLetters;
	scanf( "%d %d %d", &nLettersForKey, &nKeys, &nLetters );

	static int nFrequencies[MAX];
	for( int i = 0 ; i<nLetters ; i++ ) {
		scanf("%d", &nFrequencies[i] );
	}

	sort( nFrequencies, nFrequencies+nLetters, greater<int>() );

	long long result = 0;

	int iLetters = 0;
	int iLevel = 1;
	while( iLetters<nLetters ) {
		if( iLevel>nLettersForKey ) {
			printf( "Impossible\n" );
			return;
		}
		int chunk = min( nKeys, nLetters-iLetters );

		for( int j = 0 ; j<chunk ; j++ ) {
			result += ((long long)iLevel)*nFrequencies[j+iLetters];
		}
		//printf( "%d level, chunk %d, result %lld\n", iLevel, chunk, result );

		iLevel += 1;
		iLetters += chunk;
	}

	printf( "%lld\n", result );
}

int main() {
	int nTests;
	scanf( "%d", &nTests);
	for( int i = 0 ; i<nTests ; i++ ) {
		printf("Case  #%d: ", i+1);
		doIt();
	}
	return 0;
}

