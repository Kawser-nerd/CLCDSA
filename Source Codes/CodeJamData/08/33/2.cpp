#include<iostream>
#include<string>
#include<vector>
#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;

int A[1024];
int B[500010];
int C[500010];
map<int,int> D;
#define M 1000000007

int IT[20][500010];
// 0->1, i->2^i, 19->2^19=whole

int main( void )
{
	int N;
	cin >> N;
	for( int CC = 0; CC < N; CC ++ ){
		int n, m, X, Y, Z;
		cin >> n >> m >> X >> Y >> Z;
		for( int i = 0; i < m; i ++ )
			cin >> A[i];
		for( int i = 0; i < n; i ++ ){
			B[i] = A[i%m];
			A[i%m] = ((long long)X * A[i%m] + (long long)Y * (i+1)) % Z;
		}
		memcpy( C, B, sizeof(B) );
		sort( C, C + n );
		int T = 1;
		for( int i = 0, bef = -1; i < n; i ++ ){
			if( bef != C[i] ){
				D[C[i]] = T ++;
				bef = C[i];
			}
		}
		for( int i = 0; i < n; i ++ ){
//			printf( "%d %d\n", B[i], D[B[i]] );
			B[i] = D[B[i]];
		}

		memset( IT, 0x00, sizeof(IT) );
		for( int k = 0; k < 20; k ++ )
			IT[k][0] = 1;

		for( int i = 0; i < n; i ++ ){
			int V = B[i];
			long long c = 0;
			for( int k = 0; k < 20; k ++ ){
				if( V & (1<<k) )
					c = (c + IT[k][V & ~((1<<(k+1))-1)]) % M;
			}
			for( int k = 0; k < 20; k ++ ){
				IT[k][V & ~((1<<k)-1)] = (c + IT[k][V & ~((1<<k)-1)]) % M;
			}
		}
		
		
		long long r = 0;
		for( int i = 1; i < n+1; i ++ ){
			r = (r + IT[0][i]) % M;
		}

		printf( "Case #%d: %lld\n", CC + 1, r );
	}
}
